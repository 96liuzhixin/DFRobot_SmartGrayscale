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

uint16_t DFRobot_SmartGrayscale::getAmbience()
{
  uint16_t LIGHT;
  getRegisterValue();
  LIGHT=(sRegister.lighthigh<<8) | (sRegister.lightlow);
  return LIGHT;
}

uint16_t DFRobot_SmartGrayscale::getTrack()
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
  sendbuf[0] = newaddr;
  setRegisterValue(IIC_ADDRESS_R ,sendbuf ,1);
}

void DFRobot_SmartGrayscale::setGears(uint8_t newGears)
{
  sendbuf[0] = newGears;
  setRegisterValue(GEARS_R ,sendbuf ,1);
}

void DFRobot_SmartGrayscale::setMode(uint8_t newMode)
{
  sendbuf[0] = newMode;
  setRegisterValue(MODE_R ,sendbuf ,1);
}

void DFRobot_SmartGrayscale::setTrack(uint16_t newTrack)
{
  sendbuf[0] = (uint8_t)(newTrack >> 8);
  sendbuf[1] = (uint8_t)(newTrack & 0x00FF);
  setRegisterValue(TRACK_R ,sendbuf ,2);
}

void DFRobot_SmartGrayscale::setAmbience(uint16_t newAmbience)
{
  sendbuf[0] = (uint8_t)(newAmbience >> 8);
  sendbuf[1] = (uint8_t)(newAmbience & 0x00FF);
  setRegisterValue(AMBIENCE_R ,sendbuf ,2);
}


void DFRobot_SmartGrayscale::setOutPolar(uint8_t newOutpolar)
{
  sendbuf[0] = newOutpolar;
  setRegisterValue(OUT_POLAR_R ,sendbuf ,1);
}

void DFRobot_SmartGrayscale::setLedPolar(uint8_t newLEDpolar)
{
  sendbuf[0] = newLEDpolar;
  setRegisterValue(LED_POLAR_R ,sendbuf ,1);
}

void DFRobot_SmartGrayscale::setRegisterValue(uint8_t Register, uint8_t *data, uint8_t len)
{
  for(uint8_t i = 0; i < len; i++)
    sendbuf[i] = data[i];
  writeData(Register ,sendbuf ,len);
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

void DFRobot_SmartGrayscale_IIC::writeData(uint8_t Reg ,uint8_t *Data ,uint8_t len)
{
  _pWire->beginTransmission(this->_IIC_addr);
  _pWire->write(Reg);
  for(uint8_t i = 0; i < len; i++)
    _pWire->write(Data[i]);
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