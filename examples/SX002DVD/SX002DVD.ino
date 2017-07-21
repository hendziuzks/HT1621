#include <math.h>
#include <HT1621.h>
HT1621 ht(9,8,7); // STRB, CLK, DATA

int num_char[]={
  0xF5, 0x05, 0xB6, 0x97, 0x47, 0xD3, 0xF3, 0x85, 0xF7, 0xC7, 0xE7, 0xF7, 0xF0, 0xF5, 0xF2, 0xE2
};
int minusOne = 0x02;
int buff[]={0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void setNum(int pos, int num){
  if(num==-1){
    buff[pos] = (minusOne&0x0F) | (buff[pos]&0xF0);
    buff[pos+1] = (minusOne&0xF0) | (buff[pos+1]&0x0F);
  }
  else{
    buff[pos] = (num_char[num]&0x0F) | (buff[pos]&0xF0);
    buff[pos+1] = (num_char[num]&0xF0) | (buff[pos+1]&0x0F);
  }
  ht.write(pos+0, buff[pos]);
  ht.write(pos+1, buff[pos+1]);
}
void printNum(long num){
  bool isNegative=false;
  int i;
  if(num<0){
    isNegative = true;
    num *= -1;
  }
  for (i = 0 ; i<=8&&num>0 ; i++) {
    int adr = i;
    setNum(adr, num % 10);
    num /= 10;
  }
  if(isNegative)
     setNum(i, -1);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ht.begin();
  ht.sendCommand(HT1621::BIAS_HALF_4_COM);
  ht.sendCommand(HT1621::SYS_EN);
  ht.sendCommand(HT1621::LCD_ON);
  for (int k = 0 ; k < 21 ; k++) {
    ht.write(k, 0x0);
  }
  
}

void loop() {
  long i;
  for(i=0; i<10000; i++){
    printNum(i);
    //ht.printNumber(i, 4, 0, false);
    delay(10);
  }
}
