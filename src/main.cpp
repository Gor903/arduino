#include <Arduino.h>
#include <Bounce2.h>

constexpr uint8_t LED_PIN = 1;
constexpr uint8_t BUTTON_PIN = 2;

Bounce2::Button button = Bounce2::Button();
bool ledState = false;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    button.attach(BUTTON_PIN, INPUT_PULLUP);
    button.interval(30);              // debounce, мс
    button.setPressedState(LOW);      // LOW = нажато (т.к. pull-up)
}

void loop() {
    button.update();

    if (button.pressed()) {           // сработает один раз на нажатие
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
    }
}