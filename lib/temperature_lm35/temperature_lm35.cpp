#include <Arduino.h>
#include "esp_adc_cal.h"

int lm35_raw_sensor = 0;
float voltage = 0.0;
float lm35_temperature = 0.0;

uint32_t readADC_Cal(int ADC_Raw)
{
	esp_adc_cal_characteristics_t adc_chars;
	esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, &adc_chars);

	return esp_adc_cal_raw_to_voltage(ADC_Raw, &adc_chars);
}

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