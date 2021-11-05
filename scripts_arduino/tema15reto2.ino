// Fun Tech Academy 2021

#include "IRremote.h"

int receptor = 11; // Pin donde concetaremos el receptor IR
int pin_led1 = 4;  // Pin donde concetaremos el LED del botón 1
int pin_led2 = 5;  // Pin donde concetaremos el LED del botón 2
int pin_led3 = 6;  // Pin donde concetaremos el LED del botón 3
int pin_led4 = 7;  // Pin donde concetaremos el LED del botón 4

/*-----( Declaración de Objetos )-----*/
IRrecv irrecv(receptor);     // Creamos una instancia de 'irrecv'
decode_results resultados;   // Creamos una instancia de 'decode_results'

void setup()
{
   Serial.begin(9600);
   Serial.println("Decodificación de botones del receptor IR"); 
   pinMode(pin_led1, OUTPUT);
   pinMode(pin_led2, OUTPUT);
   pinMode(pin_led3, OUTPUT);
   pinMode(pin_led4, OUTPUT);
   irrecv.enableIRIn(); // Encendemos el receptor
}

void loop()
{
   if (irrecv.decode(resultados)) // ¿Hemos recibido una señal de IR?
   {
      switch(resultados.value)
      {
         case 0x00FF629D: Serial.println("Tecla: Arriba"); 
                          break;
         case 0x00FF22DD: Serial.println("Tecla: Izquierda");    
                          break;
         case 0x00FF02FD: Serial.println("Tecla: OK");    
                          break;
         case 0x00FFC23D: Serial.println("Tecla: Derecha");   
                          break;
         case 0x00FFA857: Serial.println("Tecla: Abajo"); 
                          break;
         case 0x00FF6897: Serial.println("Tecla: 1");    
                          digitalWrite(pin_led1, !digitalRead(pin_led1));
                          break;
         case 0x00FF9867: Serial.println("Tecla: 2");    
                          digitalWrite(pin_led2, !digitalRead(pin_led2));
                          break;
         case 0x0FFB04F:  Serial.println("Tecla: 3");    
                          digitalWrite(pin_led3, !digitalRead(pin_led3));
                          break;
         case 0x00FF30CF: Serial.println("Tecla: 4");
                          digitalWrite(pin_led4, !digitalRead(pin_led4));
                          break;
         case 0x00FF18E7: Serial.println("Tecla: 5");
                          break;
         case 0x00FF7A85: Serial.println("Tecla: 6");
                          break;
         case 0x00FF10EF: Serial.println("Tecla: 7");
                          break; 
         case 0x00FF38C7: Serial.println("Tecla: 8");    
                          break;
         case 0x00FF5AA5: Serial.println("Tecla: 9");    
                          break;
         case 0x00FF42BD: Serial.println("Tecla: *");    
                          break;
         case 0x00FF4AB5: Serial.println("Tecla: 0");    
                          break;
         case 0x00FF52AD: Serial.println("Tecla: #");    
                          break;
      }

      irrecv.resume(); // Reseteamos el receptor para recibir la siguiente señal
   }  

   delay(300);
}
