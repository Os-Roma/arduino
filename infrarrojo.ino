#include <IRremote.h>
int receptor = 11;
int led1 = 13;
int led2 = 12;
int led3 = 10;
IRrecv irrecv(receptor);
decode_results codigo; 
 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // INICIA LA RECEPCIÓN
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}
 
void loop()
{
 if (irrecv.decode(&codigo))
 {
Serial.println(codigo.value, HEX);

      if (codigo.value==0xFF6897)//CÓDIGO DEL NÚMERO CERO PARA ACTIVAR Y DESACTIVAR LED 1
      {
         digitalWrite(led1, !digitaRead(led1));
      }

      if (codigo.value==0xFF30CF)//CÓDIGO DEL NÚMERO UNO PARA ACTIVAR Y DESACTIVAR LED 2
      {
         digitalWrite(led2, !digitaRead(led2));
      }

      if (codigo.value==0xFF3287)//CÓDIGO DEL NÚMERO UNO PARA ACTIVAR Y DESACTIVAR LED 3
      {
         digitalWrite(led3, !digitaRead(led3));
      }
    
delay(500);
irrecv.resume();

 }
}


