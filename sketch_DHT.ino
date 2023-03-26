#include <dht.h> // Loads library for operating DHT sensors
#define dataPin 8 // Defines pin number to which the sensor is connected
dht DHT; // Creats a DHT object

const long interval = 1000;  // interval at which to send data (milliseconds)
unsigned long previousMillis = 0;  // will store last time data were sent

void setup() 
{
	Serial.begin(9600);
}

void loop() 
{
	//Uncomment whatever type you're using
	int readData = DHT.read22(dataPin); // DHT22/AM2302
	////int readData = DHT.read11(dataPin); // DHT11
  
  //Define name od station and name of sensor based you're using
  unsigned long currentMillis = millis();
  char sens[] = "ArduinoZuzaDHT22";
  char loc[] = "Brussels";

	float temp = DHT.temperature; // Gets the values of the temperature
	float hum = DHT.humidity; // Gets the values of the humidity

  if (currentMillis - previousMillis >= interval) {

  // save the last time data were sent
    previousMillis = currentMillis;

	// Printing the results on the serial monitor
  Serial.print("{\"Sensor\":\"");
  Serial.print(sens);
  Serial.print("\",\"Location\":\"");
  Serial.print(loc);
  Serial.print("\",\"Temperature\":");
	Serial.print(temp);
  Serial.print(",\"Humidity\":");
	Serial.print(hum);
  Serial.println("}");
  }
}