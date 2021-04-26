// FUN TECH ACADEMY 2021

// Incluimos la librería del sensor ultrasónico SR04
#include "SR04.h"

#define PIN_ENVIO 12
#define PIN_ECO 11

// Creamos una variable de tipo SR04 
// y definimos sus pines de envío y de eco
SR04 sr04 = SR04(PIN_ECO,PIN_ENVIO);
long distancia;

void setup() 
{
   Serial.begin(9600);
   delay(1000);
}

void loop() 
{
   // Recogemos la distancia devuelta por el sensor
   distancia=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   delay(1000);
}