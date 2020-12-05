// Fun Tech Academy 2020

int zumbador = 12;//Pin del Zumbador Activo

void setup()
{
   // Inicializamos el pin del zumbador como salida
    pinMode(zumbador,OUTPUT);
}

void loop()
{
   unsigned char i;
   while(1)
   {
      // Generamos una frecuencia
      for(i=0;i<80;i++)
      {
         digitalWrite(zumbador,HIGH);
         delay(1); // Esperamos 1 milisegundo
         digitalWrite(zumbador,LOW);
         delay(1); // Esperamos 1 milisegundo
      }
      // Generamos otra frecuencia
      for(i=0;i<100;i++)
      {
         digitalWrite(zumbador,HIGH);
         delay(2); // Esperamos 2 milisegundos
         digitalWrite(zumbador,LOW);
         delay(2); // Esperamos 2 milisegundos
      }
   }
}
