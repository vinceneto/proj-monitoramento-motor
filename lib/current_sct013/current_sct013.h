/**
 * @file current_sct013.h
 * @brief Biblioteca do sensor de corrente Não-invasivo SCT013-20A
 * @version 0.1
 * @date 2022-10-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Função de inicialização do sensor de corrente
 * 
 * @param sensor_pin Pino do ESP32
 * @param factor_calibration Fator de calibração para leituras do sensor de corrente
 */
void sct013_begin(int sensor_pin, float factor_calibration);

/**
 * @brief Get the current object
 * 
 * @return float Retorna o valor lido do sensor de corrente
 */
float get_current();