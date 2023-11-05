uint8_t power = 5;

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

Motor m1(9, 7, 6, power);
Motor m2(3, 5, 4, power);
Motor m3(8, 24, 25, power);
Motor m4(10, 26, 27, power);

void setup(){
  Serial.begin(9600);
  m1.stop();
  m2.stop();
  m3.stop();
  m4.stop();
}

void loop(){
  if(Serial.available()){
    char q = Serial.read();
    switch(q){
      case '1':
        Serial.println(q);
        m1.forward();
        m2.backward();
        delay(1000);
        m1.stop();
        m2.stop();
        break;

      case '2':
        Serial.println(q);
        m1.backward();
        m2.forward();
        delay(1000);
        m1.stop();
        m2.stop();
        break;

      case '3':
        Serial.println(q);
        m3.forward();
        m4.backward();
        delay(1000);
        m3.stop();
        m4.stop();
        break;

      case '4':
        Serial.println(q);
        m3.backward();
        m4.forward();
        delay(1000);
        m3.stop();
        m4.stop();
        break;
    }
  }
}
