#include <Arduino.h>
#include <Bounce2.h>

constexpr uint8_t LED_PIN = 9;
constexpr uint8_t BUTTON_PIN = 2;

Bounce2::Button button = Bounce2::Button();
bool ledState = false;

unsigned long pressStartTime = 0;
bool longPressHandled = false;

constexpr unsigned long LONG_PRESS_TIME = 1000;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    button.attach(BUTTON_PIN, INPUT_PULLUP);
    button.interval(30);              // debounce, мс
    button.setPressedState(LOW);      // LOW = нажато (т.к. pull-up)
}

void loop() {
    button.update();

    if(button.pressed()){
        pressStartTime = millis();
        longPressHandled = false;
    }

    if(button.isPressed() && !longPressHandled){
        if(millis() - pressStartTime >= LONG_PRESS_TIME){
            longPressHandled = true;
        }
    }

    if(button.released()){
        digitalWrite(LED_PIN, longPressHandled);
    }
}