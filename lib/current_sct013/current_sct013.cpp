/**
 * @file current_sct013.cpp
 * @brief Biblioteca do sensor de corrente Não-invasivo SCT013-20A
 * @version 0.1
 * @date 2022-10-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>
#include "EmonLib.h"

EnergyMonitor SCT013;

/**
 * @brief Função de inicialização do sensor de corrente
 * 
 * @param sensor_pin Pino do ESP32
 * @param factor_calibration Fator de calibração para leituras do sensor de corrente
 */
void sct013_begin(int sensor_pin, float factor_calibration)
{
	SCT013.current(sensor_pin, factor_calibration); //4.9090
}

/**
 * @brief Get the current object
 * 
 * @return float Retorna o valor lido do sensor de corrente
 */
float get_current()
{
	double Irms = SCT013.calcIrms(1480);   // Calcula o valor da Corrente

	return Irms;
}

