# Lichtschranke
Das ist ein Beispiel, wie man eine Lichtschranke für den ESP32 beteiben kann.
 
Es wird ein Analogwert vom LDR-Sensor ausgelesen, dieser Analogwert wird addiert und daraus ein Mittelwert berechnet.
Wenn dieser Mittelwert unterschritten wird, dann zählt der Counter um 1 Hoch.
Die Mittelwert-Berechnung wird gemacht, um Fehler beim auslesen vom LDR-Sensor zu vermeiden,  
da der Wert manchmal unterschritten wurde, obwohl es kein unterbruch der Lichtschranke gab.

<br>
<br>

## Bibliotheken die noch installiert werden müssen
| Nr. | Import                  |                    Name                     | Version |     Bemerkungen   |
|:---:| :---:                   |---------------------------------------------|  :---:  |        :---:      |
|  1  | Bounce2.h               | Bounce2 von Thomas O Fredericks             | v2.7.1  |                   |

<br>
<br>

# Stückliste

| Nr. | Menge |         Bauteil                                     |                    Links                                                                                                |                                                      Daten                          |       Bemerkung          |
|:---:| :---: |-----------------------------------------------------|                    :---:                                                                                                |                                                      :---:                          |         :---:            |
|  1  |   1   | Einbausteckverbinder (LUT 0830 T8CW04)              | [Link](https://www.reichelt.de/ch/de/einbausteckverbinder-m8-4-pol-stecker-0-5-m-lut-0830-t8cw04-p223100.html?&nbc=1)   | [Datenblatt](https://cdn-reichelt.de/documents/datenblatt/C152/0830_T8CW_.pdf)      |                          |
|  2  |   1   | Sensorleitung (LUT 0800 0 2)                        | [Link](https://www.reichelt.de/ch/de/sensorleitung-m8-4-pol-ku-offenes-ende-2-m-lut-0800-0-2-p223058.html?&nbc=1)       | [Datenblatt](https://cdn-reichelt.de/documents/datenblatt/C152/0800_0_.pdf)         |                          |
|  3  |   1   | Rotpunktdiode Led                                   | [Link](https://www.amazon.de/dp/B09L4WRB1Q)                                                                             |                                                                                     |                          |
|  4  |   1   | Lichtabhängige LDR Fotowiderstand                   | [Link](https://www.amazon.de/dp/B00NXW9WZ6)                                                                             |                                                                                     |                          |
|  5  |   1   | SPAX Universalschraube 2,5 x 10 mm (1081010250105)  | [Link](https://www.amazon.de/dp/B007259RFU)                                                                             |                                                                                     |                          |
|  6  |   1   | 1 KΩ Widerstand                                     |                                                                                                                         |                                                                                     |  für LDR Fotowiderstand  |  
|  7  |   1   | 100 KΩ Widerstand                                   |                                                                                                                         |                                                                                     |  für Taster              |  

<br>
<br>

### Gabellichtschranke
<img src="https://github.com/Indivikar/IoT_Examples/blob/main/Lichtschranke/images/Lichtschranke.png" width="49%"></img> 
<img src="https://github.com/Indivikar/IoT_Examples/blob/main/Lichtschranke/images/Gabellichtschranke Vorlage.png" width="49%"></img>

<img src="https://github.com/Indivikar/IoT_Examples/blob/main/Lichtschranke/images/Lichtschranke_1.jpg" width="33%"></img> 
<img src="https://github.com/Indivikar/IoT_Examples/blob/main/Lichtschranke/images/Lichtschranke_2.jpg" width="33%"></img> 
<img src="https://github.com/Indivikar/IoT_Examples/blob/main/Lichtschranke/images/Lichtschranke_3.jpg" width="33%"></img> 

<br>
<br>

### Bauteile
<img alt="Girl in a jacket" src="https://github.com/Indivikar/IoT_Examples/blob/main/Lichtschranke/images/LDR_Fotowiderstand.jpg" width="23%"></img> 
<img src="https://github.com/Indivikar/IoT_Examples/blob/main/Lichtschranke/images/Rotpunktdiode_LED_1.jpg" width="23%"></img> 
<img src="https://github.com/Indivikar/IoT_Examples/blob/main/Lichtschranke/images/Einbausteckverbinder.jpg" width="23%"></img> 
<img src="https://github.com/Indivikar/IoT_Examples/blob/main/Lichtschranke/images/Sensorleitung.jpg" width="23%"></img> 

<br>
<br>

### Elektroplan
![alt text](https://github.com/Indivikar/IoT_Examples/blob/main/Lichtschranke/images/lichtschranke_Schema.png?raw=true)
