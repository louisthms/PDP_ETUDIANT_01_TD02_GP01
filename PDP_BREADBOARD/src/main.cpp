#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

int LED = 26;
const byte DHTPIN = 33;
// Definit le type de capteur utilise
DHT dht(DHTPIN, DHT22);

void setup()
{

  // Configuration timer 5 seconds
  Serial.println();

  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(LED, OUTPUT);

  // code pour la led
  /*  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);*/

  // put your main code here, to run repeatedly:

  // sensor initialize and display (DHT)
  int TemperatureSensor = dht.readTemperature();
  int HumiditySensorAir = dht.readHumidity();

  Serial.println("Temperature = " + String(dht.readTemperature()) + " °C");
  Serial.println("Humidite = " + String(dht.readHumidity()) + " %");
  Serial.println("mode veille de 5 secondes");

  // Deep sleep mode
  Serial.println("Deep sleep mode");
  delay(100);
  ESP.deepSleep(5e6);
}

void loop()
{
}