/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Projeto de Monitoramento de controle de motor AC utilizando ESP32 e a plataforma Blynk
 * @version 0.1
 * @date 2022-10-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Diretiva para o funcionamento da plataforma Blynk*/
#define BLYNK_TEMPLATE_ID "TMPLlSfAXU4y"
#define BLYNK_DEVICE_NAME "Monitoramento Motor AC"
#define BLYNK_AUTH_TOKEN "qocAl0nfCwfimWIDFdidb8wHMvMspht-"
#define BLYNK_PRINT Serial

/*Bibliotecas necessárias para o funcionamento*/
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <temperature_lm35.h>
#include <current_sct013.h>

#define current_pin			34
#define temperature_pin		35

/* Crendenciais da rede wireless */
/* Define "" para redes abertas */
char ssid[] = "";
char pass[] = "";
char auth[] = BLYNK_AUTH_TOKEN;

BlynkTimer timer;

/*Função para envio dos dados para a plataforma Blynk*/
void send_parameters() 
{
	float temperature = get_temperature(temperature_pin);
	float current = get_current();

	Blynk.virtualWrite(V0, temperature);
	Blynk.virtualWrite(V2, current);
}

/*Função de configuração*/
void setup()
{
	Serial.begin(9600);
	sct013_begin(current_pin, 4.9090);
	Blynk.begin(auth, ssid, pass);
	timer.setInterval(1000L, send_parameters);
}

/*Loop*/
void loop()
{
	/* Executa todas as funções do Blynk */
  	Blynk.run();
	/* Executa o BlynkTimer */
	timer.run();
}
