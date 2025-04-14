#include <Arduino.h>

// Pin-Definitionen
const int EN_PIN = 25;    // Enable Pin
const int STEP_PIN = 26;  // Step Pin
const int DIR_PIN = 27;   // Direction Pin

// Motor-Parameter
const int STEPS_PER_REV = 3250;  // Schritte pro Umdrehung (für einen Standard 1.8° Schrittmotor)
const int MICROSTEPS = 2;       // 8 Mikroschritte (MS1=GND, MS2=GND)
const int TOTAL_STEPS = STEPS_PER_REV * MICROSTEPS;

// Timing-Parameter (eine Zahl zwischen 9 - 470)
const int STEP_DELAY_US = 20;  // Verzögerung zwischen Schritten in Mikrosekunden (Geschwindigkeit)

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 TMC2209 Stepper Motor Test");
  
  // Pin-Modi einstellen
  pinMode(EN_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  
  // Treiber deaktivieren beim Start (low-active)
  digitalWrite(EN_PIN, HIGH);
  
  // Richtung einstellen (LOW oder HIGH, abhängig von der gewünschten Richtung)
  digitalWrite(DIR_PIN, LOW);
  
  // Warte kurz, bis alles initialisiert ist
  delay(1000);
  
  // Treiber aktivieren
  digitalWrite(EN_PIN, LOW);
}

void loop() {
  // Eine volle Umdrehung im Uhrzeigersinn
  rotateMotor(TOTAL_STEPS, LOW);
  delay(1000);
  
  // Zusätzliche Verzögerung vor Richtungswechsel
  delay(500);
  
  // Eine volle Umdrehung gegen den Uhrzeigersinn
  rotateMotor(TOTAL_STEPS, HIGH);
  delay(1000);
}

void rotateMotor(int steps, bool direction) {
  // Richtung setzen und kurz warten
  digitalWrite(DIR_PIN, direction);
  delay(10);  // Kurze Pause nach Richtungswechsel
  
  // Führe die angegebene Anzahl von Schritten aus
  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(STEP_DELAY_US);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(STEP_DELAY_US);
  }
}