#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <temperature_lm35.h>

#define BLYNK_TEMPLATE_ID "TMPLlSfAXU4y"
#define BLYNK_DEVICE_NAME "Monitoramento Motor AC"
#define BLYNK_AUTH_TOKEN "qocAl0nfCwfimWIDFdidb8wHMvMspht-"

#define BLYNK_PRINT Serial

#define temperature_pin		35

/* Crendenciais da rede wireless */
/* Define "" para redes abertas */
char ssid[] = "NETO_WIRELESS";
char pass[] = "Netosm031214";
char auth[] = BLYNK_AUTH_TOKEN;

BlynkTimer timer;

void send_parameters() 
{
	float temperature = get_temperature(temperature_pin);

	Blynk.virtualWrite(V0, temperature);
}

void setup()
{
	Serial.begin(9600);
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