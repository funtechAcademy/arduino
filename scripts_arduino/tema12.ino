// Fun Tech Academy 2021

// Incluimos la librer�a del sensor
#include <dht_nonblocking.h>
// Definimos el tipo de sensor
#define TipoSensorDHT DHT_TYPE_11
// Definimos el pin del sensor
static const int PinSensorDHT = 2;
// Inicializamos el sensor con el pin y el tipo
DHT_nonblocking dht_sensor(PinSensorDHT, TipoSensorDHT);

void setup( )
{
   // Abrimos el puerto de Serie
   Serial.begin( 9600);
}

// Creamos una funci�n que nos permitir� medir la temperatura y la humedad cada cuatro segundos
// Devuelve False si no hay una medici�n disponible y True si se ha podido medir.
// En el caso de que devuelva verdadero, tambi�n devolver� las dos medidas
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

void loop( )
{
   float Temperatura;
   float Humedad;

   // Mide temperatura y humedad. Si la funci�n devuelve verdadero, entonces hay una medici�n disponible
   if( MedirVariables( &Temperatura, &Humedad ) == true )
   {
      Serial.print( "Temperatura = " );
      Serial.print( Temperatura, 1 );
      Serial.print( " grados, Humedad = " );
      Serial.print( Humedad, 1 );
      Serial.println( "%" );
   }
}
