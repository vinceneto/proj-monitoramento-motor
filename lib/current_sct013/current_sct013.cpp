#include <Arduino.h>
#include "EmonLib.h"

EnergyMonitor SCT013;

void sct013_begin(int sensor_pin, float factor_calibration)
{
	SCT013.current(sensor_pin, factor_calibration); //4.9090
}

float get_current()
{
	double Irms = SCT013.calcIrms(1480);   // Calcula o valor da Corrente

	return Irms;
}

