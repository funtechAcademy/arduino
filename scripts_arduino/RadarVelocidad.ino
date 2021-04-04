// Fun Tech Academy 2021
const int Echo = 3;     //Pin digital 3 para el Echo del sensor
const int Trigger = 2;  //Pin digital 2 para el Trigger del sensor

void setup() {
   Serial.begin(9600);  //iniciailzamos la comunicación
   pinMode(Echo, INPUT);      //pin Echo como entrada
   pinMode(Trigger, OUTPUT);  //pin Trigger como salida
   digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
}

void loop()
{
   float tiempo;         // Tiempo que tarda en llegar el eco
   float distancia_1;    // Distancia primera medida en cm
   float distancia_2;    // Distancia segunda medida en cm
   float velocidad;      // Velocidad en metros por segundo
   float tiempo_medida;  // Tiempo entre medidas en ms
   float distancia_recorrida_m; //distancia recorrida en metros
   distancia_1 = 100;    // Inicializamos para quede en bucle
   tiempo_medida = 400;  // Definimos el tiempo entre medidas

   // Leemos hasta que aparezca el objeto a medir
   while (distancia_1 > 20) 
   {
      // Calculamos la distancia 1
      digitalWrite(Trigger, HIGH);
      delayMicroseconds(10);        // Enviamos un pulso de 10us
      digitalWrite(Trigger, LOW);
      tiempo = pulseIn(Echo, HIGH); // Obtenemos el ancho del pulso
      distancia_1 = tiempo/59;      // Escalamos el tiempo a una distancia en cm
   }
 
   delay(tiempo_medida); // Hacemos una pausa para la segunda medición

   // Calculamos la distancia 2
   digitalWrite(Trigger, HIGH);
   delayMicroseconds(10);        // Enviamos un pulso de 10us
   digitalWrite(Trigger, LOW);
   tiempo = pulseIn(Echo, HIGH); // Obtenemos el ancho del pulso
   distancia_2 = tiempo/59.0;    // Escalamos el tiempo a una distancia en cm
  
   Serial.print("Distancia 1: ");
   Serial.print(distancia_1,4);
   Serial.print(" cm - Distancia 2: ");
   Serial.print(distancia_2,4);
   Serial.print(" cm");
   Serial.println();

   distancia_recorrida_m = (distancia_2 - distancia_1)/100.00;
   velocidad = distancia_recorrida_m / (tiempo_medida/1000.0);
  
   Serial.print("Distancia recorrida: ");
   Serial.print(distancia_recorrida_m,6);
   Serial.print(" m - Velocidad ");
   Serial.print(velocidad,6);
   Serial.print(" m/s");
   Serial.println();
   Serial.println();
  
   delay(10000); //Hacemos una pausa para volver a empezar
}
