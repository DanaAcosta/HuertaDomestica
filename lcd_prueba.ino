#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define SENSOR A0
LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7); // DIR, E, RW, RS, D4, D5, D6, D7
#include <DHT.h>
byte v_sensor = 1;

char color=0; //store the received byte here

//define the RGB pind
int red = 10;
int green = 11;
int blue = 5;

void setup()
{
    lcd.setBacklightPin(3,POSITIVE);  // puerto P3 de PCF8574 como positivo
    lcd.setBacklight(HIGH);   // habilita iluminacion posterior de LCD
    lcd.begin(16, 2);     // 16 columnas por 2 lineas para LCD 1602A
    lcd.clear();      // limpia pantalla
    pinMode(SENSOR, INPUT);
    pinMode(13,OUTPUT);

    Serial.begin(9600);     //Start the serial comunication for the bluetooth module
    pinMode(red, OUTPUT);   //Red color pwm pin defined as output
    pinMode(green, OUTPUT); //Green color pwm pin defined as output
    pinMode(blue, OUTPUT);  //Blue color pwm pin defined as output

    analogWrite(red,0);
    analogWrite(green,0);
    analogWrite(blue,0);
  
}

void loop()
{
//    lcd.setCursor(0, 0);    // ubica cursor en columna 0 y linea 0
//    lcd.print("Tengo Hambre");  // escribe el texto
//    lcd.setCursor(0, 1);    // ubica cursor en columna 0 y linea 1
//    lcd.print("Quiero galletas");     // escribe seg.
    int v_sensor = analogRead(SENSOR);
    int suelo_porcentaje = map(v_sensor, 1023, 0, 0, 100);
    lcd.setCursor(0, 0);
    lcd.print("Humedad suelo:");
    lcd.setCursor(0, 1);    // ubica cursor en columna 0 y linea 1
    lcd.print(suelo_porcentaje);
    lcd.print("%");
    delay(500);
      if(suelo_porcentaje <= 50){
    digitalWrite(13,HIGH);
    delay(3000);
    digitalWrite(13,LOW);
  } 

  if(Serial.available()>0){
    // read the bluetoot data and store it
    color = Serial.read();
    char Rec = char(color);
    if (Rec != '0')
    {
    Serial.println(Rec); //This is to visualise the received character on the serial monitor
    }  
  }

  //LEDs off
  if (color == 'n')
  {
    analogWrite(red,0);
    analogWrite(green,0);
    analogWrite(blue,0);
  }
  //White
  if (color == 'w')
  {
    analogWrite(red,255);
    analogWrite(green,255);
    analogWrite(blue,255);
  }
  //Red
  if (color == 'r')
  {
    analogWrite(red,255);
    analogWrite(green,0);
    analogWrite(blue,0);
  }
  //Green
  if (color == 'g')
  {
    analogWrite(red,0);
    analogWrite(green,255);
    analogWrite(blue,0);
  }
  //Blue
  if (color == 'b')
  {
    analogWrite(red,0);
    analogWrite(green,0);
    analogWrite(blue,255);
  }
  //Orange
  if (color == 'o')
  {
    analogWrite(red,255);
    analogWrite(green,153);
    analogWrite(blue,0);
  }
  //Violet
  if (color == 'v')
  {
    analogWrite(red,102);
    analogWrite(green,0);
    analogWrite(blue,153);
  }
  //Cyan
  if (color == 'c')
  {
    analogWrite(red,0);
    analogWrite(green,255);
    analogWrite(blue,255);
  }
  //Yellow 
  if (color == 'y')
  {
    analogWrite(red,255);
    analogWrite(green,204);
    analogWrite(blue,0);
  }   
  lcd.clear(); 
}
