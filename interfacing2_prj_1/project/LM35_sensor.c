/*
 * LM35_sensor.c
 *
 *  Created on: Oct 5, 2022
 *      Author: dell
 */

#include "LM35_sensor.h"
#include "adc.h"
#include "common_macros.h"
#include "util/delay.h"

uint8 LM35_get_temp()
{
	uint8 temp_val = 0;
	uint16 adc_val = 0;
	adc_val = ADC_readchannel(SENSOR_CHANNEL_ID);
	_delay_ms(5);
	temp_val = (uint8)( ( (uint32)adc_val*SENSOR_MAX_TEMP*ADC_VOLT_REF ) / ( SENSOR_MAX_VOLT*ADC_MAX_DIG_VAL) );
	return temp_val;
}
