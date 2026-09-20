#include <Arduino.h>
#include <avr/io.h>

constexpr uint8_t LED_PIN = 1;
constexpr uint8_t BUTTON_PIN = 2;
constexpr unsigned long DEBOUNCE_MS = 30;

bool rawState = true;
bool lastRawState = true;
bool debouncedState = true;
bool lastDebouncedState = true;

unsigned long lastChangeTime = 0;

void setup() {
    DDRB |= (1 << LED_PIN);
    PORTB &= ~(1 << LED_PIN);

    DDRD &= ~(1 << BUTTON_PIN);
    PORTD |= (1 << BUTTON_PIN);
}

void loop() {
    rawState = (PIND & (1 << BUTTON_PIN)) != 0;

    if (rawState != lastRawState) {
        lastChangeTime = millis();
    }

    if ((millis() - lastChangeTime) > DEBOUNCE_MS && rawState != debouncedState) {
        debouncedState = rawState;

        if (lastDebouncedState && !debouncedState) {
            PORTB ^= (1 << LED_PIN); // toggle
        }
        lastDebouncedState = debouncedState;
    }

    lastRawState = rawState;
}