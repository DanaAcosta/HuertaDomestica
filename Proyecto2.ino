#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
#define SENSOR A0

byte v_sensor = 1;
#include <SoftwareSerial.h>
SoftwareSerial bt(8,9);
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  //pinMode(13,OUTPUT);
  dht.begin();
  bt.begin(9600);
  pinMode(SENSOR, INPUT);
}

void loop() {
  int entrada = bt.read();
  if(entrada == '1'){
    digitalWrite(13,HIGH);
    delay(5000);
    digitalWrite(13,LOW);
    //bt.println("Carrito ==> ON");
  } 
//  else if(entrada == '0'){
//    digitalWrite(13,LOW);
//    //bt.println("Carrito ==> OFF");
//  }
  delay(1000);
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  int b_sensor = analogRead(SENSOR);

  int suelo_porcentaje = map(b_sensor, 1023, 0, 0, 100);
  //Serial.print("Temperatura: ");


//  Serial.print(t);
//  Serial.print(" ");
//  Serial.print(h);
//  Serial.print(" ");
//  Serial.println(suelo_porcentaje);
  bt.print(t);
  bt.print("°C");
  bt.print(";");

  bt.print(h);
  bt.print("%");
  bt.print(";");

  bt.print(suelo_porcentaje);
  bt.print("%");
  bt.println(";");
  if(suelo_porcentaje <= 25){
    digitalWrite(13,HIGH);
    delay(5000);
    //bt.println("Carrito ==> ON");
    digitalWrite(13,LOW);
  } 
}
