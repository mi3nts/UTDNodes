#include "Arduino.h"
#include "jobsMints.h"
#include "devicesMints.h"



bool SCD30Online;
SCD30 scd;

//
bool MGS001Online;

bool BME280Online;
BME280 bme280; // I2C

bool BME680Online;
Seeed_BME680 bme680(IIC_ADDR); /* IIC PROTOCOL */

uint16_t sensingPeriod = 2000;
uint16_t initPeriod = 1500;

unsigned long startTime;
void setup() {

  delay(initPeriod);
  initializeSerialMints();

  delay(initPeriod);
  BME280Online = initializeBME280Mints();
  
  delay(initPeriod);
  BME680Online = initializeBME680Mints();

  delay(initPeriod);
  MGS001Online =  initializeMGS001Mints();

  
  delay(initPeriod);
  SCD30Online = initializeSCD30Mints();


}




// the loop routine runs over and over again forever:
void loop() {
    startTime  = millis();
   
    delay(sensingPeriod);
    if(BME280Online)
    {
      readBME280Mints();
    }
    
    delay(sensingPeriod);
    if(BME680Online)
    {
      readBME680Mints(); 
    }

    delay(sensingPeriod);
    if(SCD30Online)
    {
      readSCD30Mints();
    }
    
     delay(sensingPeriod);
    if(MGS001Online)
    {
      readMGS001Mints();
    }
    delayMints(millis() - startTime,10000);

}
                                                                       