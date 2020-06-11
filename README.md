# DFRobot_SmartGrayscale
Smart Grayscale sensor V1.0 is a highly intelligent Grayscale sensor that subverts the tradition and is a perfect combination of technology and art.It has the characteristics of miniaturization, intelligence and multi-function.

## DFRobot_SmartGrayscale
---------------------------------------------------------
DFRobot_SmartGrayscale


## Table of Contents

* [Summary](#Summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

<snippet>
<content>


## Summary

You can set gear mode, working mode, output polarity, read environment gray level, track gray level equivalent

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++

  /**
   * @brief initialization parameters for i2c
   * @return 0 or 1, 0 is iic begin success, 1 is iic begin error
   */
  uint8_t begin();

  /**
   * @brief get Ambience value
   * @return Ambience value, This value is the reference value for the Ambience
   */
  int16_t getAmbience();

  /**
   * @brief get Track value
   * @return Track value, This value is the reference value for the Track
   */
  int16_t getTrack();

  /**
   * @brief get Thres value
   * @return Thres value, This value is the reference value for the Thres line
   */
  int16_t getThres();

  /**
   * @brief get iic device address
   * @return iic device address
   */
  uint8_t getIICAddr();

  /**
   * @brief get PID
   * @return PID (product id)
   */
  uint8_t getPID();

  /**
   * @brief get VID
   * @return VID (version id)
   */
  uint8_t getVID();

  /**
   * @brief get Gears
   * @return Gears 
   *    The higher the gear setting, the higher the measurement
   *        GEARS_HIGH   0x00
   *        GEARS_MIDDLE 0x01
   *        GEARS_LOW    0x02
   */
  uint8_t getGears();

  /**
   * @brief get Mode
   * @return Mode 
   *    Output mode is optional, digital mode is analog mode
   *        DIGITAL_OUT_MODE 0x00
   *        ANALOG_OUT_MODE  0x01
   */
  uint8_t getMode();

  /**
   * @brief get OutPolar
   * @return OutPolar 
   *    Low level output or high level output
   *        OUT_POLAR_HIGH 0x00
   *        OUT_POLAR_LOW  0x01
   */
  uint8_t getOutPolar();

  /**
   * @brief get LedPolar
   * @return LedPolar 
   *    The black light lamp or white light lamp
   *        WHITE_LIGHT 0x00
   *        BLACK_LIGHT 0x01
   */
  uint8_t getLedPolar();

  /**
   * @brief set IIC address
   * @param newaddr is i2c device number.
   */
  void setIICAddr(uint8_t newaddr);

  /**
   * @brief set Ambience
   * @param The value of the current Ambience
   */
  void setAmbience(uint8_t newAmbience);

  /**
   * @brief set Track
   * @param The value of the current newTrack
   */
  void setTrack(uint16_t newTrack);

  /**
   * @brief set GEARS ,The higher the gear setting, the higher the measurement
   * @param GEARS_HIGH   0x00
   * @param GEARS_MIDDLE 0x01
   * @param GEARS_LOW    0x02
   */
  void setGears(uint8_t newGears);

  /**
   * @brief set Mode ,Output mode is optional, digital mode is analog mode
   * @param DIGITAL_OUT_MODE 0x00
   * @param ANALOG_OUT_MODE  0x01
   */
  void setMode(uint8_t newMode);

  /**
   * @brief set Outpolar ,Low level output or high level output
   * @param OUT_POLAR_HIGH 0x00
   * @param OUT_POLAR_LOW  0x01
   */
  void setOutPolar(uint8_t newOutpolar);

  /**
   * @brief set LEDpolar ,The black light lamp or white light lamp
   * @param WHITE_LIGHT 0x00
   * @param BLACK_LIGHT 0x01
   */
  void setLedPolar(uint8_t newLEDpolar);

```
## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino uno        |      √       |              |             | 
Mega2560           |      √       |              |             | 
Lenardo            |      √       |              |             | 
micro:bit          |      √       |              |             | 
ESP32              |      √       |              |             | 

## History

-  May 21, 2020 - Version 1.0 released.

## Credits

Written by kaixingPeng(kaixing.peng@dfrobot.com), 2020. (Welcome to our [website](https://www.dfrobot.com/))