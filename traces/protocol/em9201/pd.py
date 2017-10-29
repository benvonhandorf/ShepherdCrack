import sigrokdecode as srd


class Decoder(srd.Decoder):
  class RadioState:
    txPower = 0
    txByteCount = 0
    txBuffer = []

    ss = 0
    es = 0

    register = 0

    resetPhase = 0

  api_version = 2
  id = 'em9201'
  name = 'EM9201 SPI'
  desc = 'Commands and data sent to EM9201 RF module used in Hallmark wireless ornaments'
  license = 'gplv2+'
  inputs = ['spi']
  outputs = ['em9201-tx', 'em9201-rx', 'em9201-cfg']
  annotations = (
    ('tx', 'Transmitted data'),
    ('rx', 'Received data'),
    ('cfg', 'Config changes'),
  )

  radioState = RadioState()

  def start(self):
    self.out_ann = self.register(srd.OUTPUT_ANN)


  def decode(self, ss, es, data):
    ptype, mosi, miso = data

    if ptype != 'DATA':
      return

    if radioState.register == 0:
      # New command starting
      radioState.ss = ss
      radioState.register = mosi
      print("Register : {0}".format(radioState.register))
    elif radioState.register == 0x1A:
      if radioState.resetPhase == 1 and mosi == 0x5E:
        self.put(radioState.ss, radioState.es, self.out_ann, [2,['Reset', 'RST', 'R']])
        radioState.es = es
        radioState.resetPhase = 0
      elif mosi == 0xB3:
        radioState.resetPhase = 1
      else:
        radioState.resetPhase = 0
    else:
      #A command we didn't comprehend yet has completed.  Reset the state of the decoder
      print("Register : {0} - Data : {1}".format(radioState.register, mosi))
      radioState.register = 0
