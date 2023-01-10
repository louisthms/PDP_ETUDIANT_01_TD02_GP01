#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

int LED = 26;
const byte DHTPIN = 33;
// Definit le type de capteur utilise
DHT dht(DHTPIN, DHT11);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(LED, OUTPUT);
}

void loop()
{

  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
  // put your main code here, to run repeatedly:

  int TemperatureSensor = dht.readTemperature();
  int HumiditySensorAir = dht.readHumidity();

  Serial.println("Temperature = " + String(dht.readTemperature()) + " °C");
  Serial.println("Humidite = " + String(dht.readHumidity()) + " %");

  delay(5000);
}
