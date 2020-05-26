#ifndef __DFRobot_SMARTGRAYSCALE_H__
#define __DFRobot_SMARTGRAYSCALE_H__
#include <Arduino.h>
#include <Wire.h>


#define PID_R   0x01
#define VID_R   0x02
#define GEARS_R 0x03
#define MODE_R  0x04

#define OUT_POLAR_R   0x0B
#define LED_POLAR_R   0x0C
#define IIC_ADDRESS_R 0x00

#define GEARS_HIGH    0x00
#define GEARS_MIDDLE  0x01
#define GEARS_LOW     0x02

#define DIGITAL_OUT_MODE 0x00
#define ANALOG_OUT_MODE  0x01

#define OUT_POLAR_HIGH   0x00
#define OUT_POLAR_LOW    0x01

#define WHITE_LIGHT      0x00
#define BLACK_LIGHT      0x01


typedef struct{
  uint8_t iicvalue;
  uint8_t pidvalue;
  uint8_t vidvalue;
  uint8_t gearsvalue;
  uint8_t modevalue;
  uint8_t lighthigh;
  uint8_t lightlow;
  uint8_t blackhigh;
  uint8_t blacklow;
  uint8_t threshigh;
  uint8_t threslow;
  uint8_t outploarvalue;
  uint8_t ledpolarvalue;
}sRegister_t;
extern sRegister_t sRegister;

class DFRobot_SmartGrayscale{
public:
  DFRobot_SmartGrayscale(){};
  ~DFRobot_SmartGrayscale(){};
  void setIICAddr(uint8_t newaddr);
  void setGears(uint8_t newGears);
  void setMode(uint8_t newMode);
  void setOutPolar(uint8_t newOutpolar);
  void setLedPolar(uint8_t newLEDpolar);
  void setRegisterValue(uint8_t Register,uint8_t data);
  void getRegisterValue();
  uint16_t getWhite();
  uint16_t getBlack();
  uint16_t getThres();
  uint8_t  getIICAddr();
  uint8_t  getPID();
  uint8_t  getVID();
  uint8_t  getGears();
  uint8_t  getMode();
  uint8_t  getOutPolar();
  uint8_t  getLedPolar();
  uint8_t  buf[14]={0};
protected:
  virtual uint8_t readData(uint8_t Reg)=0;
  virtual void writeData(uint8_t Reg,uint8_t Data)=0;
};

class DFRobot_SmartGrayscale_IIC:public DFRobot_SmartGrayscale{
public:
  DFRobot_SmartGrayscale_IIC(TwoWire *pWire=&Wire ,uint8_t addr=0x08);
  ~DFRobot_SmartGrayscale_IIC(){};
  void writeData(uint8_t Reg,uint8_t Data);
  uint8_t readData(uint8_t Reg);
  uint8_t begin();
private:
  TwoWire *_pWire;
  uint8_t _IIC_addr;
};

#endif