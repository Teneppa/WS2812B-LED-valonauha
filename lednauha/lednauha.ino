#include <Adafruit_NeoPixel.h>

#define PINNI 4           // Kytke ledinauhan datapinniin (yleensä DIN pinni)
#define LEDIEN_MAARA 7   // Kuinka monta led-valoa nauhassa on?

Adafruit_NeoPixel lednauha = Adafruit_NeoPixel(LEDIEN_MAARA, PINNI, NEO_GRB + NEO_KHZ800);

const uint32_t white = lednauha.Color(255,255,255);   // Color-funktiossa parametrit ovat
                                                      // Color(punainen, vihreä, sininen)
                                                      // Arvot ovat välillä 0-255
const uint32_t gold = lednauha.Color(253,156,0);

/* Tämä funktio suoritetaan vain kerran, kun Arduino käynnistetään. */
void setup() {
  lednauha.begin(); // Näyttäisi asettavan datapinnin ulostuloksi
}

/* Tämä funktio toistuu ajon aikana */
void loop() {
  //fill(white); // Täytä koko ledinauha valkoisella värillä  
  shoot(gold,40);
}
