// Fun Tech Academy 2021

int Pin_SER = 0;   // Pin SER (Serial Input)
int Pin_RCLK = 1;  // Pin RCLK (Register Clock/Latch)
int Pin_SRCLK = 2; // Pin SRCLK (Shift Register Clock)

byte leds = 0;     // Variable para mantener el patrón de los LED que están encendidos o apagados actualmente

void setup()
{
   // Configuramos todos los pines del 74HC595 como SALIDA
   pinMode(Pin_RCLK, OUTPUT);
   pinMode(Pin_SER, OUTPUT);
   pinMode(Pin_SRCLK, OUTPUT);
}

/*
   Esta función establece el Pin_RCLK en LOW, luego llama a la función 
   Arduino 'shiftOut' para desplazar el contenido de la variable 'leds' 
   en el registro de desplazamiento antes de volver a poner el 'Pin_RCLK' HIGH.
*/
void ActualizarRegistroTurnos()
{
   digitalWrite(Pin_RCLK, LOW);
   shiftOut(Pin_SER, Pin_SRCLK, LSBFIRST, leds);
   digitalWrite(Pin_RCLK, HIGH);
}

void loop()
{
   leds = 0;   // Inicialmente apaga todos los LED, dando a la variable 'leds' el valor 0
   ActualizarRegistroTurnos();
   delay(500);
   for (int i = 0; i < 8; i++) // Enciende todos los LED uno por uno.
   {
      bitSet(leds, i); // Establece el bit que controla ese LED en la variable 'leds'
      ActualizarRegistroTurnos();
      delay(500);
   }
}
