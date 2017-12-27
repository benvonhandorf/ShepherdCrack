import sigrokdecode as srd

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
      if dat is not None:
        rxBytes += "{}: {:02X} ".format(i, dat)

    self.put(self.radioState.rxSS, self.radioState.rxES, self.out_ann, [1, ["RX: {0}".format(rxBytes), rxBytes]])

  def dumpTransmit(self, ss, es):
    txBytes = ""

    for i in range(0, self.radioState.txByteCount):
      dat = self.radioState.txBuffer.get(i)
      if dat is None:
        txBytes += "{}: XX ".format(i)
      else:
        txBytes += "{}: {:02X} ".format(i, dat)

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
      if self.radioState.isRead:
        self.put(self.radioState.ss, es, self.out_ann, [3,['readRegister(0x{:02X}); // Expect 0x{:02X} - {} to {}'.format(self.radioState.register, miso, self.radioState.ss, es)]])
      else:
        self.put(self.radioState.ss, es, self.out_ann, [3,['writeRegister(0x{:02X}, 0x{:02X}); // {} to {}'.format(self.radioState.register, mosi, self.radioState.ss, es)]])

      if self.radioState.register == 0x1A:
        if self.radioState.resetPhase == 1 and mosi == 0x5E:
          self.put(self.radioState.ss, es, self.out_ann, [2,['Reset', 'RST', 'R']])
          self.radioState.es = es
          self.radioState.resetPhase = 0
        elif mosi == 0xB3:
          self.radioState.resetPhase = 1
        else:
          self.radioState.resetPhase = 0
      elif self.radioState.register == 0x00:
        self.put(self.radioState.ss, es, self.out_ann, [2,['Clear Status 0', 'CS0', 'C']])
      elif self.radioState.register == 0x01:
        self.put(self.radioState.ss, es, self.out_ann, [2,['Clear Status 1', 'CS1', 'C']])
      elif self.radioState.register == 0x02:
        self.put(self.radioState.ss, es, self.out_ann, [2,['Int1Msk {:02X}'.format(mosi), 'Int1Msk']])
      elif self.radioState.register == 0x03:
        self.put(self.radioState.ss, es, self.out_ann, [2,['Int2Msk {:02X}'.format(mosi), 'Int2Msk']])
      elif self.radioState.register == 0x04:

        if(mosi == 0x07):
          self.dumpTransmit(ss, es)
        elif mosi == 0x02:
          self.put(self.radioState.ss, es, self.out_ann, [2,['RX Enabled'.format(mosi), 'RX']])  
          self.radioState.rxByteCount = 0
          self.radioState.rxBytesRead = 0
          self.radioState.rxBuffer = {}
        elif mosi == 0x00:
          self.put(self.radioState.ss, es, self.out_ann, [2,['Radio Stop', 'RDO-OFF']])  
          if self.radioState.rxBytesRead > 0:
            self.dumpReceive()

          self.radioState.rxByteCount = 0
          self.radioState.rxBytesRead = 0
          self.radioState.rxBuffer = {}
      elif self.radioState.register == 0x06:
        self.put(self.radioState.ss, es, self.out_ann, [2,['Power Config {:02X}'.format(mosi), 'PWR-CFG']])

      elif self.radioState.register == 0x06:
        self.put(self.radioState.ss, es, self.out_ann, [2,['RF Config {:02X}'.format(mosi), 'RFC']])

        if mosi | 0x40 == 0x40:
          self.put(self.radioState.ss, es, self.out_ann, [2,['PLL Autoconfig Start', 'PLL']])

        power = mosi & 0x07
        self.put(self.radioState.ss, es, self.out_ann, [2,['Power {0}'.format(power), 'PWR']])
      elif self.radioState.register == 0x07:
        self.put(self.radioState.ss, es, self.out_ann, [2,['RF Channel {}'.format(mosi), 'CHAN']])

      elif self.radioState.register == 0x0B:
        if mosi | 0x10 == 0x10:
          self.put(self.radioState.ss, es, self.out_ann, [2,['ACK Enabled', 'ACK-ON']])
        else:
          self.put(self.radioState.ss, es, self.out_ann, [2,['ACK Disabled', 'ACK-OFF']])

        power = mosi & 0x07
        self.put(self.radioState.ss, es, self.out_ann, [2,['Power {0}'.format(power), 'PWR']])
      elif 0x0E <= self.radioState.register <= 0x10:
        offset = self.radioState.register - 0x0E
        self.radioState.address[offset] = mosi
        addr = ""

        for i in range(0, 3):
            addr += "{:02X} ".format(self.radioState.address[i])

        self.put(self.radioState.ss, es, self.out_ann, [2,['Address: {}'.format(addr), 'ADDR']])

      elif 0x11 <= self.radioState.register <= 0x13:
        offset = self.radioState.register - 0x11
        self.radioState.peerAddress[offset] = mosi
        addr = ""

        for i in range(0, 3):
            addr += "{:02X} ".format(self.radioState.peerAddress[i])

        self.put(self.radioState.ss, es, self.out_ann, [2,['Peer Address: {}'.format(addr), 'PEER']])

      elif self.radioState.register == 0x14:
        self.radioState.txByteCount = mosi
        self.put(self.radioState.ss, es, self.out_ann, [2,['Tx Size set {0}'.format(self.radioState.txByteCount), 'TX Len {0}'.format(self.radioState.txByteCount)]])
      elif self.radioState.register == 0x16:
        self.put(self.radioState.ss, es, self.out_ann, [2,['FIFO Config {:02X}'.format(mosi), 'FIFO']])

      elif 0x40 <= self.radioState.register <= 0x5F:
        offset = self.radioState.register - 0x40
        self.radioState.txBuffer[offset] = mosi
      elif 0x60 <= self.radioState.register <= 0x7F:
        offset = self.radioState.register - 0x60
        if self.radioState.isRead:
          incrementCounter = True
          # Data appears to be read 60 64 65 66 *60* 61 62 63
          self.radioState.rxBuffer[offset] = miso
          if self.radioState.register == 0x60:
            if self.radioState.rxBytesRead == 0:
              self.put(self.radioState.ss, es, self.out_ann, [2,['RX Read Begin', 'RX-START']])
            else:
              incrementCounter = False
            #First byte appears to be read first but 60 is also read multiple times, so gate this on
            #if we've already RXed any bytes
              
              # if miso == 0x02:
              #   self.radioState.rxByteCount = 7
              # elif miso == 0x03:
              #   self.radioState.rxByteCount = 6
              # elif miso == 0x04:
              #   self.radioState.rxByteCount = 5
              # elif miso == 0x05:
              #   self.radioState.rxByteCount = 5
              # else:
              #   self.put(self.radioState.ss, es, self.out_ann, [2,['RX UNEXPECTED BYTE {:02X}'.format(miso), 'RX-ERR']])
              #   self.radioState.rxByteCount = 6

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
      else:
        self.put(self.radioState.ss, es, self.out_ann, [2,['Unknown Register 0x{:02X} = 0x{:02X}'.format(self.radioState.register, mosi), 'UNK']])
      self.radioState.register = -1
