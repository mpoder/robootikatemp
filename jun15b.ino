int button1 = 2;
int button2 = 3;
int led1 = 5;
int led2 = 6;
int counter1 = 0;
int counter2 = 0;
int blinker1 = 0;
int blinker2 = 0;
int onDuration = 7 * 60;

void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(15);
  if (digitalRead(button1) == HIGH) {
    counter1 = (onDuration);
  }
  if (digitalRead(button2) == HIGH) {
    counter2 = (onDuration);
  }

  if (counter1 > 0) {
    blinkLight(1);
  } else {
    digitalWrite(led1, LOW);
  }

  if (counter2 > 0) {
    blinkLight(2);
  } else {
    digitalWrite(led2, LOW);
  }

  if (counter1 > 0) {
    counter1--;
  }

  if (counter2 > 0) {
    counter2--;
  }
}

void blinkLight(int light) {
  switch (light) {
    case 1:
      blinker1--;
      if (blinker1 < 0) {
        blinker1 = 30;
      }
      break;
    case 2:
      blinker2--;
      if (blinker2 < 0) {
        blinker2 = 30;
      }
      break;
  }
  if (blinker1 > 15) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
  if (blinker2 > 15) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
}

