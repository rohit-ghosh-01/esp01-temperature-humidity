//esp01 : GPIO 0,1,2,3
#include<TM1637Display.h>
#include<DHT.h>
DHT dht(3,DHT11);
TM1637Display display=TM1637Display(0,1);//clk,dio
float t=0,h=0;
void setup(){
  pinMode(2,OUTPUT);
  dht.begin();
  display.setBrightness(3);
  delay(1000);
}
void loop(){
  delay(100);
  t=dht.readTemperature();
  h=dht.readHumidity();
  int intpart=int(t);
  int decpart=int((t-intpart)*100);
  int combnum=intpart*100+decpart;
  display.showNumberDecEx(combnum,0b01000000,true,4,0);
  delay(1000);
  display.clear();
  delay(20);
  display.showNumberDec(h,false,4,4);
  delay(1000);
  display.clear();
}