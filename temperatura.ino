#include <DHT11.h>
#include <Servo.h>

#define ServoMotor 4
#define Botao 6
DHT11 dht11(2);

void setup() {
  pinMode(6, INPUT);
  pinMode(4, OUTPUT);

  Serial.begin(9600);
  dht11.setDelay(500);
}

void loop() {
    float temperatura = dht11.readTemperature();

    if (temperatura != DHT11::ERROR_CHECKSUM && temperatura != DHT11::ERROR_TIMEOUT) {
        Serial.print("Temperatura: ");
        Serial.print(temperatura);
        Serial.println(" °C");
    } else {
        Serial.println(DHT11::getErrorString(temperatura));
    }
}