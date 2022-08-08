// Fun Tech Academy 2022

int pin_laser = 13;

void setup() 
{
   pinMode(pin_laser, OUTPUT);  // Definir pin_laser como salida
}
 
void loop()
{
   digitalWrite(pin_laser, HIGH);   // poner el pin_laser en HIGH
   delay(5000);                     // esperar 5 segundos
   digitalWrite(pin_laser, LOW);    // poner el pin_laser en LOW
   delay(20000);                    // esperar 20 segundos
}
