
#include <Wire.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>

#include "Adafruit_AS726x.h"
#include "Adafruit_TSL2591.h"
#include "Adafruit_VEML6075.h"

#include "devicesMints.h"
#include "jobsMints.h"




//create the object
bool AS7262Online;
Adafruit_AS726x ams;

bool    TSL2591Online;
Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591); // pass in a number for the sensor identifier (for your use later)

bool VEML6075Online;
VEML6075 veml ;


uint16_t sensingPeriod =3062;
uint16_t initPeriod = 1500;

// unsigned long startTime;

void setup() {

  delay(initPeriod);
  initializeSerialMints();

  delay(initPeriod);
  AS7262Online = initializeAS7262Mints();

  delay(initPeriod);
  TSL2591Online      = initializeTSL2591Mints();

  delay(initPeriod);
  VEML6075Online      = initializeVEML6075Mints();

}

void loop() {
// startTime = millis();

  delay(sensingPeriod);
   if(AS7262Online)
   {
     readAS7262Mints();
   }
   delay(sensingPeriod);

   if(TSL2591Online)
       {
         readTSL2591Mints();
       }

   delay(sensingPeriod);

   if(VEML6075Online)
       {
         readVEML6075Mints();
       }

// Serial.println(millis()-startTime);

}
