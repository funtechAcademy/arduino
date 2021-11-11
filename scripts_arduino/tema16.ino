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
   int valorLDR = digitalRead(PinLDR);
   // Si estamos a oscuras, encendemos el LED de la placa
   if (valorLDR == HIGH)
   {
      digitalWrite(PinLED, HIGH);
      delay(50);
   }
   else
   {
      digitalWrite(PinLED, LOW);
      delay(50);
   }
}