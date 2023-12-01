/*  Beispiel für einen Taster (ESP32)
 * 
 *  Die Bibliothek "Bounce2" verhintert das der Taster mehrmals um 1 hoch Zählt, 
 *  wenn der Taster gedrückt ist
 */

#include <Bounce2.h>

// Pins
const int buttonPin = 33;                 // Taster Pin

int count = 0;                            // wie oft wurde der Taster gedrückt

Bounce buttonBounce = Bounce();            // initialisiere die Bibliothek "Bounce2"

void setup() {
  Serial.begin(115200);

  pinMode(buttonPin, INPUT);

  buttonBounce.attach(buttonPin);
  buttonBounce.interval(10);
}

void loop() {

  buttonCountAction();
  delay(5);

}

void buttonCountAction(){
  buttonBounce.update();
  if (buttonBounce.fell()) {
    
    count = 0;   
    count++;
  }

  Serial.print("Counter: "); 
  Serial.println(count); 
}


