#include <LiquidCrystal.h> //Libreria para el LCD

#include <DHT.h>
#include <DHT_U.h> //Libreria para sensor DHT

#define DHTPIN 2
#define DHTTYPE DHT11

LiquidCrystal lcd(9, 8, 7, 6, 5, 4); //Pines a los que se conecta el LCD
DHT dht(DHTPIN, DHTTYPE); //Inicio del DHT
const int celda = 0;
const int temp = 1;
const int senhum = 0; //A0
int humedad = 0;
//Pines de hardware

void setup()
{
  lcd.begin(16, 2);
  lcd.home();
  lcd.print("Hello world");
  lcd.setCursor(0, 1);
  lcd.print("test"); //Test de pantalla LCD
  Serial.begin(9600);
  dht.begin();
}


void loop()
{
  float hum = dht.readHumidity(); //Lectura de humedad
  float temp = dht.readTemperature(); //Lectura de temperatura
  float celsius = dht.computeHeatIndex(temp, hum, false); //Computa la corriente a temperatura
  int volt = analogRead(celda);
  Serial.print("VoltHumedad: ");
  Serial.println(analogRead(senhum));
  Serial.print("Voltaje celda: ");
  Serial.println(volt);
  Serial.print("Temperatura: ");
  Serial.println(celsius);
  //Print de los datos
  delay(500); 
  
}
