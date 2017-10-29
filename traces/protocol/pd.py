import sigrokdecode as srd

class Decoder(srd.Decoder):
  api_version = 2
  id = 'em9201'
  name = 'EM9201 SPI'
  desc = 'Commands and data sent to EM9201 RF module used in Hallmark wireless ornaments'
  license = 'gplv2+'
  inputs = ['spi']
  outputs = 'em9201'

  def start(self):
      self.out_ann = self.register(srd.OUTPUT_ANN)


  def decode(self, ss, es, data):
