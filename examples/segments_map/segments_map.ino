#include <HT1621.h>
#include "segments.h"

#define DELAY 150

uint8_t drawing_segments[] = {
  SEG_TWO_POINTS_1, SEG_PADLOCK, SEG_MICROPHONES, 
  SEG_DDIGITAL, SEG_PROG, SEG_TOTAL, SEG_MP3, 
  SEG_CD, SEG_VCD, SEG_REPEAT, SEG_CAMCORDER, 
  SEG_PLAY, SEG_PAUSE, SEG_ALL,SEG_TWO_POINTS_2, 
  SEG_DTS, SEG_DVD
};
uint8_t As_segments[] = {
  D0A, D1A, D2A, D3A, D4A, D5A, D6A, D7A, D8A
};
uint8_t Bs_segments[] = {
  D0B, D1B, D2B, D3B, D4B, D5B, D6B, D7B, D8B
};
uint8_t Cs_segments[] = {
  D0C, D1C, D2C, D3C, D4C, D5C, D6C, D7C, D8C
};
uint8_t Ds_segments[] = {
  D0D, D1D, D2D, D3D, D4D, D5D, D6D, D7D, D8D
};
uint8_t Es_segments[] = {
  D0E, D1E, D2E, D3E, D4E, D5E, D6E, D7E, D8E
};
uint8_t Fs_segments[] = {
  D0F, D1F, D2F, D3F, D4F, D5F, D6F, D7F, D8F
};
uint8_t Gs_segments[] = {
  D0G, D1G, D2G, D3G, D4G, D5G, D6G, D7G, D8G
};
uint8_t d0 [] = {
  D0A, D0B, D0C, D0D, D0E, D0F, D0G
};
uint8_t d1 [] = {
  D1A, D1B, D1C, D1D, D1E, D1F, D1G
};
uint8_t d2 [] = {
  D2A, D2B, D2C, D2D, D2E, D2F, D2G
};
uint8_t d3 [] = {
  D3A, D3B, D3C, D3D, D3E, D3F, D3G
};
uint8_t d4 [] = {
  D4A, D4B, D4C, D4D, D4E, D4F, D4G
};
uint8_t d5 [] = {
  D5A, D5B, D5C, D5D, D5E, D5F, D5G
};
uint8_t d6 [] = {
  D6A, D6B, D6C, D6D, D6E, D6F, D6G
};
uint8_t d7 [] = {
  D7A, D7B, D7C, D7D, D7E, D7F, D7G
};
uint8_t d8 [] = {
  D8A, D8B, D8C, D8D, D8E, D8F, D8G
};
uint8_t demo[] = {
  D0C, 
  D0D, D1D, D2D, D3D, D4D, D5D, D6D, D7D, D8D,
  D8E, 
  D8G, D7G, D6G, D5G, D4G, D3G, D2G, D1G, D0G,
  D0B,
  D0A, D1A, D2A, D3A, D4A, D5A, D6A, D7A, D8A,
  D8F,
  D8C, D8B, D7F, D7E, D7C, D7B, D6F, D6E, D6C, D6B, D5F, D5E, D5C, D5B, D4F, D4E, D4C, D4B, D3F, D3E, D3C, D3B, D2F, D2E, D2C, D2B, D1F, D1E, D1C, D1B, D0F, D0E
};

HT1621 ht(9,8,7); // STRB, CLK, DATA

void clearDisplay()
{
  for (int k = 0 ; k < 21 ; k++) {
    ht.write(k, 0x0);
  }
}

void setup()
{
  ht.begin();
  ht.sendCommand(HT1621::BIAS_HALF_4_COM);
  ht.sendCommand(HT1621::SYS_EN);
  ht.sendCommand(HT1621::LCD_ON);
}

void loop()
{
  /*
   * Show drawings only
   */
  for(int i=0; i<sizeof(drawing_segments); i++){
    ht.write(drawing_segments[i]/8, 1<<(drawing_segments[i]%8));
    delay(DELAY);
    clearDisplay();
  }

  /*
   * Show similar segments
   */
  for(int i=0; i<9; i++){
    ht.write(As_segments[i]/8, 1<<(As_segments[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  for(int i=0; i<9; i++){
    ht.write(Bs_segments[i]/8, 1<<(Bs_segments[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  for(int i=0; i<9; i++){
    ht.write(Cs_segments[i]/8, 1<<(Cs_segments[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  for(int i=0; i<9; i++){
    ht.write(Ds_segments[i]/8, 1<<(Ds_segments[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  for(int i=0; i<9; i++){
    ht.write(Es_segments[i]/8, 1<<(Es_segments[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  for(int i=0; i<9; i++){
    ht.write(Fs_segments[i]/8, 1<<(Fs_segments[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  for(int i=0; i<9; i++){
    ht.write(Gs_segments[i]/8, 1<<(Gs_segments[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  for(int i=0; i<7; i++){
    ht.write(d0[i]/8, 1<<(d0[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  
  /*
   * Show, for each digit, the segments one by one
   */
  for(int i=0; i<7; i++){
    ht.write(d1[i]/8, 1<<(d1[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  for(int i=0; i<7; i++){
    ht.write(d2[i]/8, 1<<(d2[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  for(int i=0; i<7; i++){
    ht.write(d3[i]/8, 1<<(d3[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  for(int i=0; i<7; i++){
    ht.write(d4[i]/8, 1<<(d4[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  for(int i=0; i<7; i++){
    ht.write(d5[i]/8, 1<<(d5[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  for(int i=0; i<7; i++){
    ht.write(d6[i]/8, 1<<(d6[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  for(int i=0; i<7; i++){
    ht.write(d7[i]/8, 1<<(d7[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  for(int i=0; i<7; i++){
    ht.write(d8[i]/8, 1<<(d8[i]%8));
    delay(DELAY);
    clearDisplay();
  }
  

  for(int i=0, j=0; i<sizeof(demo); i++){
    ht.write(demo[i]/8, ht.read(demo[i]/8)|1<<(demo[i]%8));
    delay(DELAY);
    //clearDisplay(demo[i]/8,demo[i]/8 +1);
  }
  for(int i=0, j=0; i<sizeof(demo); i++){
    ht.write(demo[i]/8, ht.read(demo[i]/8)&(~(1<<(demo[i]%8))) );
    delay(DELAY);
  }
  delay(DELAY);
}
