/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  Note: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "b26ee18e2fd843279f909619aa0a6f9d";
// Lamp 1 ID: b26ee18e2fd843279f909619aa0a6f9d
// Lamp 2 ID: da6ec2c5af2942739133db463dea6ab4

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "BTUgoo";
char pass[] = "blowItUp";
WidgetBridge bridge2(V2);

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  while (Blynk.connect() == false) {

  }
  for (int i = 0; i < 10; i++) {
    bridge2.digitalWrite(12, HIGH);
    delay(1000);
    bridge2.digitalWrite(12, LOW);
    delay(1000);
  }
}

BLYNK_CONNECTED() {
  bridge2.setAuthToken("da6ec2c5af2942739133db463dea6ab4");
}
void loop()
{
  Blynk.run();
}
