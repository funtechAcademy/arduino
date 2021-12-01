// Fun Tech Academy 2021

#include <Stepper.h> // Incluimos la librería para controlar motores paso a paso

#define PASOS 512 // Definimos el número de pasos que necesita para dar una vuelta.

int Pin1 = 8;
int Pin2 = 9;
int Pin3 = 10;
int Pin4 = 11;
 
// Ponemos nombre al motor, el número de pasos y los pins de control
Stepper motor(PASOS, Pin1, Pin2, Pin3, Pin4);

 
int velocidad;         //Variable lectura potenciómetro
int pin_derecha = 3;   //Pulsador derecha
int pin_izquierda = 2; //Pulsador izquierda
int direccion;         //Variable para indicar la direccón

void setup()
{
   pinMode(pin_derecha,INPUT);
   pinMode(pin_izquierda,INPUT);
}
 
void loop()
{
   velocidad = analogRead(A0); //Lectura potenciómetro

   velocidad = map(velocidad, 0, 1023, 30, 150); //Establecemos la velocidad entre 30 y 150 rpm
 
   stepper.setSpeed(velocidad); //Indicamos la velocidad al motor
 
   stepper.step(direccion); //Indicamos la dirección al motor
 
   if(digitalRead(pin_izquierda)==HIGH)
   {
      direccion=200;  //Si pulsamos el pulsador izquierdo, el motor gira a la izquierda
   }
 
   if(digitalRead(pin_derecha)==HIGH)
   {
      direccion=-200;  //Si pulsamos el pulsador derecho, el motor gira a la derecha
   }

}
