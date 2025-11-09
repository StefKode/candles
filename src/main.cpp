// Copyright : Copilot Generated
#include <Arduino.h>

// LED configuration (use PWM-capable pins on the Nano)
const int LED_PIN1 = 3;  // PWM pin for LED #1
const int LED_PIN2 = 5;  // PWM pin for LED #2

// Flicker parameters (shared)
const int BASE_BRIGHTNESS = 150;  // Base brightness (0-255)
const int FLICKER_AMOUNT = 25;    // Maximum random flicker variation

const int FACTOR = 1.7;

// Timing parameters (shared)
const int MIN_DELAY = int(60 * FACTOR);   // Minimum time between updates (ms)
const int MAX_DELAY = int(100 * FACTOR);   // Maximum time between updates (ms)

// Independent last-update timestamps for each LED
unsigned long lastUpdate1 = 0;
unsigned long lastUpdate2 = 0;

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  randomSeed(analogRead(0));  // Initialize random number generator
}

// Helper to compute and apply a new brightness value
static void updateFlicker(int pin, unsigned long &lastUpdate) {
  unsigned long currentTime = millis();
  // Use a non-blocking update so each LED is independent
  if (currentTime - lastUpdate >= (unsigned long)random(MIN_DELAY, MAX_DELAY)) {
    int flicker = random(-FLICKER_AMOUNT, FLICKER_AMOUNT);
    int brightness = BASE_BRIGHTNESS + flicker;

    // Occasionally add a larger transient to simulate a gust
    if (random(0, 20) == 0) { // 10% chance
      brightness += random(-40, 80); // small chance of a brighter surge
    }

    brightness = constrain(brightness, 0, 255);
    analogWrite(pin, brightness);
    lastUpdate = currentTime;
  }
}

void loop() {
  // Update each LED independently
  updateFlicker(LED_PIN1, lastUpdate1);
  updateFlicker(LED_PIN2, lastUpdate2);
}
