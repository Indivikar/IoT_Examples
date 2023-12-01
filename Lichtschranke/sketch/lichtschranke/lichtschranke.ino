/*  Beispiel einer Lichtschranke für den ESP32
 * 
 *  Es wird ein Analogwert vom LDR-Sensor ausgelesen, dieser Analogwert wird addiert und daraus ein Mittelwert berechnet.
 *  Wenn dieser Mittelwert unterschritten wird, dann zählt der Counter um 1 Hoch.
 *  Die Mittelwert-Berechnung wird gemacht, um Fehler beim auslesen vom LDR-Sensor zu vermeiden,  
 *  da der Wert manchmal unterschritten wurde, obwohl es kein unterbruch der Lichtschranke gab.
 */

#include <Bounce2.h>

// Config
const int actionByNumberCounter = 2000;   // wenn der Wert unterschritten wird, dann den Counter auslösen
int maxMittelwert = 5;                    // Wieviel werte sollen addiert werden, bist ein Mittelwert berechnet wird

// Pins
const int buttonResetPin = 33;            // Button Counter auf 0 zurücksetzen
const int ldrCounterPin = 34;             // Lichtschranke LDR (analoger Pin)

int count = 0;                            // wie oft wurde die Lichtschranke unterbrochen
int mittelwert = 4095;                    // Mittelwert der addierten analogen Werte
int countAnalogwert = 0;                  // addierte Analogwerte
int indexAnalogwert = 0;                  // wie oft wurde der Analogwert addiert

boolean isCounted = false;                // wurde um 1 hochgezählt

Bounce buttonReset = Bounce();

void setup() {
  Serial.begin(115200);

  pinMode(buttonResetPin, INPUT);

  buttonReset.attach(buttonResetPin);
  buttonReset.interval(10);
}

void loop() {

  int ldrCounterValue = analogRead(ldrCounterPin); 

  checkCounterLDR(ldrCounterValue, true);

  buttonResetAction();

  delay(5);
}

void buttonResetAction(){
  buttonReset.update();
  if (buttonReset.fell()) {
    Serial.println("Reset Counter!");
    count = 0;    
  }
}

void checkCounterLDR(int ldrValue, bool isLDRValueShowing){

  // Analogwerte der Lichtschranke addieren, um einen Mittelwert zu berechnen
  setMittelwert(ldrValue);

  // wenn der maxMittelwert noch nicht erreicht ist, dann hier abbrechen
  if (indexAnalogwert < maxMittelwert) {
    return;
  }    

  // warten bis der maxMittelwert erreicht ist
  if (indexAnalogwert == maxMittelwert) {
    mittelwert = getMittelwert();
  }

  // wenn der maxMittelwert überschritten ist, dann wieder reseten
  if (indexAnalogwert > maxMittelwert) {
    resetMittelwert();
  }

  // wenn der mittelwert kleiner ist, dann um 1 hoch Zählen
  if (mittelwert < actionByNumberCounter) {

    if (!isCounted) {     
      count++;                      // Counter um 1 erhöhen
      isCounted = true;             // der Counter wurde um 1 erhöht            
      delay(1000);                  // Verzögerung, um schnelle Zählungen zu vermeiden

      // Serial Monitor Ausgabe
      Serial.print("Count: ");
      Serial.println(count);
    } 

  } else {
    isCounted = false;              // reseten, das der Counter um 1 erhöht wurde
  }

  // Serial Monitor Ausgabe
  if(isLDRValueShowing) {
    Serial.print("ldrValue: ");
    Serial.println(ldrValue);
    Serial.print("mittelwert: ");
    Serial.println(mittelwert);
    Serial.print("Counter: ");
    Serial.println(count);
  }
}

void resetMittelwert() {
    indexAnalogwert = 0;
    countAnalogwert = 0;
}

int getMittelwert() {
    return countAnalogwert / maxMittelwert;
}

void setMittelwert(int ldrValue) {    
    countAnalogwert = countAnalogwert + ldrValue;
    indexAnalogwert++;
}
