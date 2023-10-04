// Fun Tech Academy 2021

#include "IRremote.h"

int receptor = 11; // Pin donde concetaremos el receptor IR

/*-----( Declaración de Objetos )-----*/
IRrecv irrecv(receptor);     // Creamos una instancia de 'irrecv'
decode_results resultados;   // Creamos una instancia de 'decode_results'

void setup()
{
   Serial.begin(9600);
   Serial.println("Decodificación de botones del receptor IR"); 
   irrecv.enableIRIn(); // Encendemos el receptor
}


// Función que extrae la información de la estructura 'resultados'. Llamarla despues de 'IRrecv::decode()'
void traducirIR()
{
   Serial.print("(");
   Serial.print(resultados.bits, DEC);
   Serial.print(" bits)");
   
   // Evaluamos y mostramos de qué marca es el mando a distancia
   if (resultados.decode_type == UNKNOWN) {
      Serial.print("Unknown encoding: ");
   }
   else if (resultados.decode_type == NEC) {
      Serial.print("Decoded NEC: ");
   }
   else if (resultados.decode_type == SONY) {
      Serial.print("Decoded SONY: ");
   }
   else if (resultados.decode_type == RC5) {
      Serial.print("Decoded RC5: ");
   }
   else if (resultados.decode_type == RC6) {
      Serial.print("Decoded RC6: ");
   }
   else if (resultados.decode_type == PANASONIC) {
      Serial.print("Decoded PANASONIC - Address: ");
      Serial.print(resultados.address, HEX);
      Serial.print(" Value: ");
   }
   else if (resultados.decode_type == LG) {
      Serial.print("Decoded LG ");
   }
   else if (resultados.decode_type == JVC) {
      Serial.print("Decoded JVC ");
   }
   else if (resultados.decode_type == AIWA_RC_T501) {
      Serial.print("Decoded AIWA RC T501 ");
   }
   else if (resultados.decode_type == WHYNTER) {
      Serial.print("Decoded Whynter ");
   }

   // Mostramos los datos del botón pulsado
   Serial.print(resultados.value, HEX);
   Serial.print(" (HEX) , ");
   Serial.print(resultados.value, BIN);
   Serial.println(" (BIN)");
}

void loop()
{
   if (irrecv.decode(&resultados)) // ¿Hemos recibido una señal de IR?
   {
      traducirIR(); 
      irrecv.resume(); // Reseteamos el receptor para recibir la siguiente señal
   }  

  delay(300);
}
