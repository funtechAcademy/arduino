// Fun Tech Academy 2021

int ladoy = A0;         // Entrada de referencia para el eje de las Y's.
int ladox = A1;         // Entrada de referencia para el eje de las X's.
int ledarriba = 13;     // Variable entera para LED de la parte de arriba.
int ledabajo = 12;      // Variable entera para LED de la parte de abajo.
int ledizquierda = 10;  // Variable entera para LED de la parte de izquierda.
int ledderecha = 11;    // Variable entera para LED de la parte de derecha.

int valorx;             // Variable para la lectura de la posición x
int valory;             // Variable para la lectura de la posición y

void setup() 
{
   // Declaramos los LEDS como salidas
   pinMode(ledarriba, OUTPUT);
   pinMode(ledabajo, OUTPUT);
   pinMode(ledizquierda, OUTPUT);
   pinMode(ledderecha, OUTPUT);
}
 
void loop()
{
   // Obtendremos continuamente el valor x en el que se encuentra posicionado así asignaremos una acción para una posición deseada.
   valorx = analogRead(ladox);

   if (valorx > 700)
   {
      digitalWrite(ledderecha,HIGH); 
   }
   else
   {
      digitalWrite(ledderecha, LOW );
   }
   if (valorx < 400)
   {
      digitalWrite(ledizquierda,HIGH);
   }
   else
   {
      digitalWrite(ledizquierda, LOW );
   }

   // Obtendremos continuamente el valor y en el que se encuentra posicionado así asignaremos una acción para una posición deseada.
   valory = analogRead(ladoy);

   if (valory > 700)
   {
      digitalWrite(ledarriba,HIGH);
   }
   else
   {
      digitalWrite(ledarriba, LOW );
   }
   if (valory < 400)
   {
      digitalWrite(ledabajo,HIGH);
   }
   else
   {
      digitalWrite(ledabajo, LOW );
   }
}