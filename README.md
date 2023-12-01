# IoT_Examples
Hier möchte ich einige Beispiele für den Arduino, ESP32, RasPi, usw... veröffentlichen

<br>
<br>

## ESP32
Ich nutze immer den `ESP32 WROOM Generic DevKit`

Zum programmieren der ESP32 benutze ich die [Arduino IDE 2](https://www.arduino.cc/en/software#future-version-of-the-arduino-ide).
Nach der Installation der Arduino IDE müssen noch ein paar einstellungen vorgenommen werden.

<br>

### ESP32 (mit CP2102) Treiber installieren
1. Den [ESP32-Treiber](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads) (CP210x Universal Windows Driver) runterladen und entpacken
2. Den ESP32 mit einem USB-Kabel an den Rechner anschliessen
3. Den Geräte-Manager öffnen (Windows-Taste + X > Geräte-Manager)
4. In der Liste, unter "Anschlüsse (COM & LPT)" sollte der ESP32 mit einer Warnung stehen
5. Rechts-Klick > Treiber aktualisieren > Auf meinem Computer nach Treibern suchen
6. Durchsuchen... > [den Ordner mit Treiber auswählen] > Weiter
7. Nach der Installation sollte die Warnung im Geräte-Manager weg sein und können fortfahren

<br>

### ESP32 in der Arduino IDE installieren
1. Gehe in der Arduino IDE 2.0 zu Datei > Einstellungen
2. Kopiere die folgende Zeile und füge sie in das Feld „Zusätzlicher Boardverwalter-URLs“ ein und bestätige mit OK
`https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
3. Gehe in der Arduino IDE 2.0 zu Werkzeuge > Board > Board-Verwaltung
4. In der Liste nach "esp32 von Espressif" suchen und installieren

<br>

### Arduino IDE Konfiguration für den ESP32
Die Konfiguration kann unter dem Menü-Punkt `Werkzeuge` vorgenommen werden.
- Board:              `ESP32 Dev Module`
- CPU Frequency:      `240MHz (WiFi/BT)`
- Core Debug Level:   `None`
- Flash Frequency:    `80MHz`
- Flash Mode:         `QIO`
- Flash Size:         `4MB (32Mb)`
- Partition Scheme:   `Default 4MB with spiffs (1.2MB APP/1.5MB SPIFFS)`
- PSRAM:              `Disable`
- Upload Speed:       `921600`

<br>

### Pinout [(Link zur ausführlichen Info)](https://www.upesy.com/blogs/tutorials/esp32-pinout-reference-gpio-pins-ultimate-guide)
![alt text](https://github.com/Indivikar/IoT_Examples/blob/main/esp32-pinout-wroom-devkit.webp?raw=true)
