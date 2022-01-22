#ifndef DEVICES_MINTS_H
#define DEVICES_MINTS_H
//
// #include <Arduino.h>
#include "jobsMints.h"

#include "seeed_bme680.h"
#include "Seeed_BME280.h"
#include "SparkFun_SCD30_Arduino_Library.h"
#include "MutichannelGasSensor.h"
#include "Adafruit_Sensor.h"

// bme680
#define IIC_ADDR  uint8_t(0x77)
extern Seeed_BME680 bme680;
bool initializeBME680Mints();
void readBME680Mints();
//
extern BME280 bme280;
bool initializeBME280Mints();
void readBME280Mints();
//
bool initializeMGS001Mints();
void readMGS001Mints();
//
extern SCD30 scd;
bool initializeSCD30Mints();
void readSCD30Mints();




#endif
