#include "Arduino.h"
#include "Seeed_BME280.h"
#include "MutichannelGasSensor.h"
#include "OPCN2NanoMints.h"
#include "jobsMints.h"
#include "devicesMints.h"



#define CS 10

OPCN2NanoMints opc = OPCN2NanoMints(CS);
bool  OPCN2Online;

bool SCD30Online;
SCD30 scd;

//
bool MGS001Online;

bool BME280Online;
BME280 bme280; // I2C

uint16_t sensingPeriod = 2417;
uint16_t initPeriod = 1500;


void setup() {

  delay(initPeriod);
  initializeSerialMints();

  delay(initPeriod);
  BME280Online = initializeBME280Mints();
  //
  delay(initPeriod);
  MGS001Online =  initializeMGS001Mints();

  //
  delay(initPeriod);
  SCD30Online = initializeSCD30Mints();

  delay(initPeriod);
  OPCN2Online =  initializeOPCN2Mints();

}




// the loop routine runs over and over again forever:
void loop() {

    delay(sensingPeriod);
    if(BME280Online)
    {
      readBME280Mints();
    }
    // //
    delay(sensingPeriod);
    if(MGS001Online)
    {
      readMGS001Mints();
    }
    // //
    delay(sensingPeriod);
    if(SCD30Online)
    {
      readSCD30Mints();
    }
    //
    delay(sensingPeriod);
    if(OPCN2Online)
    {
      readOPCN2Mints();
    }


}
