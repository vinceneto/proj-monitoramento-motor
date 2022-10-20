/**
 * @file temperature_lm35.cpp
 * @author your name (you@domain.com)
 * @brief Biblioteca do sensor de temperatura LM35
 * @version 0.1
 * @date 2022-10-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>
#include "esp_adc_cal.h"

int lm35_raw_sensor = 0;
float voltage = 0.0;
float lm35_temperature = 0.0;

/**
 * @brief Função de configuração do pino ADC do ESP32
 * 
 * @param ADC_Raw Variável que irá armazenar o valor de tensão (mV)
 * @return uint32_t Retorna o valor do tensão em mV
 */
uint32_t readADC_Cal(int ADC_Raw)
{
	esp_adc_cal_characteristics_t adc_chars;
	esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, &adc_chars);

	return esp_adc_cal_raw_to_voltage(ADC_Raw, &adc_chars);
}

/**
 * @brief Get the temperature object
 * 
 * @param sensor_pin Pino do ESP32
 * @return float Retorna o valor lido de temperatura
 */
float get_temperature(int sensor_pin)
{
	/* Lê o pino ADC do sensor LM35 */
	lm35_raw_sensor = analogRead(sensor_pin);

	/* Calibração ADC e captura a tensão (em mV) */
	voltage = readADC_Cal(lm35_raw_sensor);

	/* Temperatura em Celsius */
	lm35_temperature = voltage / 10;

	return lm35_temperature;
}