import sigrokdecode as srd
import math

class RadioState:
  txPower = 0
  txByteCount = 0
  rxByteCount = 0
  rxBytesRead = 0
  rxSS = 0
  rxES = 0
  address = [0x00] * 3
  isRead = False
  peerAddress = [0x00] * 3
  txBuffer = {}
  rxBuffer = {}

  ss = 0
  es = 0

  lastCommandSample = 0

  register = -1

  resetPhase = 0

class Decoder(srd.Decoder):
  api_version = 2
  id = 'em9201'
  name = 'EM9201 SPI'
  longname = 'EM9201 SPI'
  desc = 'Commands and data sent to EM9201 RF module used in Hallmark wireless ornaments'
  license = 'gplv2+'
  inputs = ['spi']
  outputs = ['em9201-tx', 'em9201-rx', 'em9201-cfg']
  channels = ()
  optional_channels = ()
  annotations = (
    ('tx', 'Transmitted data'),
    ('rx', 'Received data'),
    ('cfg', 'Config changes'),
    ('cmd', 'Emulation Commands'),
  )

  def start(self):
    self.radioState = RadioState()
    self.out_ann = self.register(srd.OUTPUT_ANN)

  def dumpReceive(self):
    rxBytes = ""

    for i in range(0, self.radioState.rxByteCount):
      dat = self.radioState.rxBuffer.get(i)
      if dat is None:
        rxBytes += "XX "
      else:
        rxBytes += "{:02X} ".format(dat)

    self.put(self.radioState.rxSS, self.radioState.rxES, self.out_ann, [1, ["RX: {0}".format(rxBytes), rxBytes]])

  def dumpTransmit(self, ss, es):
    txBytes = ""

    for i in range(0, self.radioState.txByteCount):
      dat = self.radioState.txBuffer.get(i)
      if dat is None:
        txBytes += "XX "
      else:
        txBytes += "{:02X} ".format(dat)

    self.put(ss, es, self.out_ann, [0, ["TX {} bytes: {}".format(self.radioState.txByteCount, txBytes), txBytes]])

  def decode(self, ss, es, data):
    ptype, mosi, miso = data

    if ptype != 'DATA':
      return

    if self.radioState.register == -1:
      # New command starting
      self.radioState.ss = ss
      self.radioState.register = mosi & 0x7F
      self.radioState.isRead = mosi & 0x80
    else:
      desc = "Unknown"

      if self.radioState.register == 0x1A:
        if self.radioState.resetPhase == 1 and mosi == 0x5E:
          self.put(self.radioState.ss, es, self.out_ann, [2,['Reset', 'RST', 'R']])
          self.radioState.es = es
          self.radioState.resetPhase = 0

          desc = "RST Phase 2"
        elif mosi == 0xB3:
          self.radioState.resetPhase = 1
          desc = "RST Phase 1"
        else:
          self.radioState.resetPhase = 0
      elif self.radioState.register == 0x00:
        self.put(self.radioState.ss, es, self.out_ann, [2,['Clear Status 0', 'CS0', 'C']])
        desc = "CS0"
      elif self.radioState.register == 0x01:
        self.put(self.radioState.ss, es, self.out_ann, [2,['Clear Status 1', 'CS1', 'C']])
        desc = "CS1"
      elif self.radioState.register == 0x02:
        self.put(self.radioState.ss, es, self.out_ann, [2,['Int1Msk {:02X}'.format(mosi), 'Int1Msk']])
        desc = "Int1Msk"
      elif self.radioState.register == 0x03:
        self.put(self.radioState.ss, es, self.out_ann, [2,['Int2Msk {:02X}'.format(mosi), 'Int2Msk']])
        desc = "Int2Msk"
      elif self.radioState.register == 0x04:

        if(mosi == 0x07):
          self.dumpTransmit(ss, es)
          desc = "TX"
        elif mosi == 0x02:
          self.put(self.radioState.ss, es, self.out_ann, [2,['RX Enabled'.format(mosi), 'RX']])  
          self.radioState.rxByteCount = 0
          self.radioState.rxBytesRead = 0
          self.radioState.rxBuffer = {}
          desc = "RX Enable"
        elif mosi == 0x00:
          self.put(self.radioState.ss, es, self.out_ann, [2,['Radio Stop', 'RDO-OFF']])  
          if self.radioState.rxBytesRead > 0:
            self.dumpReceive()

          self.radioState.rxByteCount = 0
          self.radioState.rxBytesRead = 0
          self.radioState.rxBuffer = {}
          desc = "RDO-OFF"
      elif self.radioState.register == 0x06:
        self.put(self.radioState.ss, es, self.out_ann, [2,['Power Config {:02X}'.format(mosi), 'PWR-CFG']])

        desc = "PWR-CFG"
      elif self.radioState.register == 0x06:
        self.put(self.radioState.ss, es, self.out_ann, [2,['RF Config {:02X}'.format(mosi), 'RFC']])

        if mosi | 0x40 == 0x40:
          self.put(self.radioState.ss, es, self.out_ann, [2,['PLL Autoconfig Start', 'PLL']])
          desc = "PLL Autoconfig Start"
        else:
          desc = "RF Config"

        power = mosi & 0x07
        self.put(self.radioState.ss, es, self.out_ann, [2,['Power {0}'.format(power), 'PWR']])
      elif self.radioState.register == 0x07:
        self.put(self.radioState.ss, es, self.out_ann, [2,['RF Channel {}'.format(mosi), 'CHAN']])

        desc = "Channel Selection"
      elif self.radioState.register == 0x0B:
        if mosi | 0x10 == 0x10:
          self.put(self.radioState.ss, es, self.out_ann, [2,['ACK Enabled', 'ACK-ON']])
        else:
          self.put(self.radioState.ss, es, self.out_ann, [2,['ACK Disabled', 'ACK-OFF']])

        power = mosi & 0x07
        self.put(self.radioState.ss, es, self.out_ann, [2,['Power {0}'.format(power), 'PWR']])
        desc = "RC Ack Config"
      elif 0x0E <= self.radioState.register <= 0x10:
        offset = self.radioState.register - 0x0E
        self.radioState.address[offset] = mosi
        addr = ""

        for i in range(0, 3):
            addr += "{:02X} ".format(self.radioState.address[i])

        self.put(self.radioState.ss, es, self.out_ann, [2,['Address: {}'.format(addr), 'ADDR']])

        desc = "ADDR"

      elif 0x11 <= self.radioState.register <= 0x13:
        offset = self.radioState.register - 0x11
        self.radioState.peerAddress[offset] = mosi
        addr = ""

        for i in range(0, 3):
            addr += "{:02X} ".format(self.radioState.peerAddress[i])

        self.put(self.radioState.ss, es, self.out_ann, [2,['Peer Address: {}'.format(addr), 'PEER']])

        desc = "PEER"

      elif self.radioState.register == 0x14:
        self.radioState.txByteCount = mosi & 0x0F
        self.put(self.radioState.ss, es, self.out_ann, [2,['Tx Size set {0}'.format(self.radioState.txByteCount), 'TX Len {0}'.format(self.radioState.txByteCount)]])

        desc = "TX Length"
      elif self.radioState.register == 0x16:
        self.put(self.radioState.ss, es, self.out_ann, [2,['FIFO Config {:02X}'.format(mosi), 'FIFO']])

        desc = "FIFO CTRL"

      elif 0x40 <= self.radioState.register <= 0x5F:
        offset = self.radioState.register - 0x40
        self.radioState.txBuffer[offset] = mosi

        desc = "TX Buffer"
      elif 0x60 <= self.radioState.register <= 0x7F:
        desc = "RX Buffer"

        offset = self.radioState.register - 0x60
        if self.radioState.isRead:
          incrementCounter = True
          # Data appears to be read 60 64 65 66 *60* 61 62 63
          self.radioState.rxBuffer[offset] = miso
          if self.radioState.register == 0x60:
            if self.radioState.rxBytesRead == 0:
              #First byte appears to be read first but 60 is also read multiple times, so gate this on
              #if we've already RXed any bytes

              self.put(self.radioState.ss, es, self.out_ann, [2,['RX Read Begin', 'RX-START']])
            else:
              incrementCounter = False

              self.radioState.rxSS = ss

          if incrementCounter:
            self.radioState.rxBytesRead = self.radioState.rxBytesRead + 1

          self.radioState.rxES = es
          self.radioState.rxByteCount = max(self.radioState.rxByteCount, offset + 1)

          self.put(self.radioState.ss, es, self.out_ann, [2,['RXed {} bytes - {}'.format(self.radioState.rxByteCount, self.radioState.rxBytesRead), 'RX-CNT']])

        else:
          self.put(self.radioState.ss, es, self.out_ann, [2,['Writing to RX Buffer: {}'.format(self.radioState.register), 'ERR']])
      elif self.radioState.register == 0x81:
        if miso == 0x03:
          self.put(self.radioState.ss, es, self.out_ann, [2,['PLL Complete'.format(power), 'PLL-END']])
          desc = "PLL-END"
        else:
          desc = "PLL-POLL"
      else:
        self.put(self.radioState.ss, es, self.out_ann, [2,['Unknown Register 0x{:02X} = 0x{:02X}'.format(self.radioState.register, mosi), 'UNK']])

      if es - self.radioState.lastCommandSample > 10000:
        delay = math.floor((es - self.radioState.lastCommandSample) / 1000)
        self.put(self.radioState.ss, es, self.out_ann, [3,['delay({}); // Delay {} cycles'.format(delay, es - self.radioState.lastCommandSample)]])

      if self.radioState.isRead:
        self.put(self.radioState.ss, es, self.out_ann, [3,['result = readRegister(0x{:02X}); // {} - Expect 0x{:02X} - {} to {}'.format(self.radioState.register, desc, miso, self.radioState.ss, es)]])
      else:
        self.put(self.radioState.ss, es, self.out_ann, [3,['writeRegister(0x{:02X}, 0x{:02X}); // {} - {} to {}'.format(self.radioState.register, mosi, desc, self.radioState.ss, es)]])
      self.radioState.lastCommandSample = es

      self.radioState.register = -1
