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

/**
 * @brief Get the temperature object
 * 
 * @param sensor_pin Pino do ESP32
 * @return float Retorna o valor lido de temperatura
 */
float get_temperature(int sensor_pin);