#ifndef DEVICES_MINTS_H
#define DEVICES_MINTS_H
//
// #include <Arduino.h>
#include "jobsMints.h"
#include "Seeed_BME280.h"
#include "SparkFun_SCD30_Arduino_Library.h"
#include <OPCN2NanoMints.h>
#include "MutichannelGasSensor.h"
#include "Adafruit_Sensor.h"

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

//
extern OPCN2NanoMints opc;
bool initializeOPCN2Mints();
void readOPCN2Mints();

// extern Adafruit_INA219 ina;
// bool initializeINA219Mints();
// void readINA219Mints();


// void printInput(String command);
// void sensorPrintMints(String sensor,String readigs[],uint8_t numOfvals);




















#endif
