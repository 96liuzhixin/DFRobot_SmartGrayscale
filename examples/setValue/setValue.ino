/* 
 * @file setValue.ino
 * @Enter the address and value of the register you want to change
 * @You can see the print on the serial port by filling in the parameter with the value of the register you want to get
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author      [PengKaixing](kaixing.peng@dfrobot.com)
 * @version  V1.0
 * @date  2020-5-21
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/DFRobot_SmartGrayscale.git
 */
#include "DFRobot_SmartGrayscale.h"

#define I2C_ADDRESS       0x08              // default  IIC device address is 0x08
#define NEW_I2C_ADDRESS   0x08              // Modified IIC device address
DFRobot_SmartGrayscale_IIC smartgrayscale(&Wire, I2C_ADDRESS);      // i2c configuration parameters

void setup()
{
  Serial.begin(115200);
  while(smartgrayscale.begin() != 0){
    Serial.println("I2c device number error");
    delay(1000);
  }
}

void loop()
{
/*
  smartgrayscale.setIICAddr(NEW_I2C_ADDRESS);
  Serial.print("new iic device address = 0x");
  Serial.println(smartgrayscale.getIICAddr(),HEX);
  Serial.println("Restart to take effect");
*/

/*
  The higher the gear setting, the higher the measurement
    GEARS_HIGH   0x00
    GEARS_MIDDLE 0x01
    GEARS_LOW    0x02
*/
  smartgrayscale.setGears(GEARS_HIGH);
  Serial.print("new Gears = 0x");
  Serial.println(smartgrayscale.getGears(),HEX);

/*
  Output mode is optional, digital mode is analog mode
    DIGITAL_OUT_MODE 0x00
    ANALOG_OUT_MODE  0x01
*/
  smartgrayscale.setMode(DIGITAL_OUT_MODE);
  Serial.print("new mode = 0x");
  Serial.println(smartgrayscale.getMode(),HEX);

/*
  Low level output or high level output
    OUT_POLAR_HIGH   0x00
    OUT_POLAR_LOW    0x01
*/
  smartgrayscale.setOutPolar(OUT_POLAR_HIGH);
  Serial.print("new OutPolar = 0x");
  Serial.println(smartgrayscale.getOutPolar(),HEX);

/*
  The black light lamp or white light lamp
    WHITE_LIGHT   0x00
    BLACK_LIGHT   0x01
*/
  smartgrayscale.setLedPolar(WHITE_LIGHT);
  Serial.print("new LedPolar = 0x");
  Serial.println(smartgrayscale.getLedPolar(),HEX);
  delay(1000);
}