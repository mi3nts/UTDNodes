#ifndef DEVICES_MINTS_H
#define DEVICES_MINTS_H
//
#include <Arduino.h>
#include "seeed_bme680.h"
#include "Seeed_BME280.h"
#include "SparkFun_SCD30_Arduino_Library.h"
#include "jobsMints.h"


#define IIC_ADDR  uint8_t(0x77)

// bme680
extern Seeed_BME680 bme680;
bool initializeBME680Mints();
void readBME680Mints();

extern BME280 bme280;
bool initializeBME280Mints();
void readBME280Mints();

extern SCD30 scd;
bool initializeSCD30Mints();
void readSCD30Mints();


#endif
