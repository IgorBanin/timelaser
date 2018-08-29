#include <Servo.h>
#include <cQueue.h>
#define IMPLEMENTATION FIFO

#define laser 1
typedef int Item;
int incomingByte = 0;
Servo servox; 
Servo servoy; 
Queue_t q;
int sizeOfQ;

void setup() {
  Serial.begin(9600);
  pinMode(laser, OUTPUT);
  servox.attach(2); // x-axis
  servoy.attach(3); // y-axis
}

void loop() {
  servoy.write(30);
  Item value;
  q_init(&q, sizeof(Item), 10, IMPLEMENTATION, false);
  while (Serial.available() > 0) {
    incomingByte = Serial.read();
    if(incomingByte >= '0' && incomingByte <= '9'){
      value = incomingByte - '0';
      Serial.print("I received: ");
      Serial.println(value, DEC);
      q_push(&q, &value);
    }
  }
  int overall = 0;
  while(q_pop(&q, &value)) {
      overall = overall * 10 + value;
  }
  
  Serial.print("Concatenated value is: ");
  Serial.println(overall);
  delay(5000);
  servox.write(overall);

}
