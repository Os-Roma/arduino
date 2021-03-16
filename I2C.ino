#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // Establece las dimenciones del display
#include <RTClib.h>

RTC_DS3231 rtc;

DateTime f;

void setup() {
  Serial.begin(9600);
  if(!rtc.begin()){
    Serial.println("Módulo RTC no encontrado !");
    while(1);
  }
  // Activar linea cuando conecta el módulo RTC por primera vez
  // rtc.adjust(DateTime(__DATE__, __TIME__));
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 1);
  lcd.print("Creative!");
  delay(4000);
  lcd.clear();
}

void loop() {


  f = rtc.now();   // Fecha y hora

  // Marca la hora
  lcd.setCursor(11, 1);
  if (f.hour() <= 9) {
    lcd.print("0");
    lcd.setCursor(12, 1);
  }
  lcd.print(f.hour());
  lcd.setCursor(13, 1);
  if (f.second() % 2 == 0 ) {
    lcd.print(" ");
  } else {
    lcd.print(":");
  }
  lcd.setCursor(14, 1);
  if (f.minute() <= 9) {
    lcd.print("0");
    lcd.setCursor(15, 1);
  }
  lcd.print(f.minute());
}
