
/*ds3231 RTC clock setup*/
//include these header files

#include <Wire.h>
#include <ds3231.h>          
 
struct ts rtc; 
 
void setup() {
  Serial.begin(9600);
  Wire.begin();
  DS3231_init(DS3231_CONTROL_INTCN);
 //-----------------------------------------//
 //once uploade code this line comment and uploade this code again  to arduino 

 //start
rtc.hour  =       8; 
rtc.min   =      24;
rtc.sec   =       0;
rtc.mday  =      30;
rtc.mon   =       4;
rtc.year  =    2022;
DS3231_set(rtc);

//end ,comment these lines
}

void loop() {
  DS3231_get(&rtc);
  Serial.print("Date : ");
  Serial.print(rtc.mday);
  Serial.print("/");
  Serial.print(rtc.mon);
  Serial.print("/");
  Serial.print(rtc.year);
  Serial.print("\t Hour : ");
  Serial.print(rtc.hour);
  Serial.print(":");
  Serial.print(rtc.min);
  Serial.print(".");
  Serial.println(rtc.sec);
  delay(1000);
}
