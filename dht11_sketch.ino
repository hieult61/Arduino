#include <Adafruit_Sensor.h>
#include <DHT.h>
#define dht_1 2
#define DHTTYPE DHT11
DHT dht(dht_1, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
delay (2000);
float h = dht.readHumidity();
float t= dht.readTemperature();

Serial.println("humidity=");
Serial.println(h);
Serial.println("temperature=");
Serial.println(t);
Serial.println("degree centigrade");

}
