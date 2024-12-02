#include <Arduino.h>
#include <Wire.h>
#include <DS1881_2.h>

#define LED_PIN 13
// Sketch setup function - runs once at startup
void setup() 
{
    Wire.begin();
    pinMode(LED_PIN, OUTPUT);
}

// Sketch loop function - runs continuously
void loop() 
{
    digitalWrite(LED_PIN, LOW);
    delay(500);
    digitalWrite(LED_PIN, HIGH);
    delay(500);
}