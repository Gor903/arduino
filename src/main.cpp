#include <Arduino.h>

constexpr uint8_t POT_PIN = A0;

constexpr uint8_t GREEN = 1;
constexpr uint8_t YELLOW = 2;
constexpr uint8_t ORANGE = 3;
constexpr uint8_t RED = 4;

constexpr uint8_t LEDS[] = {
    GREEN,
    YELLOW,
    ORANGE,
    RED
};

void setup() {
    for(size_t i = 0; i < sizeof(LEDS); i++){
        pinMode(LEDS[i], OUTPUT);
    }
}

void loop() {
    unsigned int potValue = analogRead(POT_PIN);
    unsigned int percent = potValue * 100L / 1023;

    for(size_t i = 0; i < sizeof(LEDS); i++){
        digitalWrite(LEDS[i], percent <= 25 * (i+1) && percent > i * 25);
    }

    delay(10);
}