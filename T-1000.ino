int pX = 8;
int pY = 7;
int pZ = 6;
int pJ = 5;
int oX = 497;
int oY = 497;
int oZ = 507;
int oJ = 517;
int dj[] = {0, 0, 0, 0};

int boot = 1;

void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);
  pinMode(pX, INPUT);
  pinMode(pY, INPUT);
  pinMode(pZ, INPUT);
  pinMode(pJ, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  
  if (boot == 1) {
    int x = digitalRead(8);
    int y = digitalRead(7);
    int z = digitalRead(6);
    int j = digitalRead(5);
    Serial1.println(x);
    Serial1.println(x);
    Serial1.println(z);
    Serial1.println(j);
    delay(100000);
  }
}



void loop() {
  int x = digitalRead(pX) - oX;
  int y = digitalRead(pY) - oY;
  int z = digitalRead(pZ) - oZ;
  int j = digitalRead(pJ) - oJ;

  if(x > -50 && x < 50) dj[0] = 0;
  if(y > -50 && y < 50) dj[1] = 0;
  if(x < -51) dj[0] = -1;
  if(y < -51) dj[1] = -1;
  if(x > 51) dj[0] = 1;
  if(y > 51) dj[1] = 1;

  if(z > -50 && z < 50) dj[2] = 0;
  if(j > -50 && j < 50) dj[3] = 0;
  if(z < -51) dj[2] = -1;
  if(j < -51) dj[3] = -1;
  if(z > 51) dj[2] = 1;
  if(j > 51) dj[3] = 1;

 Serial1.print(dj[0]);
 Serial1.print(" ");
 Serial1.print(dj[1]);
 Serial1.print(" ");
 Serial1.print(dj[2]);
 Serial1.print(" ");
 Serial1.print(dj[3]);
 Serial1.println(" ");

 digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);   
  
//  Serial.print(x);
//  Serial.print(" ");
//  Serial.print(y);
//  Serial.print(" ");
//  Serial.print(z);
//  Serial.print(" ");
//  Serial.print(j);
//  Serial.println(" ");
}
