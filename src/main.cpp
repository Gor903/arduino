#include <Arduino.h>
#include <avr/io.h>

#include <BitUtils.h>

void setup() {
    // Pin 3 = PD3 (PORTD) -> выход
    DDRD |= (1 << DDD3);
}

void loop() {
    for (int i = 0; i <= 4; i += 2) {
        uint8_t mask = 1 << i;
        writeBits(PORTD, 3, 5, mask);
        delay(500);
    }
}