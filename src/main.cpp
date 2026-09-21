#include <Arduino.h>

constexpr uint8_t POT_PIN = A0;
constexpr uint8_t GREEN = 1;
constexpr uint8_t YELLOW = 2;
constexpr uint8_t ORANGE = 3;
constexpr uint8_t RED = 4;

void setup() {
    pinMode(GREEN, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(ORANGE, OUTPUT);
    pinMode(RED, OUTPUT);
}

void loop() {
    int potValue = analogRead(POT_PIN);
    int percent = (long)potValue * 100 / 1023;

    digitalWrite(GREEN, percent > 0);
    digitalWrite(YELLOW, percent > 25);
    digitalWrite(ORANGE, percent > 50);
    digitalWrite(RED, percent > 75);

    delay(10);
}