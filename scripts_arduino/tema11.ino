// Fun Tech Academy 2021

/*
   LiquidCrystal Library - Hola Mundo

   Demuestra el uso de una pantalla LCD de 16x2. 
   La biblioteca de la pantalla LCD funciona con todas las 
   pantallas LCD que son compatibles con la Controlador 
   Hitachi HD44780 y que son de 16 pines.

   Este ejemplo imprime "¡Hola mundo!" en la pantalla LCD
   y muestra el tiempo desde que se enciende.

   Las conexiones:

   * Pin LCD RS a pin digital 12
   * Pin LCD Habilitar a pin digital 11
   * Pin LCD D4 a pin digital 5
   * Pin LCD D5 a pin digital 4
   * Pin LCD D6 a pin digital 3
   * Pin LCD D7 a pin digital 2
   * Pin LCD R/W a tierra
   * Pin LCD VSS a tierra
   * Pin LCD VCC pin a 5V
   * Resistencia de 10K
   * Termina a + 5V y tierra
   * Pontenciómetro al pin LCD VO (pin 3)
*/

// Incluimos el código de la librería:
#include <LiquidCrystal.h>

// Inicializamis la pantalla LCD con los pines de la interfaz
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
   // Configura el número de columnas y filas del LCD:
   lcd.begin(16, 2);
   // Imprime el mensaje "Hola Mundo!" en la pantalla LCD.
   lcd.print("Hola Mundo!");
}

void loop()
{
   // (la línea 0 es la primera fila)
   // (la línea 1 es la segunda fila)
   // Coloca el cursor en la columna 0, línea 1
   lcd.setCursor(0, 1);
   // imprime el número de segundos desde el reinicio:
   lcd.print(millis()/100);
}
