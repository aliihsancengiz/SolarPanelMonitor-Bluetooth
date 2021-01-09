#include <Arduino.h>

// User Defined Headers
#include <bt_hc05.h>
#include <MobilAppProtocol.h>
#include <Measurement.h>
#include <MovingAverageFilter.h>
#include "DHT.h"

#define DHTPIN 2    
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

bt_hc05 bt_handler;
MobileAppProtocolWrapper protocolWrapper;
Measurement measurement_handler;
Measurement_t valuesUnfiltered,valuesFiltered;
Filter movingAverageHandler;


void setup()
{
  bt_handler.init(9600);
  dht.begin(); 
}
void loop()
{
  // Take 100 samples in a second
  delay(10);

  // Get values
  valuesUnfiltered=measurement_handler.getData();
  valuesUnfiltered.temprature=dht.readTemperature(); // 
  valuesUnfiltered.humudity=dht.readHumidity();
  
  // Push values into filter Object
  movingAverageHandler.push_measurementValue(valuesUnfiltered);
  
  //Get New Sample
  valuesFiltered=movingAverageHandler.getSample();
  
  // Send it to Bluetooth
  bt_handler.write_bt(protocolWrapper.getSerializedString(valuesFiltered.voltage,valuesFiltered.temprature,valuesFiltered.humudity));
 
}