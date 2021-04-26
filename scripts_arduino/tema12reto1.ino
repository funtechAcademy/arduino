// Fun Tech Academy 2021

// Incluimos la librería del sensor
#include <dht_nonblocking.h>
// Definimos el tipo de sensor
#define TipoSensorDHT DHT_TYPE_11

// Definimos el pin del sensor y zumbador
static const int PinSensorDHT = 2;
int zumbador = 12;

// Creamos las variables globales
float TemperaturaInicial;
float HumedadInicial;
float TemperaturaFinal;
float HumedadFinal;
int i;

// Inicializamos el sensor con el pin y el tipo
DHT_nonblocking dht_sensor(PinSensorDHT, TipoSensorDHT);

// Creamos una función que nos permitirá medir la temperatura y la humedad cada cuatro segundos
// Devuelve False si no hay una medición disponible y True si se ha podido medir.
// En el caso de que devuelva verdadero, también devolverá las dos medidas
static bool MedirVariables( float *Temperatura, float *Humedad )
{
   static unsigned long TiempoMedida = millis( );

   // Medimos cada 4 segundos
   if( millis( ) - TiempoMedida > 3000ul )
   {
      if( dht_sensor.measure( Temperatura, Humedad ) == true )
      {
         TiempoMedida = millis( );
         return( true );
      }
   }

   return( false );
}

void setup( )
{
   // Inicializamos el pin del zumbador como salida
    pinMode(zumbador,OUTPUT);

   // Abrimos el puerto de Serie
   Serial.begin( 9600);

   // Recogemos la temperatura inicial de la habitación
   do
   {
      if( MedirVariables( &TemperaturaInicial, &HumedadInicial ) == true )
      {
         Serial.print( "INICIAL: Temperatura = " );
         Serial.print( TemperaturaInicial, 1 );
         Serial.print( " grados, Humedad = " );
         Serial.print( HumedadInicial, 1 );
         Serial.println( "%" );
      }
   } while (MedirVariables == true);
}


void loop( )
{
   float Temperatura;
   float Humedad;

   // Mide temperatura y humedad. Si la función devuelve verdadero, entonces hay una medición disponible
   if( MedirVariables( &TemperaturaFinal, &HumedadFinal ) == true )
   {
      Serial.print( "Temperatura = " );
      Serial.print( TemperaturaFinal, 1 );
      Serial.print( " grados, Humedad = " );
      Serial.print( HumedadFinal, 1 );
      Serial.println( "%" );
      if( Temperatura > (TemperaturaInicial+1) )
      {
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
            delay(1000); // Esperamos 1 segundo
         }
      }
   }
}
