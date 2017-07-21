#include <HT1621.h>
#include "segments.h"


uint8_t drawing_segments[] = {
                              SEG_TWO_POINTS_1, SEG_PADLOCK, SEG_MICROPHONES, 
                              SEG_DDIGITAL, SEG_PROG, SEG_TOTAL, SEG_MP3, 
                              SEG_CD, SEG_VCD, SEG_REPEAT, SEG_CAMCORDER, 
                              SEG_PLAY, SEG_PAUSE, SEG_ALL,SEG_TWO_POINTS_2, 
                              SEG_DTS, SEG_DVD
};
HT1621 ht(9,8,7); // STRB, CLK, DATA
void setup()
{
  ht.begin();
  ht.sendCommand(HT1621::BIAS_HALF_4_COM);
  ht.sendCommand(HT1621::SYS_EN);
  ht.sendCommand(HT1621::LCD_ON);
}

void loop()
{
  
  for (int k = 0 ; k < 21 ; k++) {
    ht.write(k, 0x0);
  }
  for(int i=0; i<sizeof(drawing_segments); i++){
    ht.write(drawing_segments[i]/8, 1<<(drawing_segments[i]%8));
    delay(250);
  }
}
