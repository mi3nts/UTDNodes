#ifndef DEVICES_MINTS_H
#define DEVICES_MINTS_H

// #include <Arduino.h>
#include "jobsMints.h"
#include "seeed_bme680.h"


#define IIC_ADDR  uint8_t(0x77)

// #define CONV_FACTOR 0.00812

// extern uint8_t PPD42NSPinMid;
// extern uint8_t PPD42NSPinPM10;
// bool initializePPD42NSDuoMints();
// void readPPD42NSDuoMints(uint8_t sampleTimeSeconds);


extern Seeed_BME680 bme680;
bool initializeBME680Mints();
void readBME680Mints();
//

// extern uint8_t PPD42NSPinMid;
// extern uint8_t PPD42NSPinPM10;
// bool initializePPD42NSDuoMints();
// void readPPD42NSDuoMints(uint8_t sampleTimeSeconds);



#endif
