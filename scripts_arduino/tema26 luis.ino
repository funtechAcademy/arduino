
/* 
 *  Prueba de Servidor Web con el ESP8266.
 * 
 * Se conecta mediante wifi al router.
 * Se crea un el objeto servidor para escuchar en elpuerto 80 (*). 
 *   (*)Para acceder desde internet, es necesario hacer fordwarding en puerto 80 en el router.
 * En el loop se comprueba si se ha coenctado algun cliente, para responder al request. 
 * 
 * Para probarlo, desde cualquier navegador se puede acceder a 192.168.0.111
 * y se mostrará la web de prueba con el texto:
 *      "Ejemplo de servidor web. Se ha recibido: GET / HTTP/1.1"
 */
#include <ESP8266WiFi.h>

char ssid[] = "LRWIFI";
char pass[] = "caparracaparra";
IPAddress ip (192,168,0,111);   // ip fija
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);

WiFiServer server(80); //crea un server que escucha la conexiones en el puerto especificado


void conexion()
{
  WiFi.mode(WIFI_STA);            // tiene tres modos AP (Access Point), STA (Station), AP+STA 
  WiFi.config(ip,gateway,subnet); // asignamos una IP fija 
  WiFi.begin(ssid, pass);
  
  while (WiFi.status() != WL_CONNECTED) 
    delay(10);

  // mostramos datos de la conexión
  Serial.print("SSID:          ");  Serial.println(WiFi.SSID());
  Serial.print("LocalIP:       ");  Serial.println(WiFi.localIP());
  Serial.print("Potencia RSSI: ");  Serial.print(WiFi.RSSI());  Serial.println(" dBm"); 

  server.begin();
}

void setup() 
{
  Serial.begin(9600);  Serial.println("");
  conexion();
}

void loop() 
{
  // Chequear si el cliente se ha conectado
  WiFiClient client = server.available();
  if (!client) 
    return;
  
  // leer la primera linea del request
  String req = client.readStringUntil('\r');
  client.flush();

  // Enviar html como respuesta
  String s = 
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n\r\n"
    "<!DOCTYPE HTML>\r\n<html>\r\n"
    "Ejemplo de servidor web. Se ha recibido: <br>" + req + "<br>"
    "</html>\n";
  client.print(s);
  delay(1);
}
