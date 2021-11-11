// Fun Tech Academy 2021

/* 
   Carga y descarga de un condensador. 
   Para el ejemplo:
      Condensador de 220 microfaradios (F)
      Resistencia de carga 1 kOhm
      Resistencia de descarga 470 Ohm
*/

#define cargar 13
#define descargar 11
#define medir 0 
unsigned long tiempo_inicio;   // tiempo inicio lecturas
unsigned int valor_condensador;

void setup () 
{
   pinMode(cargar, OUTPUT );    // pin de carga  
   pinMode(descargar, OUTPUT ); // pin de descarga auxiliar
   Serial.begin(9600);
}

void loop(){
   /* Descarga capacitor */ 
   digitalWrite(cargar, LOW );
   pinMode(descargar, OUTPUT );               
   digitalWrite(descargar, LOW );          

   tiempo_inicio = micros();                 // tiempo inicial
   valor_condensador = analogRead(medir);
   while (valor_condensador > 0) 
   {
      Serial.print(micros() - tiempo_inicio); // tiempo transcurrido 
      Serial.print ( "," );
      Serial.println(valor_condensador) ;
      valor_condensador = analogRead(medir);
   }
  
   /* carga capacitor */ 
   digitalWrite (cargar, HIGH ); 
   pinMode(descargar, INPUT );       // pin auxiliar con alta impedancia
   tiempo_inicio = micros ();        // tiempo inicial 
   valor_condensador = analogRead(medir); 
   while (valor_condensador < 1016)
   {         // valor maximo de carga de 1024 
      Serial.print(micros() - tiempo_inicio);
      Serial.print ( "," );
      Serial.println (valor_condensador);
      valor_condensador = analogRead(medir);
   }
}
