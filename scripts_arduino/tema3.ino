// Fun Tech Academy 2020

// Definimos los pins
#define PinRojo 6    // Red
#define PinVerde 5   // Green
#define PinAzul 3    // Blue

void setup()
{
   pinMode(PinRojo, OUTPUT);
   pinMode(PinVerde, OUTPUT);
   pinMode(PinAzul, OUTPUT);
   digitalWrite(PinRojo, HIGH);
   digitalWrite(PinVerde, LOW);
   digitalWrite(PinAzul, LOW);
}

// Se definen las variables
int ValorRojo;
int ValorVerde;
int ValorAzul;
int TiempoEspera = 10;

#define TiempoEspera 10 // Tiempo de desvanecimiento entre colores

void loop()
{
   ValorRojo = 255; // Elegimos un valor entre 1 y 255
   ValorVerde = 0;
   ValorAzul = 0;

   for(int i = 0; i < 255; i += 1) // Se desvanece el rojo y aparece el verde completo cuando i = 255
   {
      ValorRojo -= 1;
      ValorVerde += 1;
      analogWrite(PinRojo, ValorRojo);
      analogWrite(PinVerde, ValorVerde);
      delay(TiempoEspera);
   }
}