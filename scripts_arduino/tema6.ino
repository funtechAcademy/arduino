// Fun Tech Academy 2020

int melodia[] = 
{
   NOTA_C5, 
   NOTA_D5, 
   NOTA_E5, 
   NOTA_F5, 
   NOTA_G5, 
   NOTA_A5, 
   NOTA_B5, 
   NOTA_C6
};

int duracion = 500; // 500 milisegundos
 
void setup() 
{
   // No necesitamos asignar nada pero hay que declarar la función
}
 
void loop() 
{  
   for (int TocarNota = 0; TocarNota < 8; TocarNota++) 
   {
      // El Pin 8 emite el sonido. Cada escala es de 0,5 segundos
      tone(8, melodia[TocarNota], duracion);
     
      // Tiempo de espera entre nota y nota
      delay(1000);
   }
   
   // A los dos segundos volvemos a emitir las notas
   delay(2000);
}