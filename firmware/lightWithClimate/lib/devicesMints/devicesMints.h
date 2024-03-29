#ifndef DEVICES_MINTS_H
#define DEVICES_MINTS_H

// #include <Arduino.h>

#include "Adafruit_AS726x.h"
#include "Adafruit_TSL2591.h"
#include <SparkFun_VEML6075_Arduino_Library.h>
#include "seeed_bme680.h"
#include "jobsMints.h"



#define IIC_ADDR  uint8_t(0x77)

extern Seeed_BME680 bme680;
bool initializeBME680Mints();
void readBME680Mints();
//


// // For HTU21D
extern Adafruit_AS726x ams;
bool initializeAS7262Mints();
void readAS7262Mints();

extern VEML6075 veml;
bool initializeVEML6075Mints();
void readVEML6075Mints();
//
//
extern Adafruit_TSL2591 tsl;
bool initializeTSL2591Mints();
void readTSL2591Mints();
// Taken from:https://github.com/adafruit/Adafruit_TSL2591_Library/blob/master/examples/tsl2591/tsl2591.ino
void displayTSL2591DetailsMints(void);
void configureTSL2591Mints(void);
void advancedReadTSL2591Mnits(void);
// Ends functions taken from:https://github.com/adafruit/Adafruit_TSL2591_Library/blob/master/examples/tsl2591/tsl2591.ino

#endif
