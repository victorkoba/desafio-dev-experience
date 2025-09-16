#include <DHT.h>

#define DHTPIN 2       // Pino de dados conectado ao D2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando sensor DHT...");
  dht.begin();
  delay(2000);  // Espera inicial
}

void loop() {
  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Falha na leitura do sensor DHT!");
  } else {
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" °C");
  }

  delay(5000);
}
