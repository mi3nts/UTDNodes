
#include "devicesMints.h"
//
//
//
// AS7262 ---------------------------------------
bool initializeAS7262Mints()
{
    if (ams.begin())
    {
      Serial.println("AS7262 Initiated");
      delay(1);
      return true;
    }else
    {
      Serial.println("AS7262 Not found");
      delay(1);
      return false;
    }
}


void readAS7262Mints(){

    uint8_t temperature = ams.readTemperature();

    //ams.drvOn(); //uncomment this if you want to use the driver LED for readings
    ams.startMeasurement(); //begin a measurement

    //wait till data is available
    bool rdy = false;
    while(!rdy){
      delay(5);
      rdy = ams.dataReady();
    }

    //read the values!
    uint16_t AS7262Values[AS726x_NUM_CHANNELS];
    float    AS7262Calibrated[AS726x_NUM_CHANNELS];

    ams.readRawValues(AS7262Values);
    ams.readCalibratedValues(AS7262Calibrated);

  String readings[13] = { String(temperature),\
       String(AS7262Values[AS726x_VIOLET]),\
       String(AS7262Values[AS726x_BLUE]),\
       String(AS7262Values[AS726x_GREEN]),\
       String(AS7262Values[AS726x_YELLOW]),\
       String(AS7262Values[AS726x_ORANGE]),\
       String(AS7262Values[AS726x_RED]),\
       String(AS7262Calibrated[AS726x_VIOLET]),\
       String(AS7262Calibrated[AS726x_BLUE]),\
       String(AS7262Calibrated[AS726x_GREEN]),\
       String(AS7262Calibrated[AS726x_YELLOW]),\
       String(AS7262Calibrated[AS726x_ORANGE]),\
       String(AS7262Calibrated[AS726x_RED])\
     };
  sensorPrintMints("AS7262",readings,13);

}






//     veml.begin(VEML6070_4_T);
//     Serial.println("VEML6070 Initiated");
//     delay(1);
//     return true;
//
// }
//
// void readVEML6070Mints(){
//
//   float UVLightLevel = veml.readUV();
//
//   String readings[1] = { String(UVLightLevel,2) };
//   sensorPrintMints("VEML6070",readings,1);
//
// }


// VEML6075 ---------------------------------------
bool initializeVEML6075Mints()
{
    if (veml.begin())
    {
      // cannot set to 800
        veml.setIntegrationTime(VEML6075::IT_800MS);

        // Set the high dynamic mode
        veml.setHighDynamic(VEML6075::DYNAMIC_HIGH);
          // Get the mode


      Serial.println("VEML6075 Initiated");

      delay(1);
      return true;
    }else
    {
      Serial.println("VEML6075 Not found");
      delay(1);
      return false;
    }
}



void readVEML6075Mints(){

  String readings[7] = {   String(veml.rawUva()),
                           String(veml.rawUvb()),
                           String(veml.visibleCompensation()),
                           String(veml.irCompensation()),
                           String(veml.uva()),
                           String(veml.uvb()),
                           String(veml.index())
                         };
  sensorPrintMints("VEML6075",readings,7);

}

// TSL2591 ---------------------------------------
bool initializeTSL2591Mints()
{
  if (tsl.begin())
  {
    delay(10);
    displayTSL2591DetailsMints();
    delay(10);
    configureTSL2591Mints();
    Serial.println("TSL2591 Initiated");
    delay(1);
    return true;
  }else
  {
    Serial.println("TSL2591 not found");
    delay(1);
    return false;
  }
}

void readTSL2591Mints(){

  uint32_t luminosity      = tsl.getFullLuminosity();
  uint16_t ir              = luminosity >> 16;
  uint16_t full            = luminosity & 0xFFFF;
  uint16_t visible         = full - ir;
  float    lux             = tsl.calculateLux(full, ir);

  String readings[5] = { String(luminosity) ,  String(ir) , String(full) , String(visible) , String(lux,6) };
  sensorPrintMints("TSL2591",readings,5);

}


/**************************************************************************/
/*
    Taken from:
    https://github.com/adafruit/Adafruit_TSL2591_Library/blob/master/examples/tsl2591/tsl2591.ino
*/
/**************************************************************************/

void displayTSL2591DetailsMints(void)
{
    sensor_t sensor;
    tsl.getSensor(&sensor);
    Serial.println(F("------------------------------------"));
    Serial.print  (F("Sensor:       ")); Serial.println(sensor.name);
    Serial.print  (F("Driver Ver:   ")); Serial.println(sensor.version);
    Serial.print  (F("Unique ID:    ")); Serial.println(sensor.sensor_id);
    Serial.print  (F("Max Value:    ")); Serial.print(sensor.max_value); Serial.println(F(" lux"));
    Serial.print  (F("Min Value:    ")); Serial.print(sensor.min_value); Serial.println(F(" lux"));
    Serial.print  (F("Resolution:   ")); Serial.print(sensor.resolution, 4); Serial.println(F(" lux"));
    Serial.println(F("------------------------------------"));
    Serial.println(F(""));
    delay(500);
}

