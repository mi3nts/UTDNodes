#include <Arduino.h>
#include <Wire.h>
#include <devicesMints.h>
#include <jobsMints.h>

// bool PPD42NSOnline;

// uint8_t PPD42NSPinMid = 3;
// uint8_t PPD42NSPinPM10 = 4;

bool PPD42NSOnline;

uint8_t PPD42NSPinMid = 2;
uint8_t PPD42NSPinPM10 = 3;

bool BME680Online;
Seeed_BME680 bme680(IIC_ADDR); /* IIC PROTOCOL */


uint16_t initPeriod = 1500;
uint16_t sensingPeriod = 1500;

unsigned long startTime;

void setup() {
  initializeSerialMints();
  delay(initPeriod);
  BME680Online = initializeBME680Mints();
  delay(initPeriod);
  PPD42NSOnline = initializePPD42NSDuoMints();
  delay(1000);
}


// the loop routine runs over and over again forever:
void loop() {
    startTime  = millis();
 if(BME680Online)
    {
      readBME680Mints();
    }
  delay(sensingPeriod);

  if(PPD42NSOnline)
    {
    readPPD42NSDuoMints(5);
    }

  delayMints(millis() - startTime,10000);

}
