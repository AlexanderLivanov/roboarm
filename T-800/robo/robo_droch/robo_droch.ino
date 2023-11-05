#include <SPI.h> 
#include <nRF24L01.h>
#include <RF24.h>


int pX = 0;
int pY = 1;
int pZ = 2;
int pJ = 3;
int oX = 497;
int oY = 497;
int oZ = 507;
int oJ = 517;

int pCE = 10;
int pCSN = 9;
RF24 radio(pCE, pCSN);
int dj[4];

int boot = 0;

void setup() {
  
  radio.begin();
  radio.setChannel(5);
  radio.setDataRate (RF24_1MBPS);
  radio.setPALevel(RF24_PA_HIGH);
  radio.openWritingPipe(0x7878787878LL);
  
  pinMode(pX, INPUT);
  pinMode(pY, INPUT);
  pinMode(pZ, INPUT);
  pinMode(pJ, INPUT);
  
  if (boot == 1) {
    int x = analogRead(pX);
    int y = analogRead(pY);
    int z = analogRead(pZ);
    int j = analogRead(pJ);
    Serial.println(x);
    Serial.println(x);
    Serial.println(z);
    Serial.println(j);
    delay(100000);
  }
}


void loop() {
  int x = analogRead(pX) - oX;
  int y = analogRead(pY) - oY;
  int z = analogRead(pZ) - oZ;
  int j = analogRead(pJ) - oJ;

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

  radio.write(dj);
  
//  Serial.print(x);
//  Serial.print(" ");
//  Serial.print(y);
//  Serial.print(" ");
//  Serial.print(z);
//  Serial.print(" ");
//  Serial.print(j);
//  Serial.println(" ");
}
