#include <Arduino.h>

constexpr uint8_t POT_PIN = A0;
constexpr unsigned long POT_INTERVAL = 10;

constexpr uint8_t LED_MASK = 
    (1 << PD1) |
    (1 << PD2) |
    (1 << PD3) |
    (1 << PD4);


unsigned long lastChanged = 0;
unsigned int potValue = 0;

void setup() {
    DDRD |= LED_MASK;
    PORTD &= ~LED_MASK;
}

void loop() {
    unsigned long now = millis();

    if (now - lastChanged >= POT_INTERVAL) {
        lastChanged = now;
        potValue = analogRead(POT_PIN);
    }

    unsigned int percent = potValue * 100L / 1023;

    PORTD &= ~LED_MASK;
    if(percent == 0){
        // nothing, all leds must be off
    }
    else if(percent <= 25){
        PORTD |= (1 << PD1);
    }
    else if(percent <= 50){
        PORTD |= (1 << PD2);
    }
    else if(percent <= 75){
        PORTD |= (1 << PD3);
    }
    else{
        PORTD |= (1 << PD4);
    }
}