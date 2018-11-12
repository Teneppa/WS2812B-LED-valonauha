uint8_t suunta = 1; //suunta shoot-funktiolle
                    // 1 = poispäin ledinauhan juuresta ja 0 = takaisin

/* Vaihda kaikki ledit tietyksi väriksi */
void fill(uint32_t color) {
  for(uint16_t x = 0; x < LEDIEN_MAARA; x++) {
    lednauha.setPixelColor(x,color);  // Aseta ledin numero x väriksi color
                                      // Tämä ei vielä tee muutoksia, vaan päivittää
                                      // Arduinossa olevaa puskuria
                                      
    lednauha.show();                  // Tämä lähettää koko puskurin ledinauhalle
  }
}

/*  Sytytä yksi ledi ja liikuta sitä ledinauhan päästä päähän.
*   spd määrittää, kuinka monta millisekuntia yksi ledi palaa
*/
void shoot(uint32_t color, int spd){
  
  if(suunta == 1) { // kun suunta on poispäin
    
    for(uint8_t i=0; i<LEDIEN_MAARA; i++) { // käy kaikki ledit läpi
      fill(0);                              // Sammuta kaikki ledit
      lednauha.setPixelColor(i,color);      // Aseta ledi numero i väriksi color
      lednauha.show();                      // Lähetä puskuri nauhalle
      delay(spd);                           // Odota
    }
    
  }else{        // kun suunta on takaisinpäin

    for(uint8_t i=LEDIEN_MAARA-1; i>0; i--) { // käy kaikki ledit läpi (tällä kertaa suunta on toinen)
      fill(0);                                // Sammuta kaikki ledit
      lednauha.setPixelColor(i,color);        // Aseta ledi numero i väriksi color
      lednauha.show();                        // Lähetä puskuri nauhalle
      delay(spd);                             // Odota
    }

  }

  suunta = 1-suunta; // Vaihda suuntaa kun valo on jommassa kummassa päässä
}
