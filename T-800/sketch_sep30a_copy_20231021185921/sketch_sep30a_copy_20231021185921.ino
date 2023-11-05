#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
#include <printf.h>
#include <SPI.h>

int ENA = 9; 
int ENB = 3;
int IN1 = 7;
int IN2 = 6;
int IN3 = 5;
int IN4 = 4;
uint8_t power = 5;

int CE = 45;
int CSN = 44;
RF24 radio(CE, CSN);
int incomingBytes[4];

class Motor{
public:
  Motor(int EN, int IN1, int IN2, uint8_t power){
    _EN = EN;
    _IN1 = IN1;
    _IN2 = IN2;
    _power = power;

    pinMode(_EN, OUTPUT);
    pinMode(_IN1, OUTPUT);
    pinMode(_IN2, OUTPUT);

    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, LOW);
  }

  void forward(){
    Serial.println("forward");
    analogWrite(_EN, _power);
    digitalWrite(_IN1, HIGH);
    digitalWrite(_IN2, LOW);

    analogWrite(_EN, _power);
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, HIGH);
  }

  void backward(){
    Serial.println("backward");
    analogWrite(_EN, _power);
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, HIGH);

    analogWrite(_EN, _power);
    digitalWrite(_IN1, HIGH);
    digitalWrite(_IN2, LOW);
  }

  void stop(){
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, LOW);
  }

private:
  int _EN = 0;
  int _IN1 = 0;
  int _IN2 = 0;
  uint8_t _power = 0;
};

Motor m1(ENA, IN1, IN2, power);
Motor m2(ENB, IN3, IN4, power);

void setup(){
  Serial.begin(9600);
  m1.stop();
  m2.stop();
  radio.begin();
  radio.setChannel(1);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.openReadingPipe(1, 0x1234567890LL);
  radio.startListening();
}

void loop(){
  if(Serial.available()){
    int q = Serial.read();
    if(q == 49){
      Serial.println(q);
      m1.forward();
      m2.backward();
      delay(1000);
      m1.stop();
      m2.stop();
    }
    if(q == 50){
      Serial.println(q);
      m1.backward();
      m2.forward();
      delay(1000);
      m1.stop();
      m2.stop();
    }
  }
  if(radio.available()){
    radio.read(&incomingBytes, sizeof(incomingBytes));
    for (int i : incomingBytes) {
      Serial.print(i);
    }
    Serial.println();
  }
}
