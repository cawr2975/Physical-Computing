/*
   IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
   An IR detector/demodulator must be connected to the input RECV_PIN.
   Version 0.1 July, 2009
   Copyright 2009 Ken Shirriff
   http://arcfn.com
*/

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;
bool threeOn = false;
bool fourOn = false;
bool fiveOn = false;
void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
//    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  if (results.value == 0xa90 && fourOn == false) {
    Serial.println("Button 4 pressed - Low Flash");
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    fiveOn = false;
    fourOn = true;
    threeOn = false;
  }
  else if (results.value == 0xa88 && fiveOn == false) {
    Serial.println("Button 5 pressed - Medium Flash");
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    fiveOn = true;
    fourOn = false;
    threeOn = false;
  }
  else if (results.value == 0xa86 && threeOn == false) {
    Serial.println("Button 3 pressed - High Flash");
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH );
    fiveOn = false;
    fourOn = false;
    threeOn = true;
  }
  delay(100);
}
