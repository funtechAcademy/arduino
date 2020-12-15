// Fun Tech Academy 2020

// Definimos los pines del sensor y el led
#define SENSOR_PIN 2
#define LED_PIN 13

void setup()
{
   // Asignamos los sensores a sus pines correspondientes
   pinMode(SENSOR_PIN, INPUT_PULLUP);
   pinMode(LED_PIN, OUTPUT);
}

void loop()
{
   // Dependiendo del valor del sensor de inclinacon, encendemos o apagamos el LED
   if (digitalRead(SENSOR_PIN) == LOW)
   {
      digitalWrite(LED_PIN, HIGH);
   }
   else
   {
      digitalWrite(LED_PIN, LOW);
   }
}
