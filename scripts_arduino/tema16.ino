// Fun Tech Academy 2021

const int PinLED = 13;
const int PinLDR = A0;

void setup()
{
   pinMode(PinLED, OUTPUT); 
   pinMode(PinLDR, INPUT);
} 

void loop()
{
   int value = digitalRead(PinLDR);
   // Si hay luz, encendemos el LED de la placa
   if (value == HIGH)
   {
      digitalWrite(PinLED, HIGH);
      delay(50);
      digitalWrite(PinLED, LOW);
      delay(50);
   }
}