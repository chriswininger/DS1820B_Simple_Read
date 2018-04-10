/*
 * DS10820B_Simple_Read
 * Author: Chris Wininger
 * Descirption: Reads the temperature value reported by a DS1820B digital
 *  temperature probe, attached to port P1 of a JeeNode v6 and logs the data
 *  as json to the serial port
*/
#include <OneWire.h> 
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4

float temp1;
float temp2;
float temp3;
float temp4;

// setup to read sensor data on Port1 D
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(57600);
  Serial.println("Running");

  // initialize temperature sensor library
  sensors.begin(); 

}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures();
  temp1 = celsiusToFarenheit(sensors.getTempCByIndex(0));
  Serial.print("{\"temperature\": \"");
  Serial.print(temp1);
  Serial.print("\"}");
  Serial.println("");
  delay(1000);
}

float celsiusToFarenheit(float c) {
  return c * 1.8 + 32.0;  
}
