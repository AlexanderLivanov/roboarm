int pX = 0;
int pY = 1;
int pX1 = 2;
int pY1 = 3;
int oX = 497;
int oY = 512;
int oX1 = 497;
int oY1 = 512;

void setup() {
  Serial.begin(9600);
  pinMode(pX, INPUT);
  pinMode(pY, INPUT);
  pinMode(pX1, INPUT);
  pinMode(pY1, INPUT);
}


void loop() {
  int x = analogRead(pX) - oX;
  int y = analogRead(pY) - oY;
  int x1 = analogRead(pX1) - oX1;
  int y1 = analogRead(pY1) - oY1;

  if(x > -50 && x < 50) x = 0;
  if(y > -50 && y < 50) y = 0;
  if(x < -51) x = -1;
  if(y < -51) y = -1;
  if(x > 51) x = 1;
  if(y > 51) y = 1;

  if(x1 > -50 && x1 < 50) x1 = 0;
  if(y1 > -50 && y1 < 50) y1 = 0;
  if(x1 < -51) x1 = -1;
  if(y1 < -51) y1 = -1;
  if(x1 > 51) x1 = 1;
  if(y1 > 51) y1 = 1;

  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.print(x1);
  Serial.print(" ");
  Serial.print(y1);
  Serial.println(" ");
}