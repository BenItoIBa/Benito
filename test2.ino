#include <Servo.h>

const byte LEDPIN = 13;
const byte PAWPIN1 = 1;
const byte PAWPIN2 = 2;
const byte PAWPIN3 = 3;
const byte PAWPIN4 = 4;
const byte LEFTEARPIN = 9;
const byte RIGHTEARPIN = 10;

Servo leftEar;
Servo rightEar;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(PAWPIN1, INPUT);
  pinMode(PAWPIN2, INPUT);
  pinMode(PAWPIN3, INPUT);
  pinMode(PAWPIN4, INPUT);
  leftEar.attach(LEFTEARPIN);
  rightEar.attach(RIGHTEARPIN);
}

void loop() {
  if (digitalRead(PAWPIN1) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  }
   if (digitalRead(PAWPIN2) == HIGH) {
    digitalWrite(LEDPIN, LOW);
  }
  if (digitalRead(PAWPIN3) == HIGH){
    wagEars();
  }
  if (digitalRead(PAWPIN4) == HIGH){
    blinkingLed();
  }
}

void wagEars(){
  leftEar.write(0);
  rightEar.write(0);
  leftEar.write(90);
  rightEar.write(90);
  leftEar.write(0);
  rightEar.write(0);
}

void blinkingLed(){
  byte randNumber = random(1, 3);

  for (int i = 0; i < randNumber; i++) {
  digitalWrite(LEDPIN, HIGH);
  delay(500);
  digitalWrite(LEDPIN, LOW);
  delay(500);
  }
}