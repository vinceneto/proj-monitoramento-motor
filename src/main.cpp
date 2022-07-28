#include <Arduino.h>

// This example shows how to connect to Cayenne using an ESP32 and send/receive sample data.
// Make sure you install the ESP32 Board Package and select the correct ESP32 board before compiling.
// To install the ESP32 Board Package follow the instructions here: https://github.com/espressif/arduino-esp32/blob/master/README.md#installation-instructions.

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP32.h>

// WiFi network info.
char ssid[] = "SSID";
char wifiPassword[] = "Senha";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "c2b28380-db01-11e9-ba7c-716e7f5ba423";
char password[] = "833101c2884519f76212d39e3f91096dba7442bf";
char clientID[] = "2b7860a0-8af6-11ec-8c44-371df593ba58";

unsigned long lastMillis = 0;

#define VIRTUAL_CHANNEL 0
#define ACTUATOR_PIN 2 // Do not use digital pins 0 or 1 since those conflict with the use of Serial.

void setup() {
	Serial.begin(9600);
  pinMode(ACTUATOR_PIN, OUTPUT);
	Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

void loop() {
	Cayenne.loop();
}

// This function is called when data is sent from Cayenne.
CAYENNE_IN(VIRTUAL_CHANNEL)
{
	int value = getValue.asInt();
	CAYENNE_LOG("Channel %d, pin %d, value %d", VIRTUAL_CHANNEL, ACTUATOR_PIN, value);
	// Write the value received to the digital pin.
	digitalWrite(ACTUATOR_PIN, value);
}

// This function is called at intervals to send data to Cayenne and keep the device online.
// Will create a temporary green widget on Channel 0, make it permanent by clicking on '+'. 
CAYENNE_OUT(0)
{
	CAYENNE_LOG("Send data for Virtual Channel 0");
	// This command writes the device's uptime in seconds to the Virtual Channel. 
	Cayenne.virtualWrite(0, millis() / 1000);
}
