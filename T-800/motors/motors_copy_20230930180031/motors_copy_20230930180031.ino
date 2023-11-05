// int ENA = 9;
// int ENB = 3;
// int IN1 = 7;
// int IN2 = 6;
// int IN3 = 5;
// int IN4 = 4;

class Motor{
public:
  Motor(int ENA, int IN1, int IN2, int power){
    _ENA = ENA;
    _IN1 = IN1;
    _IN2 = IN2;
    _power = power;
    pinMode(_ENA, OUTPUT);
    pinMode(_IN1, OUTPUT);
    pinMode(_IN2, OUTPUT);
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, LOW);
  }

  void forward(){
    while(_power < 255) {
      analogWrite(_ENA, _power);
      digitalWrite(_IN1, HIGH);
      digitalWrite(_IN2, LOW);
      delay(1000);
      _power += 30;
  }
  _power = 225;
  while(_power > 105) {
    analogWrite(_ENA, _power);
    digitalWrite(_IN1, LOW);
    digitalWrite(_IN2, HIGH);
    delay(1000);
    _power -= 30;
  }
  _power = 105;
  }

private:
  int _ENA;
  int _IN1;
  int _IN2;
  int _power;
};

Motor m1(9, 7, 6, 100);

void setup() {
  pinMode(9, OUTPUT);
  pinMode(7, LOW);
  pinMode(6, LOW);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    int i = Serial.read();
    if(i == 49){
      Serial.println("GO");
      m1.forward();
    }
  }
}