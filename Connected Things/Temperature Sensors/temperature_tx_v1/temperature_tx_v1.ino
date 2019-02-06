/*
  433 MHz RF Module Transmitter Demonstration 2
  RF-Xmit-Demo-2.ino
  Demonstrates 433 MHz RF Transmitter Module with DHT-22 Sensor
  Use with Receiver Demonstration 2
   adapted from
  https://dronebotworkshop.com/433mhz-rf-modules-arduino/
*/

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>

// Define Constants


// Define Variables

int analogIn;    // stores input values
int digitalIn;

int aPin = A0;
int dPin = 2;

// Define output strings

String str_analogIn = "0000";
String str_digitalIn = "0";
String str_out;

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
int counter = 0;

void setup() {

  // Initialize ASK Object
  rf_driver.init();

  // initialize digital pin to use an internal pullup
  pinMode(dPin, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.print("started serial at 9600...");

}

void loop()
{

  delay(500);

  analogIn = analogRead(aPin);  // Get analog value
  digitalIn = digitalRead(dPin);  // Get digital value

  // Convert analog read integer to string
  if (analogIn < 1000 && analogIn > 99) {
    str_analogIn = "0" + String(analogIn);
  }
  else if (analogIn < 100 && analogIn > 9) {
    str_analogIn = "00" + String(analogIn);
  }
  else if (analogIn < 10) {
    str_analogIn = "000" + String(analogIn);
  }
  else { //uses 4 digits
    str_analogIn = String(analogIn);
  }

  str_digitalIn = String(digitalIn);
  
  // Combine analog and digital sensors into one string (payload)
  str_out = "cgw1" + str_analogIn + "," + str_digitalIn;
  String str_analogIn2 = "9999";
  String str_digitalIn2 = "2";
  String str_out2 = "cgw2" + str_analogIn2 + "," + str_digitalIn2;
  String str_analogIn3 = "00" + String(int(random(65, 80)));
  String str_digitalIn3 = "3";
  String str_out3 = "cgw3" + str_analogIn3 + "," + str_digitalIn3;

  // Compose output character
  static char *msg1 = str_out.c_str();
  static char *msg2 = str_out2.c_str();
  static char *msg3 = str_out3.c_str();
  Serial.print("Sending: ");
  Serial.print(msg1);
  Serial.print("  ");
  Serial.print(msg2);
  Serial.print("  ");
  Serial.println(msg3);
  rf_driver.send((uint8_t *)msg1, strlen(msg1));
  rf_driver.waitPacketSent();
  delay(200);
  rf_driver.send((uint8_t *)msg2, strlen(msg2));
  rf_driver.waitPacketSent();
  delay(200);
  rf_driver.send((uint8_t *)msg3, strlen(msg3));
  rf_driver.waitPacketSent();
  delay(200);
//  if(counter == 7 || counter == 17 || counter == 21){
//  static char *msg = str_out2.c_str();
//  Serial.print("sending message: ");
//  Serial.println(msg);
//  Serial.print("message length: ");
//  Serial.println(strlen(msg));
//
//  rf_driver.send((uint8_t *)msg, strlen(msg));
//  rf_driver.waitPacketSent();
//  }
//  else{
//  static char *msg = str_out.c_str();
//  Serial.print("sending message: ");
//  Serial.println(msg);
//  Serial.print("message length: ");
//  Serial.println(strlen(msg));
//
//  rf_driver.send((uint8_t *)msg, strlen(msg));
//  rf_driver.waitPacketSent();
//  }
//  counter++;
//  if(counter == 30){
//    counter = 0;
//  }

}
