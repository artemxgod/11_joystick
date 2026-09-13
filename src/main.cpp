#include <Arduino.h>

const int axisX = A1;  // ось X (VRx) подключена к A1
const int axisY = A0;  // ось Y (VRy) подключена к A0
const int buttonPin = 7;  // кнопка джойстика подключена к D7
int valX, valY, valButton = 0;

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);  // D7 как вход с подтягивающим резистором
    Serial.begin(9600);
}

void loop() {
    valX = analogRead(axisX);   // значение оси X
    valY = analogRead(axisY);   // значение оси Y
    valButton = 1 - digitalRead(buttonPin);  // кнопка (инвертированное значение)
    Serial.print("X:");
    Serial.print(valX, DEC);
    Serial.print(" | Y:");
    Serial.print(valY, DEC);
    Serial.print(" | Button: ");
    Serial.println(valButton, DEC);
    delay(30);
}