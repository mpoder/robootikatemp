void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);

}

int counter;
int blinker;


void loop() {
  // put your main code here, to run repeatedly:
  delay(15);
  if (digitalRead(2) == HIGH) {
    counter = (5 * 60);
  } else {

  }

  if (counter > 0) {
    blinkLight();
  } else {
    digitalWrite(4, LOW);
  }

  if (counter > 0) {
    counter = counter - 1;
  }
}

void blinkLight() {
  blinker = blinker - 1;
  if (blinker <= 0) {
    blinker = 30;}
  if (blinker > 15) {
    digitalWrite(4, HIGH);
    } else {
    digitalWrite(4, LOW);
    }
  }

