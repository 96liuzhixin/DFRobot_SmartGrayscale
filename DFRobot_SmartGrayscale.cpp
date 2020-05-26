#include "DFRobot_SmartGrayscale.h"

sRegister_t sRegister;
void DFRobot_SmartGrayscale::getRegisterValue()
{
  readData(0x00);
  memcpy(&sRegister, buf, 13);
}

uint8_t DFRobot_SmartGrayscale::getIICAddr()
{
  getRegisterValue();
  return sRegister.iicvalue;
}

uint8_t DFRobot_SmartGrayscale::getPID()
{
  getRegisterValue();
  return sRegister.pidvalue;
}

uint8_t DFRobot_SmartGrayscale::getVID()
{
  getRegisterValue();
  return sRegister.vidvalue;
}

uint8_t DFRobot_SmartGrayscale::getGears()
{
  getRegisterValue();
  return sRegister.gearsvalue;
}

uint8_t DFRobot_SmartGrayscale::getMode()
{
  getRegisterValue();
  return sRegister.modevalue;
}

uint16_t DFRobot_SmartGrayscale::getWhite()
{
  uint16_t LIGHT;
  getRegisterValue();
  LIGHT=(sRegister.lighthigh<<8) | (sRegister.lightlow);
  return LIGHT;
}

uint16_t DFRobot_SmartGrayscale::getBlack()
{
  uint16_t BLACK;
  getRegisterValue();
  BLACK=(sRegister.blackhigh<<8) | (sRegister.blacklow);
  return BLACK;
}

uint16_t DFRobot_SmartGrayscale::getThres()
{
  uint16_t THRES;
  getRegisterValue();
  THRES=(sRegister.threshigh<<8) | (sRegister.threslow);
  return THRES;
}

uint8_t DFRobot_SmartGrayscale::getOutPolar()
{
  getRegisterValue();
  return sRegister.outploarvalue;
}

uint8_t DFRobot_SmartGrayscale::getLedPolar()
{
  getRegisterValue();
  return sRegister.ledpolarvalue;
}

void DFRobot_SmartGrayscale::setIICAddr(uint8_t newaddr)
{
  setRegisterValue(IIC_ADDRESS_R,newaddr);
}

void DFRobot_SmartGrayscale::setGears(uint8_t newGears)
{
  setRegisterValue(GEARS_R,newGears);
}

void DFRobot_SmartGrayscale::setMode(uint8_t newMode)
{
  setRegisterValue(MODE_R,newMode);
}

void DFRobot_SmartGrayscale::setOutPolar(uint8_t newOutpolar)
{
  setRegisterValue(OUT_POLAR_R,newOutpolar);
}

void DFRobot_SmartGrayscale::setLedPolar(uint8_t newLEDpolar)
{
  setRegisterValue(LED_POLAR_R,newLEDpolar);
}

void DFRobot_SmartGrayscale::setRegisterValue(uint8_t Register,uint8_t data)
{
  writeData(Register,data);
}

DFRobot_SmartGrayscale_IIC::DFRobot_SmartGrayscale_IIC(TwoWire *pWire, uint8_t addr)
{
  _pWire = pWire;
  this->_IIC_addr = addr;
}

uint8_t DFRobot_SmartGrayscale_IIC::begin(void)
{
  _pWire->begin();
  _pWire->beginTransmission(_IIC_addr);
  if(_pWire->endTransmission() == 0)
    return 0;
  return 1;
}

void DFRobot_SmartGrayscale_IIC::writeData(uint8_t Reg,uint8_t Data)
{
  _pWire->beginTransmission(this->_IIC_addr);
  _pWire->write(Reg);
  _pWire->write(Data);
  _pWire->endTransmission();
}

uint8_t DFRobot_SmartGrayscale_IIC::readData(uint8_t Reg)
{
  int i=0;
  _pWire->beginTransmission(this->_IIC_addr);
  _pWire->write(Reg);
  _pWire->endTransmission();
  _pWire->requestFrom((uint8_t)this->_IIC_addr,(uint8_t)13);
  while (_pWire->available()){
    buf[i++]=_pWire->read();
  }
}