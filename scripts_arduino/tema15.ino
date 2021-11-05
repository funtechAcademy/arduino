// Fun Tech Academy 2021

#include "IRremote.h"

int pin_receptor = 11; // Pin donde concetaremos el receptor IR
int pin_led = 13;      // Pin donde concetaremos el LED

/*-----( Declaración de Objetos )-----*/
IRrecv irrecv(pin_receptor);     // Creamos una instancia de 'irrecv'
decode_results resultados;       // Creamos una instancia de 'decode_results'

void setup()
{
   irrecv.enableIRIn(); // Encendemos el receptor de IR
   pinMode(pin_led, OUTPUT);
}

void loop()
{
   if (irrecv.decode(&resultados)) // ¿Hemos recibido una señal de IR?
   {
      // Dato recibido, encendemos y apagamos el LED
      digitalWrite(pin_led, HIGH); 
      delay(300);
      digitalWrite(pin_led, LOW); 
      irrecv.resume(); // Reseteamos el receptor para recibir la siguiente señal
   }  
}