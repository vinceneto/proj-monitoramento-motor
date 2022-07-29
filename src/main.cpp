#include <Arduino.h>

#define BLYNK_TEMPLATE_ID "TMPL2aL37KLm"
#define BLYNK_DEVICE_NAME "LED BUILTIN"
#define BLYNK_AUTH_TOKEN "dJEkKMfVdqIMu2hagBlOHkOmB_RhJVRg"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial
#define led         2

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ssid";
char pass[] = "password";

char auth[] = BLYNK_AUTH_TOKEN;

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  pinMode(led, OUTPUT);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0) // Executes when the value of virtual pin 0 changes
{
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(led,HIGH);  // Set digital pin 2 HIGH
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(led,LOW);  // Set digital pin 2 LOW    
  }
}