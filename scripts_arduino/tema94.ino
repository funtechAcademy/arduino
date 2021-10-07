// Fun Tech Academy 2021

#include <Stepper.h> // Incluimos la librería para controlar motores paso a paso
 
int Pin1 = 8;
int Pin2 = 9;
int Pin3 = 10;
int Pin4 = 11;

#define PASOS 512 // Definimos el número de pasos que necesita para dar una vuelta.
 
// Ponemos nombre al motor, el número de pasos y los pins de control
Stepper motor(PASOS, Pin1, Pin2, Pin3, Pin4);
 
void setup()
{
  // Velocidad del motor en RPM
  motor.setSpeed(25);
}
 
void loop()
{
  //Girar una vuelta entera en un sentido
  motor.step(200);
  delay(500); //Pequeña pausa
 
  //Girar una vuelta entera en sentido contrario
  motor.step(-200);
  delay(500); //Pequeña pausa
}
