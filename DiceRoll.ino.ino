const byte BINPIN = 1;
const byte POTPIN = A1;


void setup() {
  pinMode(BINPIN, INPUT);
  pinMode(POTPIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BINPIN) == HIGH) {
    Serial.println("Rolling dice");

    int diceType = analogRead(POTPIN);
    diceType = map(diceType, 0, 1023, 1, 6);
    rollDice(diceType);
  }
}

void rollDice(byte numSides) {
  byte diceRoll = 255;

  switch (numSides) {
    case 1:
      Serial.print("A 4 sided dice rolls: ");
      diceRoll = random(1, 4);
      break;
    case 2:
      Serial.print("A 6 sided dice rolls: ");
      diceRoll = random(1, 6);
      break;
    case 3:
      Serial.print("A 8 sided dice rolls: ");
      diceRoll = random(1, 8);
      break;
    case 4:
      Serial.print("A 10 sided dice rolls: ");
      diceRoll = random(1, 10);
      break;
    case 5:
      Serial.print("A 12 sided dice rolls: ");
      diceRoll = random(1, 12);
      break;
    case 6:
      Serial.print("A 20 sided dice rolls: ");
      diceRoll = random(1, 20);
      break;
    default:
      Serial.println("Issue with mapping potentiometer values");
      break;
  }
  Serial.println(diceRoll);
}
