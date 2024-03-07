#include <Servo.h>

const byte LEDPIN = 13;
const byte BINPIN = 1;
const byte MICROPIN = 2;
const byte SERVOPIN = 3;

const byte LOCK = 0;
const byte UNLOCK = 90;
const byte LOUDENOUGH = 512;


Servo latch;


void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BINPIN, INPUT);
  pinMode(MICROPIN, INPUT);
  latch.attach(SERVOPIN);

  Serial.begin(9600);
}

void loop() {

  if (analogRead(MICROPIN) > LOUDENOUGH) {
    Serial.print("Heard a knock, unlocking box");
    digitalWrite(LEDPIN, HIGH);
    latch.write(UNLOCK);
  }


  if (digitalRead(BINPIN) == HIGH) {
    Serial.print("Button pressed, locking box");
    latch.write(LOCK);
  }
}