// Fun Tech Academy 2021

int Pin_SER = 3;   // Pin SER (Serial Input)
int Pin_RCLK = 4;  // Pin RCLK (Register Clock/Latch)
int Pin_SRCLK = 2; // Pin SRCLK (Shift Register Clock)

byte leds = 0;     // Variable para mantener el patrón de los LED que están encendidos o apagados actualmente

void setup()
{
   // Configuramos todos los pines del 74HC595 como SALIDA
   pinMode(Pin_RCLK, OUTPUT);
   pinMode(Pin_SER, OUTPUT);
   pinMode(Pin_SRCLK, OUTPUT);
   leds = 0; // Inicialmente apaga todos los segmentos
   ActualizarRegistroTurnos();
}

void ActualizarRegistroTurnos()
{
   digitalWrite(Pin_RCLK, LOW);
   shiftOut(Pin_SER, Pin_SRCLK, LSBFIRST, leds);
   digitalWrite(Pin_RCLK, HIGH);
}

void EscribeNumero(int pin_0, int pin_1, int pin_2, int pin_4, int pin_5, int pin_6, int pin_7)
{
   int led;
   if (pin_0 == 1)
   {
      led = 0;
      bitSet(leds, led);
   }
   if (pin_1 == 1)
   {
      led = 1;
      bitSet(leds, led);
   }
   if (pin_2 == 1)
   {
      led = 2;
      bitSet(leds, led);
   }
   if (pin_4 == 1)
   {
      led = 4;
      bitSet(leds, led);
   }
   if (pin_5 == 1)
   {
      led = 5;
      bitSet(leds, led);
   }
   if (pin_6 == 1)
   {
      led = 6;
      bitSet(leds, led);
   }
   if (pin_7 == 1)
   {
      led = 7;
      bitSet(leds, led);
   }
   bitSet(leds, led);
   ActualizarRegistroTurnos();
}

void loop()
{

   // Escribimos el 1
   EscribeNumero(0,0,1,1,0,0,0);

   delay (1000);
  
   leds = 0; // Apagamos todos los segmentos
   ActualizarRegistroTurnos();

   // Escribimos el 2
   EscribeNumero(0,1,1,0,1,1,1);

   delay (1000);
  
   leds = 0; // Apagamos todos los segmentos
   ActualizarRegistroTurnos();

   // Escribimos el 3
   EscribeNumero(0,1,1,1,1,0,1);
  
   delay (1000);
  
   leds = 0; // Apagamos todos los segmentos
   ActualizarRegistroTurnos();

   // Escribimos el 4
   EscribeNumero(1,0,1,1,0,0,1);
  
   delay (1000);

   leds = 0; // Apagamos todos los segmentos
   ActualizarRegistroTurnos();

   // Escribimos el 5
   EscribeNumero(1,1,0,1,1,0,1);
  
   delay (1000);
  
   leds = 0; // Apagamos todos los segmentos
   ActualizarRegistroTurnos();

   // Escribimos el 6
   EscribeNumero(1,1,0,1,1,1,1);
  
   delay (1000);

   leds = 0; // Apagamos todos los segmentos
   ActualizarRegistroTurnos();

   // Escribimos el 7
   EscribeNumero(0,1,1,1,0,0,0);
  
   delay (1000);

   leds = 0; // Apagamos todos los segmentos
   ActualizarRegistroTurnos();

   // Escribimos el 8
   EscribeNumero(1,1,1,1,1,1,1);
  
   delay (1000);

   leds = 0; // Apagamos todos los segmentos
   ActualizarRegistroTurnos();

   // Escribimos el 9
   EscribeNumero(1,1,1,1,1,0,1);
  
   delay (1000);

   leds = 0; // Apagamos todos los segmentos
   ActualizarRegistroTurnos();

   // Escribimos el 0
   EscribeNumero(1,1,1,1,1,1,0);
  
   delay (1000);

   leds = 0; // Apagamos todos los segmentos
   ActualizarRegistroTurnos();

}