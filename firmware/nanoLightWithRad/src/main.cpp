
// #include <Wire.h>
// #include <Adafruit_I2CDevice.h>
// #include <Adafruit_I2CRegister.h>

// #include "Adafruit_AS726x.h"
// #include "Adafruit_TSL2591.h"
// #include <SparkFun_VEML6075_Arduino_Library.h>

#include "devicesMints.h"
#include "jobsMints.h"


//create the object
bool AS7262Online;
Adafruit_AS726x ams;

bool    TSL2591Online;
Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591); // pass in a number for the sensor identifier (for your use later)

bool VEML6075Online;
VEML6075 veml ;


uint16_t sensingPeriod =1400;
uint16_t initPeriod = 1500;




bool    LIBRADOnline;
uint8_t LIBRADPin   = 2;
long    LIBRADCount = 0;


unsigned long 
 startTime;

void setup() {

  delay(initPeriod);
  initializeSerialMints();

  delay(initPeriod);
  AS7262Online = initializeAS7262Mints();

  delay(initPeriod);
  TSL2591Online      = initializeTSL2591Mints();

  delay(initPeriod);
  VEML6075Online      = initializeVEML6075Mints();
  
  delay(1000);
  LIBRADOnline       = initializeLIBRADMints();

}

void loop() {
//  startTime = millis();

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

  if(LIBRADOnline)
      {
        readLIBRADMints(5);
      }

//  Serial.println(millis()-startTime);

}
