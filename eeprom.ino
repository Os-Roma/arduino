#include <EEPROM.h>

// EEPROM.put(direccion,valor);
// EEPROM.read(0)

bool GT = false;

byte LE = EEPROM.read(0); // Hora de inicio de luz
byte LA = EEPROM.read(1); // Hora de fin de luz
byte AV = EEPROM.read(2); // Tiempo de actividad de ventiladores cada hora

byte PL = 4; // Pin relé luces
byte PV = 2; // Pin relé ventiladores

void setup() {
  Serial.begin(9600);
  pinMode(PL, OUTPUT);
  pinMode(PV, OUTPUT);
}

void loop() {
  guardarDatos();
  programas();
}


void guardarDatos(){
  if(GT == true){
    EEPROM.put(0,LE);
    EEPROM.put(1,LA);
    EEPROM.put(2,AV);
    GT = false;
  }
}

void programas(){
  //Horario de las luces
  if (f.hour() >= LE && f.hour() < LA ) {
    digitalWrite(PL, LOW);
  } else {
    digitalWrite(PL, HIGH);
  }
  
  //Horario de los ventiladores
  if (f.minute() >= 0 && f.minute() < AV ) {
    digitalWrite(PV, LOW);
  } else {
    digitalWrite(PV, HIGH);
  }

}