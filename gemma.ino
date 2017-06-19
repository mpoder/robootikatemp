#include <Adafruit_NeoPixel.h>

int inputPin = 0;
int ledPin = 1;
int lightMode = 0;
int lightCtl = 0;
int lightTimer = 0;
#define PIN 1
Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, PIN, NEO_GRB + NEO_KHZ800);



void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  strip.begin();
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  lightCtl += 5;
  if (digitalRead(inputPin) == LOW) {
    lightTimer = 360;
    lightMode = 1;
  } else {
    lightMode = 0;
  }

  if (lightCtl > 60) {
    lightCtl = 0;
  }

  if (lightTimer > 0) {
    blinkLight();
    lightTimer--;
  }

  if (lightTimer == 0) {
    strip.setPixelColor(0, 0, 0, 0);
    strip.setPixelColor(1, 0, 0, 0);
    strip.setPixelColor(2, 0, 0, 0);
    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }

  switch (lightMode) {
    case 0:
      digitalWrite(ledPin, LOW);
      break;
    case 1:
      digitalWrite(ledPin, HIGH);
  }

  delay(25);
}

void blinkLight() {
  if (lightCtl < 15) {
    strip.setPixelColor(0, 255, 255, 255);
    strip.setPixelColor(1, 0, 0, 0);
    strip.setPixelColor(2, 0, 0, 0);
    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }
  if (lightCtl > 15 && lightCtl < 30) {
    strip.setPixelColor(0, 0, 0, 0);
    strip.setPixelColor(1, 255, 255, 255);
    strip.setPixelColor(2, 0, 0, 0);
    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }
  if (lightCtl > 30 && lightCtl < 45) {
    strip.setPixelColor(0, 0, 0, 0);
    strip.setPixelColor(1, 0, 0, 0);
    strip.setPixelColor(2, 255, 255, 255);
    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }
  if (lightCtl > 45 && lightCtl <= 60) {
    strip.setPixelColor(0, 0, 0, 0);
    strip.setPixelColor(1, 0, 0, 0);
    strip.setPixelColor(2, 0, 0, 0);
    strip.setPixelColor(3, 255, 255, 255);
    strip.show();
  }
}
