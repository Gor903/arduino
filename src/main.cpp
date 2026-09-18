#include <Arduino.h>
#include <avr/io.h>

#include <BitUtils.h>

void setup() {
    // Pin 9 = PB1 -> делаем его выходом (кран переведён в режим "сам качает воду")
    DDRB |= (1 << DDB1);

    // Pin 3 = PD3 (PORTD) -> выход
    DDRD |= (1 << DDD3);
}

void loop() {
    // PORTB |= (1 << PB1);
    setBit(PORTB, PB1);
    // PORTD &= ~(1 << PD3);
    // PORTD &= ~(1 << PD7);
    writeBits(PORTD,3,5,0b10000);
    delay(500);

    // PORTB &= ~(1 << PB1);
    // PORTD |= (1 << PD3);
    // PORTD &= ~(1 << PD7);
    // delay(500);

    // PORTB &= ~(1 << PB1);
    clearBit(PORTB, PB1);
    // PORTD &= ~(1 << PD3);
    // PORTD |= (1 << PD7);
    writeBits(PORTD,3,5,0b00001);
    delay(500);
}