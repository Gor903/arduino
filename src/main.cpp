#include <Arduino.h>

constexpr uint8_t POT_PIN = A0;
constexpr unsigned long POT_INTERVAL = 10;

constexpr uint8_t LEDS[] = {1, 2, 3, 4};
constexpr size_t LED_COUNT = sizeof(LEDS) / sizeof(LEDS[0]);

unsigned long lastChanged = 0;
unsigned int potValue = 0;

void setup() {
    for (size_t i = 0; i < LED_COUNT; i++) {
        pinMode(LEDS[i], OUTPUT);
    }
}

void loop() {
    unsigned long now = millis();

    if (now - lastChanged >= POT_INTERVAL) {
        lastChanged = now;
        potValue = analogRead(POT_PIN);
    }

    unsigned int percent = potValue * 100L / 1023;

    for (size_t i = 0; i < LED_COUNT; i++) {
        digitalWrite(
            LEDS[i],
            percent <= 25 * (i + 1) &&
            percent > 25 * i
        );
    }
}