/*
 * adc.c
 *
 *  Created on: Oct 5, 2022
 *      Author: dell
 */

#include "common_macros.h"
#include "adc.h"
#include "avr/io.h"

void ADC_init(const ADC_ConfigType* Config_ptr)
{
	ADMUX = (ADMUX & 0x3F) | ( (Config_ptr -> ref_volt) << 6);
	CLEAR_BIT(ADMUX,ADLAR);
	ADMUX = (ADMUX & 0xE0) | ( (2) & 0x07);
	SET_BIT(ADCSRA,ADEN);
	CLEAR_BIT(ADCSRA,ADATE);
	CLEAR_BIT(ADCSRA,ADIE);
	ADCSRA = (ADCSRA & 0xF8) | ( (Config_ptr -> prescaler) );
}

uint16 ADC_readchannel(uint8 ch_num)
{
	ADMUX = (ADMUX & 0xE0) | (ch_num & 0x07);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF)) {}
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
