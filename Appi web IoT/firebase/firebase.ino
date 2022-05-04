
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

const char* ssid = ""; // nombre de red wifi en caso de que se esta usando
const char* password = ""; // clave de red wifi

#define FIREBASE_HOST "" // url de base de datos de api firebase

#define FIREBASE_AUTH "" // api key de api de firebase
    
void setup() {
  // put your setup code here, to run once:
  pinMode(D0,INPUT);
  pinMode(D1,INPUT);
  Serial.begin(9600);
  delay(10);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  Serial.print("Conectando a: \t");
  Serial.print(ssid);

  while(WiFi.status() != WL_CONNECTED){
    delay(200);
    Serial.print(".");
  }
  Serial.println(" ");
  Serial.print("Se logro establecer la conexion con la red ");
  Serial.println(WiFi.SSID());
  Serial.print("Direccion IP: ");
  Serial.print(WiFi.localIP());

  pinMode(D8, OUTPUT);

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int luz = analogRead(A0);
  int gas = digitalRead(D0);
  int humedad = digitalRead(D1);
  String estadoGas = "";
  String estadoLuz = "";
  String estadoHumedad = "";


  if(gas == 1){
      estadoGas = "No";
  }else{
      estadoGas = "Si";
   }
  
   if(luz < 700){
      estadoLuz = "Si";
  }else{
      estadoLuz = "No";
    }

   if(humedad == 0){
     estadoHumedad = "No";
  }else{
     estadoHumedad = "Si";
   }


  Serial.print("Humedad: ");
  Serial.println(humedad);
  Serial.print("Luz: ");
  Serial.println(luz);
  Serial.println("\n");

  Firebase.setString("Gas", estadoGas);
  Firebase.setString("Humedad", estadoHumedad);
  Firebase.setString("Luz", estadoLuz);

/*
  Serial.print("Humedad: ");
  Serial.println(humedad);
  Serial.print("Gas: ");
  Serial.println(gas);
  Serial.print("Luz: ");
  Serial.println(luz);

  Serial.print("Humedad: ");
  Serial.println(estadoHumedad);
  Serial.print("Gas: ");
  Serial.println(estadoGas);
  Serial.print("Luz: ");
  Serial.println(estadoLuz);

  Serial.println(); */


  String estadoLed = Firebase.getString("wLed");

  if(estadoLed == "1"){
      digitalWrite(D8, HIGH);
    }else{
        digitalWrite(D8, LOW);
      }
  

}
