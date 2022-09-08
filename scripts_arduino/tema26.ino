// Fun Tech Academy 2022

// Define el puerto del LED
int PinLed=13;

// Define el puerto del interruptor 
int PinInterruptor=2;

// Define la variable
int valor;

void setup()
{
   // Define el LED como un puerto de salida 
   pinMode(PinLed,OUTPUT);

   // Define el interruptor como un puerto de salida 
   pinMode(PinInterruptor,INPUT);
} 

void loop()
{
   // Lee el valor del Módulo Interruptor y la asigna a valor
   valor=digitalRead(PinInterruptor);

   // Cuando el interruptor tenga señal, el LED lucirá
   if(valor==HIGH)
   {
      digitalWrite (PinLed,LOW);
   }
   else
   {
      digitalWrite (PinLed,HIGH);
      delay(100);
   }
}