#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
#include <Servo.h>

Cytron_PS2Shield ps2(10,11);
Servo myservo1;
Servo myservo2; 
int pos = 0;   
int up;
int down;
int left;
int right;

void setup() {
  myservo1.attach(8);
  myservo2.attach(9);
  Serial.begin(9600);
  ps2.begin(9600);
  }

void loop() {
up = ps2.readButton(PS2_UP);
down = ps2.readButton(PS2_DOWN);
right = ps2.readButton(PS2_RIGHT);
left = ps2.readButton(PS2_LEFT);
delay (100);  
 if ((down==0)&& (up==1) && (right==1) && (left==1) ) //down//
 {
  myservo2.write(0); 
  delay (500);
  Serial.println("down");
 }
 if ((up==0) && (down==1) && (right==1) && (left==1)) //up//
 {
  myservo2.write(90);
  delay (500);
  Serial.println("up");
 }
 if ((right==0) && (left==1) && (up==1) && (down==1)) //grip//
 {
  myservo1.write(180);
  delay(500);
  Serial.println("grip");
 }
 if ((left==0) && (right==1) && (up==1) && (down==1)) //release//
 {
  myservo1.write(0);
  delay(500);
 Serial.println("release"); 
  
 }

 }


