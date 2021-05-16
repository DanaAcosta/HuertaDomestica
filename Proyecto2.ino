#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
#define SENSOR A0

byte v_sensor = 1;
#include <SoftwareSerial.h>
SoftwareSerial bt(8,9);
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);


//define the RGB pind
int red = 11;
int green = 10;
int blue = 5;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  dht.begin();
  bt.begin(9600);
  pinMode(SENSOR, INPUT);
  pinMode(red, OUTPUT);   //Red color pwm pin defined as output
  pinMode(green, OUTPUT); //Green color pwm pin defined as output
  pinMode(blue, OUTPUT);  //Blue color pwm pin defined as output
  
  //Give first value of the PWM 0, we start with the RGB LEDs off
  analogWrite(red,0);
  analogWrite(green,0);
  analogWrite(blue,0);
}

void loop() {
  int entrada = bt.read();

//    if (entrada == 'n')
//  {
//    analogWrite(red,0);
//    analogWrite(green,0);
//    analogWrite(blue,0);
//  }
//  //White
//  if (entrada == 'w')
//  {
//    analogWrite(red,255);
//    analogWrite(green,255);
//    analogWrite(blue,255);
//  }
//  //Red
//  if (entrada == 'r')
//  {
//    digitalWrite(red,255);
//    digitalWrite(green,0);
//    digitalWrite(blue,0);
//  }
//  //Green
//  if (entrada == 'g')
//  {
//    analogWrite(red,0);
//    analogWrite(green,255);
//    analogWrite(blue,0);
//  }
//  //Blue
//  if (entrada == 'b')
//  {
//    analogWrite(red,0);
//    analogWrite(green,0);
//    analogWrite(blue,255);
//  }
//  //Orange
//  if (entrada == 'o')
//  {
//    analogWrite(red,255);
//    analogWrite(green,153);
//    analogWrite(blue,0);
//  }
//  //Violet
//  if (entrada == 'v')
//  {
//    analogWrite(red,102);
//    analogWrite(green,0);
//    analogWrite(blue,153);
//  }
//  //Cyan
//  if (entrada == 'c')
//  {
//    analogWrite(red,0);
//    analogWrite(green,255);
//    analogWrite(blue,255);
//  }
//  //Yellow 
//  if (entrada == 'y')
//  {
//    analogWrite(red,255);
//    analogWrite(green,204);
//    analogWrite(blue,0);
//  }  
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
//  if(suelo_porcentaje <= 25){
//    digitalWrite(13,HIGH);
//    delay(5000);
//    //bt.println("Carrito ==> ON");
//    digitalWrite(13,LOW);
//  } 
}
