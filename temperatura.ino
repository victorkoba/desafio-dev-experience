#include <DHT11.h>
#include <Servo.h>

Servo ServoMotor;
int posicaoAtual = 0;
#define Botao 6
DHT11 dht11(2);

void setup() {
  pinMode(6, INPUT);
  pinMode(10, OUTPUT);

  Serial.begin(9600);
  dht11.setDelay(500);

  ServoMotor.attach(10);
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

  // Define o ângulo alvo de acordo com a temperatura
  int posicaoAlvo = 0;
  if (temperatura <= 20) {          
    posicaoAlvo = 0;      // 0% abertura
  } else if (temperatura <= 25) {   
    posicaoAlvo = 45;     // 25% abertura
  } else if (temperatura <= 30) {   
    posicaoAlvo = 90;     // 50% abertura
  } else if (temperatura <= 35) {   
    posicaoAlvo = 135;    // 75% abertura
  } else {                         
    posicaoAlvo = 180;    // 100% abertura
  }

  // Faz o servo girar suavemente até a posição alvo
  if (posicaoAtual < posicaoAlvo) {
    for (int i = posicaoAtual; i <= posicaoAlvo; i++) {
      ServoMotor.write(i);
      delay(15); // velocidade do giro
    }
  } else if (posicaoAtual > posicaoAlvo) {
    for (int i = posicaoAtual; i >= posicaoAlvo; i--) {
      ServoMotor.write(i);
      delay(15);
    }
  }

  posicaoAtual = posicaoAlvo;

  delay(1000);

      if (temperatura < 18 || temperatura > 38) {
        digitalWrite(Buzzer, HIGH); 
    } else {
        digitalWrite(Buzzer, LOW);  
    }

    delay(1000); 
}
