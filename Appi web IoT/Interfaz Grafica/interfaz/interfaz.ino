void setup() {
   Serial.begin(9600);
  // pinMode(D0,INPUT);
   //pinMode(D1,INPUT);


}

void loop() {
  
int luz = 0;
int gas = 0;
int humedad = 0;

/*
Serial.print("Luz: ");
Serial.println(luz);

Serial.print("Gas: ");
Serial.println(gas);

Serial.print("Humedad: ");
Serial.println(humedad);
*/

//delay(1000);


  String datos = "$";
  datos = datos + String(gas);
  datos = datos + "$";
  datos = datos + "#";
  datos = datos + String(luz);
  datos = datos + "#";
  datos = datos + "?";
  datos = datos + String(humedad);
  datos = datos + "?";
  Serial.println(datos);
  delay(1000);

 

 
}
