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

#define NEW_AMBIENCE      0x384             // dafault Ambience value ,Used to calculate the thres value
#define NEW_TRACK         0x64              // dafault Track value ,Used to calculate the thres value
#define I2C_ADDRESS       0x08              // default IIC device address is 0x08
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
  The higher the gear setting ,the higher the measurement
    GEARS_HIGH   0x02
    GEARS_MIDDLE 0x01
    GEARS_LOW    0x00
*/
  smartgrayscale.setGears(GEARS_HIGH);
  Serial.print("new Gears = 0x0");
  Serial.println(smartgrayscale.getGears(),HEX);

/*
  set Ambience value ,Used to calculate the thres value
*/
  smartgrayscale.setAmbience(NEW_AMBIENCE);
  Serial.print("new Ambience = 0x");
  Serial.println(smartgrayscale.getAmbience(),HEX);

/*
  set Track value ,Used to calculate the thres value
*/
  smartgrayscale.setTrack(NEW_TRACK);
  Serial.print("new Track = 0x");
  Serial.println(smartgrayscale.getTrack(),HEX);

/*
  Output mode is optional, digital mode is analog mode
    DIGITAL_OUT_MODE 0x00
    ANALOG_OUT_MODE  0x01
*/
  smartgrayscale.setMode(DIGITAL_OUT_MODE);
  Serial.print("new mode = 0x0");
  Serial.println(smartgrayscale.getMode(),HEX);

/*
  Identifies the track output high or low level
    OUT_POLAR_LOW    0x00
    OUT_POLAR_HIGH   0x01
*/
  smartgrayscale.setOutPolar(OUT_POLAR_HIGH);
  Serial.print("new OutPolar = 0x0");
  Serial.println(smartgrayscale.getOutPolar(),HEX);

/*
  The LED is the same or opposite to the output level
    DIFFERENT   0x00
    SAME        0x01
*/
  smartgrayscale.setLedPolar(SAME);
  Serial.print("new LedPolar = 0x0");
  Serial.println(smartgrayscale.getLedPolar(),HEX);
  Serial.println();
  delay(1000);
}