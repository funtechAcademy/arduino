// Fun Tech Academy 2020

int duracion = 500; // 500 milisegundos
long nota; // Nota generada por la salida del potenci�metro
int PinZumbador = 10;//Pin del Zumbador Activo

void setup() 
{
   //Inicializamos la comunicaci�n serial
   Serial.begin(9600); 
   //Escribimos por el monitor serie mensaje de inicio
   Serial.println("Valores del potenciometro");
}
 
void loop() 
{  
  // Leemos la nota que va a sonar del Potenci�metro
  nota = analogRead(A0);
  tone(PinZumbador, nota, duracion);
  Serial.print("La Nota es = ");
  Serial.println(nota);
}