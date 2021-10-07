// Fun Tech Academy 2021

int ladoy = A0;         // Entrada de referencia para el eje de las Y's.
int ladox = A1;         // Entrada de referencia para el eje de las X's.

int valorx;             // Variable para la lectura de la posición x
int valory;             // Variable para la lectura de la posición y

void setup() 
{
   // Abrimos el puerto de Serie
   Serial.begin( 9600);
}
 
void loop()
{
   // Obtendremos los valores x e y en el que se encuentra posicionado.
   valorx = analogRead(ladox);
   valory = analogRead(ladoy);

   Serial.print("Posición x = ");
   Serial.print(valorx);
   Serial.print(" Posición y = ");
   Serial.print(valory);
   Serial.print("\n");

  delay(1000);
}