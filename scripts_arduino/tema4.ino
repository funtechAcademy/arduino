int PinLed = 5;
int PinBotonA = 9;
int PinBotonB = 8;

void setup() 
{
  pinMode(PinLed, OUTPUT);
  pinMode(PinBotonA, INPUT_PULLUP);  
  pinMode(PinBotonB, INPUT_PULLUP);  
}

void loop() 
{
  if (digitalRead(PinBotonA) == LOW)
  {
    digitalWrite(PinLed, HIGH);
  }
  if (digitalRead(PinBotonB) == LOW)
  {
    digitalWrite(PinLed, LOW);
  }
}