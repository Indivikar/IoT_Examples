#include <Arduino.h>

// Pin-Definitionen
const int EN_PIN = 25;    // Enable Pin
const int STEP_PIN = 26;  // Step Pin
const int DIR_PIN = 27;   // Direction Pin

// Motor-Parameter
const int STEPS_PER_REV = 51200;    // Schritte pro Umdrehung (für einen Standard 1.8° Schrittmotor), der Wert 51200 stimmt voraussichtlich nicht zu 100%
const int MICROSTEPS = 4;           // 4 Mikroschritte (MS1=GND, MS2=VDD)
const int TOTAL_STEPS = STEPS_PER_REV / MICROSTEPS;

// Funktion zur Berechnung der minimalen Verzögerung basierend auf der Anzahl der Mikroschritte
int calculateMinDelay(int microsteps) {
  // Basisverzögerung für 2 Mikroschritte
  const int BASE_DELAY_US = 10;
  // Minimale Verzögerung skaliert linear mit der Anzahl der Mikroschritte
  return BASE_DELAY_US * (microsteps / 2);
}

// Timing-Parameter (eine Zahl zwischen 20 - 470)
// Die Zahlen wurden im 2 Mikroschritte-Modus getestet, wenn man die Werte unter- oder überschreitet, kann es sein, 
// das der Schrittmotor alle Steps machen kann, es wurde nicht ausgiebig getestet, ob die Werte ok sind
// Der Wert "STEPS_PER_REV" für eine Umdrehung wurde auch nicht ausgiebig getestet
const int STEP_DELAY_US = calculateMinDelay(MICROSTEPS);  // Verzögerung zwischen Schritten in Mikrosekunden (Geschwindigkeit)

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 TMC2209 Stepper Motor Test");
  Serial.print("Schritte pro Umdrehung (TOTAL_STEPS): ");
  Serial.println(TOTAL_STEPS);
  Serial.print("Mikroschritt-Modus (MICROSTEPS): ");
  Serial.println(MICROSTEPS);
  Serial.print("Verzögerung zwischen Schritten in Mikrosekunden (STEP_DELAY_US): ");
  Serial.println(STEP_DELAY_US);
  
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
