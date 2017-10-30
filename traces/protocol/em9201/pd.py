import sigrokdecode as srd

class RadioState:
  txPower = 0
  txByteCount = 0
  txBuffer = []
  rxBuffer = []

  ss = 0
  es = 0

  register = 0

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
  )

  def start(self):
    self.radioState = RadioState()
    self.out_ann = self.register(srd.OUTPUT_ANN)


  def decode(self, ss, es, data):
    ptype, mosi, miso = data

    if ptype != 'DATA':
      return

    if self.radioState.register == 0:
      # New command starting
      self.radioState.ss = ss
      self.radioState.register = mosi
    else:
      if self.radioState.register == 0x1A:
        if self.radioState.resetPhase == 1 and mosi == 0x5E:
          print("RST")
          self.put(self.radioState.ss, self.radioState.es, self.out_ann, [2,['Reset', 'RST', 'R']])
          self.radioState.es = es
          self.radioState.resetPhase = 0
        elif mosi == 0xB3:
          self.radioState.resetPhase = 1
        else:
          self.radioState.resetPhase = 0
      elif self.radioState.register == 0x00:
        self.put(self.radioState.ss, self.radioState.es, self.out_ann, [2,['Clear Status 0', 'CS0', 'C']])
      elif self.radioState.register == 0x01:
        self.put(self.radioState.ss, self.radioState.es, self.out_ann, [2,['Clear Status 1', 'CS1', 'C']])
      elif self.radioState.register in range(0x40, 0x5F):
        offset = self.radioState.register - 0x40
        self.radioState.txBuffer[offset] = mosi
      elif self.radioState.register in range(0x60, 0x7F):
        offset = self.radioState.register - 0x60
        self.radioState.rxBuffer[offset] = mosi
      self.radioState.register = 0
