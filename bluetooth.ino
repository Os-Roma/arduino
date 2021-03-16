#include <SoftwareSerial.h>

#include <RTClib.h>

RTC_DS3231 rtc;
SoftwareSerial BT(10,11); // Establece los puertos de transmicion de datos bluetooth 10 TX, 11 RX.
char DATO = ' ';
int now;
const int led = 13;
// char nombreBT[10] = "Dispositivo";
// char velocidad = '4'; // 960
// char pin[5] = "1234";

int segundo = 0;
DateTime f;

void setup() {
  Serial.begin(9600);
  // pinMode(led, OUTPUT);

  // Serial.print("AT");
  // delay(1000);

  // Serial.print("AT+NAME");
  // Serial.print(nombreBT);
  // delay(1000);

  // Serial.print("AT+BAUD");
  // Serial.print(velocidad);
  // delay(1000);

  // Serial.print("AT+PIN");
  // Serial.print(pin);
  // delay(1000);

  // digitalWrite(led, HIGH);

  if(!rtc.begin()){
    Serial.println("Módulo RTC no encontrado !");
    while(1);
  }
  // Activar linea cuando conecta el módulo RTC por primera vez
  // rtc.adjust(DateTime(__DATE__, __TIME__));
  BT.begin(9600);
}

void loop() {

  f = rtc.now();   // Fecha y hora

  if(BT.available()){
      DATO = BT.read();
      Serial.print(DATO);
      // ON/OFF
      if(DATO == 'A'){
          // digital.write(led, !digitalRead(led));
      }
  }
  enviarDatos();
}

void enviarDatos(){
  if( f.second() != segundo ){
     
    BT.print("Di");
    if (f.day() < 10) { BT.print("0"); }
    BT.print(f.day()); BT.print(" / ");
    if (f.month() < 10) { BT.print("0"); }
    BT.print(f.month()); BT.print(" / ");
    BT.println(f.year()); delay(50);

    BT.print("Hr");
    if (f.hour() < 10) { BT.print("0"); }
    BT.print(f.hour()); BT.print(":");
    if (f.minute() < 10) { BT.print("0"); }
    BT.println(f.minute()); delay(50);
    
    segundo = f.second();
  }
}
