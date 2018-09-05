/* Igor Banin
 * 8/28/2018
 * Time Laser Display
 * 
 * Displays the time in 24hr format on a glow in the dark sticker sheet 
 * using an ultraviolet laser. This class stores the functionality 
 * of breaking down the information received from the tiny RTC, determining
 * which numbers need to be drawn, and drawing those numbers using x and y
 * servo motor movements.
 */

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
int overallPos = 0; //Variable responsible for determining character position. 

/* Initializes the laser, tiny RTC, and servo motors.
 * Places the servo motors in their starting location, adjusts the RTC
 * and turns off the laser.
 */
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

// Writes out the time in 24hr format every 30 seconds.
void loop(){
  writeTime();
  overallPos = 0;
  delay(30000);
  digitalWrite(laser, LOW);
}

/* Processes information taken from the tiny RTC to determine which numbers 
 * should be displayed, and writes those numbers on the sticker sheet.
 */
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

/*  Given a character, calls on the methods responsible for writing that character
 *  on the sticker sheet.
 *  num: character to be written
 */
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

/* The characters are written onto the sticker sheet by turning the laser on/off 
 * and using x and y servo movements. 
 */
 
// Writes out 0 on the sticker sheet.
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


// Writes out 1 on the sticker sheet.
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


// Writes out 2 on the sticker sheet.
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


// Writes out 3 on the sticker sheet.
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


// Writes out 4 on the sticker sheet.
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


// Writes out 5 on the sticker sheet.
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


// Writes out 6 on the sticker sheet.
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


// Writes out 7 on the sticker sheet.
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


// Writes out 8 on the sticker sheet.
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


// Writes out 9 on the sticker sheet. 
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


// Writes out a : on the sticker sheet. 
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