/**************************************************************************/
/*
    Configures the gain and integration time for the TSL2591
*/
/**************************************************************************/
void configureTSL2591Mints(void)
{


    // You can change the gain on the fly, to adapt to brighter/dimmer light situations
    //tsl.setGain(TSL2591_GAIN_LOW);    // 1x gain (bright light)
    tsl.setGain(TSL2591_GAIN_MED);      // 25x gain
    //tsl.setGain(TSL2591_GAIN_HIGH);   // 428x gain

    // Changing the integration time gives you a longer time over which to sense light
    // longer timelines are slower, but are good in very low light situtations!
    //tsl.setTiming(TSL2591_INTEGRATIONTIME_100MS);  // shortest integration time (bright light)
    // tsl.setTiming(TSL2591_INTEGRATIONTIME_200MS);
    tsl.setTiming(TSL2591_INTEGRATIONTIME_300MS);
    // tsl.setTiming(TSL2591_INTEGRATIONTIME_400MS);
    // tsl.setTiming(TSL2591_INTEGRATIONTIME_500MS);
    // tsl.setTiming(TSL2591_INTEGRATIONTIME_600MS);  // longest integration time (dim light)

    /* Display the gain and integration time for reference sake */
    Serial.println(F("------------------------------------"));
    Serial.print  (F("Gain:         "));
    tsl2591Gain_t gain = tsl.getGain();
    switch(gain)
    {
      case TSL2591_GAIN_LOW:
        Serial.println(F("1x (Low)"));
        break;
      case TSL2591_GAIN_MED:
        Serial.println(F("25x (Medium)"));
        break;
      case TSL2591_GAIN_HIGH:
        Serial.println(F("428x (High)"));
        break;
      case TSL2591_GAIN_MAX:
        Serial.println(F("9876x (Max)"));
        break;
    }
    Serial.print  (F("Timing:       "));
    Serial.print((tsl.getTiming() + 1) * 100, DEC);
    Serial.println(F(" ms"));
    Serial.println(F("------------------------------------"));
    Serial.println(F(""));
}



void advancedReadTSL2591Mnits(void)
{
    // More advanced data read example. Read 32 bits with top 16 bits IR, bottom 16 bits full spectrum
    // That way you can do whatever math and comparisons you want!
    uint32_t lum = tsl.getFullLuminosity();
    uint16_t ir, full;
    ir = lum >> 16;
    full = lum & 0xFFFF;
    Serial.print(F("[ ")); Serial.print(millis()); Serial.print(F(" ms ] "));
    Serial.print(F("IR: ")); Serial.print(ir);  Serial.print(F("  "));
    Serial.print(F("Full: ")); Serial.print(full); Serial.print(F("  "));
    Serial.print(F("Visible: ")); Serial.print(full - ir); Serial.print(F("  "));
    Serial.print(F("Lux: ")); Serial.println(tsl.calculateLux(full, ir), 6);
}


/**************************************************************************/
/*
    Ends functions taken from:
    https://github.com/adafruit/Adafruit_TSL2591_Library/blob/master/examples/tsl2591/tsl2591.ino
*/
/**************************************************************************/


// // LIBRad ---------------------------------------

bool initializeLIBRADMints(){
    pinMode(LIBRADPin, INPUT);
    digitalWrite(LIBRADPin,HIGH);
    delay(1);
    return true;
  }

void countPulseLIBRADMints(){

      detachInterrupt(0);
      LIBRADCount++;
      while(digitalRead(LIBRADPin)==0){
      }
      attachInterrupt(0,countPulseLIBRADMints,FALLING);
}

void readLIBRADMints(uint8_t sampleTimeSeconds)  {

    LIBRADCount = 0;

    unsigned long sampleTimeMS = sampleTimeSeconds*1000;
    unsigned long startTime = millis();
    attachInterrupt(0,countPulseLIBRADMints,FALLING);
    while ((millis()-startTime) < sampleTimeMS) {
    }
    detachInterrupt(0);
    unsigned long timeSpent = millis()-startTime;

    float countPerMinute = (float(LIBRADCount)*float(60000))/float(timeSpent) ;
    float radiationValue = countPerMinute*CONV_FACTOR;
    String readings[4] = { String(countPerMinute,4), String(radiationValue,4), String(timeSpent),String(LIBRADCount)};
    sensorPrintMints("LIBRAD",readings,4);

}


