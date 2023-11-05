int ENA = 9; 
int ENB = 3;
int IN1 = 7;
int IN2 = 6;
int IN3 = 5;
int IN4 = 4;

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

  // void forward(){
  //   Serial.println("forward");
  //   while(_power < 255){
  //     analogWrite(_EN, _power);
  //     digitalWrite(_IN1, HIGH);
  //     digitalWrite(_IN2, LOW);
  //     delay(1000);
  //     _power += 50;
  //   }
  //   _power = 205;
  //   while(_power > 105){
  //     analogWrite(_EN, _power);
  //     digitalWrite(_IN1, LOW);
  //     digitalWrite(_IN2, HIGH);
  //     delay(1000);
  //     _power -= 50;
  //   }
  //   _power = 105;
  // }

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

  // void backward(){
  //   Serial.println("backward");
  //   while(_power < 255){
  //   analogWrite(_EN, _power);
  //   digitalWrite(_IN1, LOW);
  //   digitalWrite(_IN2, HIGH);
  //   delay(500);
  //   _power += 30;
  //   }
  //   _power = 225;
  //   while(_power > 105){
  //     analogWrite(_EN, _power);
  //     digitalWrite(_IN1, HIGH);
  //     digitalWrite(_IN2, LOW);
  //     delay(500);
  //     _power -= 30;
  //   }
  //   _power = 105;
  // }

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
}
