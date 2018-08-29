#include <Servo.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;
#define laser 1
Servo servox; 
Servo servoy; 
int rightX = 58;
int leftX = 113;
int upY = 45;
int downY = 30;
int overallPos = 0;

void setup() {
  pinMode(laser, OUTPUT);
  digitalWrite(laser, LOW);
  Wire.begin();
  RTC.begin();
  RTC.adjust(DateTime(__DATE__, __TIME__));
  servox.attach(2); // x-axis
  servoy.attach(3); // y-axis
  servox.write(leftX);
  servoy.write(downY);
}

void loop(){
  writeTime();
  overallPos = 0;
  delay(30000);
  digitalWrite(laser, LOW);
}

void writeTime() {
  DateTime now = RTC.now();
  String hour = String(now.hour(), DEC);
  String minute = String(now.minute(), DEC);
  if(hour.length() < 2){
    hour = "0" + hour;
  }
  if(minute.length() < 2){
    minute = "0" + minute;
  }
  String time =  hour + minute;
  decideNumber(time[0]);
  overallPos += 13;
  decideNumber(time[1]);
  overallPos += 13;
  decideNumber(':');
  overallPos += 3;
  decideNumber(time[2]);
  overallPos += 13;
  decideNumber(time[3]);
}

void decideNumber(char num){
  if(num == ':'){
    colon();
  }
  else if(num == '0'){
    zero();
  }
  else if(num == '1'){
    one();
  }
  else if(num == '2'){
    two();
  }
  else if(num == '3'){
    three();
  }
  else if(num == '4'){
    four();
  }
  else if(num == '5'){
    five();
  }
  else if(num == '6'){
    six();
  }
  else if(num == '7'){
    seven();
  }
  else if(num == '8'){
    eight();
  }
  else if(num == '9'){
    nine();
  }
}

void zero(){
  servox.write(110 - overallPos);
  servoy.write(32);
  delay(200);
  digitalWrite(laser, HIGH);
  delay(200);
  servoy.write(43);
  delay(200);
  servox.write(103 - overallPos);
  delay(200);
  servoy.write(32);
  delay(200);
  servox.write(110 - overallPos);
  delay(200);
  digitalWrite(laser, LOW);
}

void one(){
  servox.write(107 - overallPos);
  servoy.write(32);
  delay(200);
  digitalWrite(laser, HIGH);
  delay(200);
  servoy.write(43);
  delay(200);
  digitalWrite(laser, LOW);
}

void two(){
  servox.write(103 - overallPos);
  servoy.write(32);
  delay(200);
  digitalWrite(laser, HIGH);
  delay(200);
  servox.write(110 - overallPos);
  delay(200);
  servox.write(103 - overallPos);
  servoy.write(40);
  delay(200);
  servox.write(105 - overallPos);
  servoy.write(43);
  delay(200);
  servox.write(108 - overallPos);
  delay(200);
  servox.write(111 - overallPos);
  servoy.write(38);
  delay(200);
  digitalWrite(laser, LOW);
}

void three(){
  servox.write(110 - overallPos);
  servoy.write(32);
  delay(200);
  digitalWrite(laser, HIGH);
  delay(200);
  servox.write(103 - overallPos);
  delay(200);
  servoy.write(37);
  delay(200);
  servox.write(109 - overallPos);
  delay(200);
  servox.write(103 - overallPos);
  delay(200);
  servoy.write(43);
  delay(200);
  servox.write(110 - overallPos);
  delay(200);
  digitalWrite(laser, LOW);
}

void four(){
  servox.write(107 - overallPos);
  servoy.write(32);
  delay(200);
  digitalWrite(laser, HIGH);
  delay(200);
  servoy.write(43);
  delay(200);
  servox.write(113 - overallPos);
  servoy.write(37);
  delay(200);
  servox.write(102 - overallPos);
  delay(200);
  digitalWrite(laser, LOW);
}

void five(){
  servox.write(110 - overallPos);
  servoy.write(32);
  delay(200);
  digitalWrite(laser, HIGH);
  delay(200);
  servox.write(103 - overallPos);
  delay(200);
  servoy.write(39);
  delay(200);
  servox.write(110 - overallPos);
  delay(200);
  servoy.write(43);
  delay(200);
  servox.write(103 - overallPos);
  delay(200);
  digitalWrite(laser, LOW);
}

void six(){
  servox.write(110 - overallPos);
  servoy.write(39);
  delay(200);
  digitalWrite(laser, HIGH);
  delay(200);
  servox.write(103 - overallPos);
  delay(200);
  servoy.write(32);
  delay(200);
  servox.write(110 - overallPos);
  delay(200);
  servoy.write(43);
  delay(200);
  servox.write(103 - overallPos);
  delay(200);
  digitalWrite(laser, LOW);
}

void seven(){
  servox.write(110 - overallPos);
  servoy.write(32);
  delay(200);
  digitalWrite(laser, HIGH);
  delay(200);
  servox.write(105 - overallPos);
  servoy.write(41);
  delay(200);
  servox.write(112 - overallPos);
  delay(200);
  digitalWrite(laser, LOW);
}

void eight(){
  servox.write(103 - overallPos);
  servoy.write(32);
  delay(200);
  digitalWrite(laser, HIGH);
  delay(200);
  servoy.write(38);
  delay(200);
  servox.write(110 - overallPos);
  delay(200);
  servoy.write(43);
  delay(200);
  servox.write(103 - overallPos);
  delay(200);
  servoy.write(36);
  delay(200);
  servox.write(110 - overallPos);
  delay(200);
  servoy.write(32);
  delay(200);
  servox.write(103 - overallPos);
  delay(200);
  digitalWrite(laser, LOW);
}

void nine(){
  servox.write(103 - overallPos);
  servoy.write(32);
  delay(200);
  digitalWrite(laser, HIGH);
  delay(200);
  servoy.write(43);
  delay(200);
  servox.write(110 - overallPos);
  delay(200);
  servoy.write(39);
  delay(200);
  servox.write(103 - overallPos);
  delay(200);
  digitalWrite(laser, LOW);
}

void colon(){
  servox.write(85);
  servoy.write(35);
  delay(200);
  digitalWrite(laser, HIGH);
  delay(300);
  digitalWrite(laser, LOW);
  delay(300);
  servoy.write(40);
  delay(100);
  digitalWrite(laser, HIGH);
  delay(300);
  digitalWrite(laser, LOW);
}

