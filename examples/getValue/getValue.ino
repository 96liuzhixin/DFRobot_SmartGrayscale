/* 
 * @file getValue.ino
 * @You can see the print on the serial port by filling in the parameter with the value of the register you want to get
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author      [PengKaixing](kaixing.peng@dfrobot.com)
 * @version  V2.0
 * @date  2020-5-21
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/DFRobot_SmartGrayscale.git
 */
#include "DFRobot_SmartGrayscale.h"

#define I2C_ADDRESS  0x08                   // default IIC device address is 0x08
DFRobot_SmartGrayscale_IIC smartgrayscale(&Wire, I2C_ADDRESS);      // i2c configuration parameters

void setup()
{
  Serial.begin(115200);
  while(smartgrayscale.begin() != 0) {
    Serial.println("I2c device number error");
    delay(1000);
  }
}

void loop()
{
  Serial.print("IIC address = 0x");
  Serial.println(smartgrayscale.getIICAddr(),HEX);
  
  Serial.print("PID = 0x");
  Serial.println(smartgrayscale.getPID(),HEX);
  
  Serial.print("VID = 0x");
  Serial.println(smartgrayscale.getVID(),HEX);

  Serial.print("Gears = 0x");
  Serial.println(smartgrayscale.getGears(),HEX);

  Serial.print("Mode = 0x");
  Serial.println(smartgrayscale.getMode(),HEX);

  Serial.print("White = 0x");
  Serial.println(smartgrayscale.getWhite(),HEX);

  Serial.print("Black = 0x");
  Serial.println(smartgrayscale.getBlack(),HEX);

  Serial.print("Thres = 0x");
  Serial.println(smartgrayscale.getThres(),HEX);

  Serial.print("Outpolar = 0x");
  Serial.println(smartgrayscale.getOutPolar(),HEX);

  Serial.print("LEDpolar = 0x");
  Serial.println(smartgrayscale.getLedPolar(),HEX);
  delay(1000);
}