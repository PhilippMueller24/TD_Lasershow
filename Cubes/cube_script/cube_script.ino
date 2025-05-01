//einbinden der Bibliotheken zum
//ansteuern der LED Matrix auf dem
//Arduino UNO R4 WiFi
#include "WIFI.h"
#include "Arduino_LED_Matrix.h"

//erzeugen eines ArduinoLEDMatrix Objektes
ArduinoLEDMatrix matrix;

void setup() {
  //beginn der kommunikation mit der LED Matrix
  matrix.begin();
}

void loop() {
  //beginn des zeichnens
  matrix.beginDraw();
  //alle LEDs deaktivieren
  matrix.stroke(0xFFFFFFFF);
  //Geschwindigkeit des Scrolltextes setzen
  //je niedriger der Wert desto schneller läuft der Text
  matrix.textScrollSpeed(50);

  //der Text welcher ausgegeben werden soll
  const char text[] = "    Hallo Welt!    ";
  //Schriftgröße setzen, 
  //verfügbare Werte sind:
  // - Font_4x6
  // - Font_5x7
  matrix.textFont(Font_4x6);
  //koordinate für den Text
  //je nach Schriftgröße kann man damit den Text
  //in der Matrix zentrieren
  matrix.beginText(0, 1, 0xFFFFFF);
  //Ausgeben des Textes
  matrix.println(text);
  //definieren von wo gescrollt werden soll
  matrix.endText(SCROLL_LEFT);
  //beenden des zeichnens
  matrix.endDraw();
}