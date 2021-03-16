#include <RTClib.h>

RTC_DS3231 rtc;

DateTime f;


void setup() {
  Serial.begin(9600);
  if(!rtc.begin()){
     Serial.println("Módulo RTC no encontrado !");
    while(1);
  }
  rtc.adjust(DateTime(__DATE__, __TIME__));
}

void loop() {
  f = rtc.now();   // Fecha y hora
  println(f);
}
