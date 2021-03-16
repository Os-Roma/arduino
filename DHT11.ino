#include <DHT_U.h>
#include <DHT.h>

DHT dht(PS, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  T = dht.readTemperature(); // Temperatura 
  H = dht.readHumidity();    //Humedad
}