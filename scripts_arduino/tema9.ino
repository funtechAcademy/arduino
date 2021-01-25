// Fun Tech Academy 2020

// Incluimos la librer�a Servo.h
#include <Servo.h>

int pos = 0;
// Definimos la variable de tipo Servo
Servo servo_9;

void setup()
{
   // Definimos los par�metros del servo:
   // - pin: el n�mero del pin al que est� conectado el servo
   // - min (opcional): el ancho de pulso, en microsegundos, correspondiente al �ngulo m�nimo (0 grados) en el servo (predeterminado en 544)
   // - max (opcional): el ancho de pulso, en microsegundos, correspondiente al �ngulo m�ximo (180 grados) en el servo (predeterminado en 2400)
   servo_9.attach(9, 500, 2500);
}

void loop()
{
   // barre el servo de 0 a 180 grados en pasos
   // de 1 grados
   for (pos = 0; pos <= 180; pos += 1) 
   {
      // Le decimos al servo que vaya a la posici�n en la variable 'pos'
      servo_9.write(pos);
      // Espera 100 ms para que el servo alcance la posici�n
      delay(100);
   }
   for (pos = 180; pos >= 0; pos -= 1) 
   {
      // Le decimos al servo que vaya a la posici�n en la variable 'pos'
      servo_9.write(pos);
      // Espera 5 ms para que el servo alcance la posici�n
      delay(5); // Wait for 5 millisecond(s)
   }
}
