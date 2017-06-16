int inputPin = 0;
int ledPin = 1;
int lightMode = 0; // is the light toggled in
int lastConn = 0;
int connectionMade = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lastConn = connectionMade;
  if (digitalRead(inputPin) == LOW) {
    connectionMade = 1;
    //blinkLight();
  } else {
    connectionMade = 0;}

  if (connectionMade == 1  && lightMode == 0) {
    lightMode = 1;
  }

  if (connectionMade == 1  && lightMode == 1) {
    lightMode = 0;
  }

  switch (lightMode) {
    case 0:
    digitalWrite(ledPin, LOW);
    break;
    case 1:
    digitalWrite(ledPin, HIGH);
    }
}

void blinkLight() {
  digitalWrite(ledPin, HIGH);
  delay(25);
  digitalWrite(ledPin, LOW);
  delay(25);
  digitalWrite(ledPin, HIGH);
  delay(25);
  digitalWrite(ledPin, LOW);
}
