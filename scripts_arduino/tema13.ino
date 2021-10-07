// Fun Tech Academy 2021

int lectura = 0;          // Variable para la lectura del sensor
int pin_temperatura = A0; // Pin del sensor de temperatura
int pin_led = 10;          // Pin del LED
float voltaje;            // Variable con decimales para el cálculo del voltaje devuelto
float temperatura = 0.0;  // Variable con decimales para el cálculo de la temperatura
int temp_maxima = 25;     // Variable para la temperatura máxima a controlar

void setup()
{
   Serial.begin(9600); //Iniciamos la comunicación serial
}

void loop()
{
   // Tomamos la lectura analógica del sensor
   lectura = analogRead(pin_temperatura);

   // Obtenemos el voltaje en base a la lectura del sensor
   voltaje = lectura * 0.004882814;

   // Obtenemos la temperatura en ºC en base al voltaje
   temperatura = (voltaje - 0.5) * 100.0;

   // Imprimimos por monitor serie la temperatura en grados celcius
   Serial.println(temperatura);

   // Si la temperatura supera la temperatura máxima, encendemos el LED
   if (temperatura >= temp_maxima)
   {
      digitalWrite(pin_led, HIGH);
   }
   else
   {
      digitalWrite(pin_led, LOW);
   }
  delay(1000);
}
