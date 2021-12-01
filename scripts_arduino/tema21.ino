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
   leds = 0; // Inicialmente apaga todos los LED, dando a la variable 'leds' el valor 0
   ActualizarRegistroTurnos();

   Serial.begin(9600);
   while (! Serial); // Espera hasta que metamos un número
   {
      Serial.println("Introduce el LED que quieres encender o 'x' para apagar");
   }
}

void ActualizarRegistroTurnos()
{
   digitalWrite(Pin_RCLK, LOW);
   shiftOut(Pin_SER, Pin_SRCLK, LSBFIRST, leds);
   digitalWrite(Pin_RCLK, HIGH);
}

void loop()
{
   if (Serial.available()) // Evaluamos si tenemos algo que leer en el monitor de serie
   {
      char ch = Serial.read(); // Leemos los datos del monitor de serie
      if (ch >= '0' && ch <= '7') // Evaluamos si hemos introducido un número del 0 al 7
      {
         int led = ch - '0'; 
         bitSet(leds, led);
         ActualizarRegistroTurnos();
         Serial.print("Encendemos el LED ");
         Serial.println(led);
      }
      if (ch == 'x')
      {
         leds = 0;
         ActualizarRegistroTurnos();
         Serial.println("Apagados");
      }
   }
}
