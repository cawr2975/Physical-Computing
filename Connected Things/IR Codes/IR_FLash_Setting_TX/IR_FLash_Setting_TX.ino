/*
   IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
   An IR LED must be connected to Arduino PWM pin 3.
   Version 0.1 July, 2009
   Copyright 2009 Ken Shirriff
   http://arcfn.com
*/


#include <IRremote.h>

IRsend irsend;
bool fourPressed = false;
bool fivePressed = false;
bool sixPressed = false;

void setup() {
  Serial.begin(9600);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  Serial.print("Serial Monitor Started - ");
}

void loop() {
  if (digitalRead(4) == HIGH && fourPressed == false) {
    Serial.println("Button 4 pressed");
    for (int i = 0; i < 3; i++) {
      irsend.sendSony(0xa90, 12);
      fourPressed = true;
      fivePressed = false;
      sixPressed = false;
      delay(40);
    }
  }
  if (digitalRead(5) == HIGH && fivePressed == false) {
    Serial.println("Button 5 pressed");
    for (int i = 0; i < 3; i++) {
      irsend.sendSony(0xa88, 12);
      fourPressed = false;
      fivePressed = true;
      sixPressed = false;
      delay(40);
    }
  }
  if (digitalRead(6) == HIGH && sixPressed == false) {
    Serial.println("Button 6 pressed");
    for (int i = 0; i < 3; i++) {
      irsend.sendSony(0xa86, 12);
      fourPressed = false;
      fivePressed = false;
      sixPressed = true;
      delay(40);
    }
  }
}
