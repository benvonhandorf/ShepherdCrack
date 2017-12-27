#include <SPI.h>


// pins used for the connection with the sensor
// the other you need are controlled by the SPI library):
const int dataReadyPin = 9;
const int chipSelectPin = 10;

void setup() {
  Serial.begin(9600);

  // initalize the  data ready and chip select pins:
  pinMode(dataReadyPin, INPUT);
  pinMode(chipSelectPin, OUTPUT);

  digitalWrite(chipSelectPin, HIGH);

  
  // start the SPI library:
  SPI.begin();

  delay(800);

  //Reset the radio
  writeRegister(0x1A, 0xB3);
  writeRegister(0x1A, 0x5E);

  //Reset interrupts
  writeRegister(0x00, 0xFF);
  writeRegister(0x01, 0xFF);

  //Undocumented registers
  writeRegister(0x1B, 0x74);
  writeRegister(0x1B, 0x9B);
  
  writeRegister(0x2A, 0x7B);
  writeRegister(0x2B, 0x14);

  writeRegister(0x22, 0x60);
  writeRegister(0x35, 0x41);
  writeRegister(0x34, 0x02);
  writeRegister(0x36, 0x03);
  writeRegister(0x24, 0x10);
  writeRegister(0x32, 0x33);
  writeRegister(0x33, 0x34);
  writeRegister(0x31, 0x87);
  writeRegister(0x32, 0x11);
  writeRegister(0x33, 0x22);
  writeRegister(0x31, 0x88);
  writeRegister(0x32, 0xFF);
  writeRegister(0x33, 0x00);
  writeRegister(0x31, 0x89);
  writeRegister(0x32, 0xEE);
  writeRegister(0x33, 0xEE);
  writeRegister(0x31, 0x8A);
  writeRegister(0x22, 0x00);

  //Back to normal land
  writeRegister(0x04, 0x02);

  //Reset interrupts
  writeRegister(0x00, 0xFF);
  writeRegister(0x01, 0xFF);

  writeRegister(0x02, 0x00);
  writeRegister(0x03, 0x01);

  writeRegister(0x06, 0x37);

  delay(1);

  writeRegister(0x06, 0x17);
  writeRegister(0x04, 0x00);
  writeRegister(0x0B, 0x1D);

  //More dragons
  writeRegister(0xBD, 0xFF);
  writeRegister(0x3D, 0x32);

  writeRegister(0x07, 0x1A);
  writeRegister(0x16, 0x10);
  
  //Reset interrupts
  writeRegister(0x00, 0xFF);
  writeRegister(0x01, 0xFF);

  Serial.println("Configuring addresses");

  //Set the own address
  writeRegister(0x0E, 0x5A);
  writeRegister(0x0F, 0x00);
  writeRegister(0x10, 0x5A);

  //Set the peer address
  writeRegister(0x11, 0x5A);
  writeRegister(0x12, 0x00);
  writeRegister(0x13, 0x5A);

  writeRegister(0x04, 0x02);
  writeRegister(0x02, 0x08);
  writeRegister(0x03, 0x00);

  //Reset interrupts
  writeRegister(0x00, 0xFF);
  writeRegister(0x01, 0xFF);

  delay(25);

  writeRegister(0x09, 0x10);

  delay(25);

  byte result = 0x00;

  result = readRegister(0x89);

  if(result != 0x10) {
    Serial.print("Expected response mismatch.  Wanted 0x10, got:");
    Serial.println(result, HEX);
  }

  writeRegister(0x09, 0x00);
  writeRegister(0x04, 0x00);

  writeRegister(0x00, 0xFF);

  writeRegister(0x07, 0x0F);

  writeRegister(0x16, 0x10);

  //Reset interrupts
  writeRegister(0x00, 0xFF);
  writeRegister(0x01, 0xFF);

  //In their startup, they set the addresses here again.  If this doesn't work, add that in here

  writeRegister(0x04, 0x02);
  writeRegister(0x02, 0x80);
  writeRegister(0x03, 0x00);

  writeRegister(0x00, 0xFF);
  writeRegister(0x01, 0xFF);

  //PLL Autoconfig
  writeRegister(0x06, 0x04);

  delay(800);

  result = 0x02;

  while((result & 0x01) == 0) {
    result = readRegister(0x81);
    delay(5);
  }

  Serial.println("PLL Autoconfig Completed");

  writeRegister(0x08, 0x31);

  Serial.println("1");

  writeRegister(0x0C, 0x02);

  Serial.println("2");
  
  //Reset interrupts
  writeRegister(0x00, 0xFF);
  writeRegister(0x01, 0xFF);

  Serial.println("3");

  writeRegister(0x07, 0x1A);

  delay(200);

  //TX Length
  writeRegister(0x14, 0x1F);

  writeRegister(0x02, 0x40);
  writeRegister(0x03, 0x00);

  //Reset interrupts
  writeRegister(0x00, 0xFF);
  writeRegister(0x01, 0xFF);

  writeRegister(0x16, 0xC0);

  //Disable ACKs
  writeRegister(0x0B, 0x00);
  delay(100);

  Serial.println("Radio configured, sending start signal");

  for(int i = 0x172; i > 0; i -= 2) {
    Serial.print("Countdown: ");
    Serial.println(i);
    
    writeRegister(0x40, 0x02);
    writeRegister(0x41, 0x09);
    writeRegister(0x42, i & 0xFF);
    writeRegister(0x43, (i >> 8) & 0xFF);
    writeRegister(0x44, 0x13);
    writeRegister(0x45, 0x01);
    writeRegister(0x46, 0x13);
    
    //Beginning TX
    writeRegister(0x04, 0x07);

    delay(10);
  }
  
  delay(10000);
}

void loop() {
}

byte readRegister(byte thisRegister ) {
  byte inByte = 0;           // incoming byte from the SPI
  unsigned int result = 0;   // result to return
  Serial.print(thisRegister, HEX);
  Serial.print("\t");

  //High bit being set indicates a read
  //thisRegister = 0x80 | thisRegister;
  // now combine the address and the command into one byte

  digitalWrite(chipSelectPin, LOW);
  
  // gain control of the SPI port
  // and configure settings
  SPI.beginTransaction(SPISettings(100000, MSBFIRST, SPI_MODE0));
  // send the device the register you want to read:
  SPI.transfer(thisRegister);
  // send a value of 0 to read the first byte returned:
  result = SPI.transfer(0x00);

  // release control of the SPI port
  SPI.endTransaction();
  // return the result:

  digitalWrite(chipSelectPin, HIGH);

  Serial.println(result, HEX);
  
  return(result);
}

void writeRegister(byte thisRegister, byte thisValue) {

  // gain control of the SPI port
  // and configure settings
  SPI.beginTransaction(SPISettings(100000, MSBFIRST, SPI_MODE0));

  digitalWrite(chipSelectPin, LOW);

  SPI.transfer(thisRegister); //Send register location
  SPI.transfer(thisValue);  //Send value to record into register

  // release control of the SPI port
  SPI.endTransaction();

  digitalWrite(chipSelectPin, HIGH);
}



