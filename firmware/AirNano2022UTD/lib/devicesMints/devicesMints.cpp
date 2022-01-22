
#include "devicesMints.h"

// BME280  ---------------------------------------
//
bool initializeBME280Mints(){
      if (bme280.init()) {
        Serial.println("BME280 Initiated");
        delay(1);
        return true;
      }
      else
      {
      Serial.println("BME280 not found");
      delay(1);

      return false;
      }

}

void readBME280Mints(){

  float temperature    = bme280.getTemperature();
  float pressure       = bme280.getPressure();
  float humidity       = bme280.getHumidity();
  float altitude       = bme280.calcAltitude(pressure);

  String readings[4] = { String(temperature,2) , String(pressure,2), String(humidity,2) , String(altitude,2) };
  sensorPrintMints("BME280",readings,4);
}


// BME680 ---------------------------------------
bool initializeBME680Mints(){
  if (bme680.init()) {
    Serial.println("BME680 Initiated");
    delay(1);
    return true;
  }else{
    Serial.println("BME680 not found");
    delay(1);
    return false;
  }

}

void readBME680Mints(){
  if (!bme680.read_sensor_data()) {
    String readings[4] = { String(bme680.sensor_result_value.temperature), 
                           String(bme680.sensor_result_value.pressure / 1000.0) ,
                           String(bme680.sensor_result_value.humidity) ,
                           String(bme680.sensor_result_value.gas / 1000.0),
                           };
  
  sensorPrintMints("BME680",readings,4);
  }


}



// SCD30 ---------------------------------------
bool initializeSCD30Mints(){
  if (scd.begin()) {
    Serial.println("SCD30 Initiated");
    delay(1);
    return true;
  }else{
    Serial.println("SCD30 not found");
    delay(1);
    return false;
  }

  delay(2000);
}

void readSCD30Mints(){
  String readings[3] = { String(scd.getCO2()), String(scd.getTemperature()) , String(scd.getHumidity()) };
  sensorPrintMints("SCD30",readings,3);
}


