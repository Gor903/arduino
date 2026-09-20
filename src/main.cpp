#include <Arduino.h>
#include <avr/io.h>

constexpr uint8_t LED_PIN = 1;
constexpr uint8_t BUTTON_PIN = 2; 

bool ledState = false;
// bool lastButtonState = HIGH;
bool lastButtonState = true;

void setup() {
    // pinMode(LED_PIN, OUTPUT);
    DDRB |= (1 << LED_PIN);
    PORTB &= ~(1 << LED_PIN);

    // pinMode(BUTTON_PIN, INPUT_PULLUP);
    DDRD &= ~(1 << BUTTON_PIN);
    PORTD |= (1 << BUTTON_PIN);
}
 
void loop() {
    // const bool buttonState = digitalRead(BUTTON_PIN);
    const bool buttonState = (PIND & (1 << BUTTON_PIN)) != 0;

    // if(lastButtonState == HIGH && buttonState == LOW){
    if(lastButtonState && !buttonState){
        delay(100); // temporary, to avoid button bounce
        
        ledState = !ledState;
        // digitalWrite(LED_PIN, ledState);
        PORTB ^= (1 << LED_PIN);
    }

    lastButtonState = buttonState;
}
 