#include <DHT11.h>
#include <Servo.h>

#define ServoMotor 4
#define Botao 6
DHT11 dht11(2);

Servo ventilacao; // Declaramos o servo fora do loop

void setup() {
  pinMode(6, INPUT);
  pinMode(4, OUTPUT);

  Serial.begin(9600);
  dht11.setDelay(500);

  ventilacao.attach(ServoMotor); // Inicializa o servo no pino definido
  ventilacao.write(0);           // Começa fechado
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

    if (temperatura <= 20) {          
      ventilacao.write(0);      // 0% abertura
    } else if (temperatura <= 25) {   
      ventilacao.write(45);     // 25% abertura
    } else if (temperatura <= 30) {   
      ventilacao.write(90);     // 50% abertura
    } else if (temperatura <= 35) {   
      ventilacao.write(135);    // 75% abertura
    } else {                         
      ventilacao.write(180);    // 100% abertura
    }

    delay(1000); 
}
