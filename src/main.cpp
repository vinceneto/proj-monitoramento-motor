#define BLYNK_TEMPLATE_ID "TMPLlSfAXU4y"
#define BLYNK_DEVICE_NAME "Monitoramento Motor AC"
#define BLYNK_AUTH_TOKEN "qocAl0nfCwfimWIDFdidb8wHMvMspht-"

#define BLYNK_PRINT Serial

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <temperature_lm35.h>
#include <current_sct013.h>

#define current_pin		34
#define temperature_pin		35

/* Crendenciais da rede wireless */
/* Define "" para redes abertas */
char ssid[] = "";
char pass[] = "";
char auth[] = BLYNK_AUTH_TOKEN;

BlynkTimer timer;

void send_parameters() 
{
	float temperature = get_temperature(temperature_pin);
	float current = get_current();

	Blynk.virtualWrite(V0, temperature);
	Blynk.virtualWrite(V2, current);
}

void setup()
{
	Serial.begin(9600);
	sct013_begin(current_pin, 4.9090);
	Blynk.begin(auth, ssid, pass);
	timer.setInterval(1000L, send_parameters);
}

void loop()
{
	/* Executa todas as funções do Blynk */
  	Blynk.run();
	/* Executa o BlynkTimer */
	timer.run();
}
