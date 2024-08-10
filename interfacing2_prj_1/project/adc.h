/*
 * adc.h
 *
 *  Created on: Oct 5, 2022
 *      Author: dell
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

#define ADC_VOLT_REF      2.56
#define ADC_MAX_DIG_VAL   1023

typedef enum
{
	AREF = 0,AVCC,RESERVED,Internal_REF_VOLT
}ADC_ReferenceVolatge;

typedef enum
{
	DIV_FACTOR_2 = 1,DIV_FACTOR_4 = 2,DIV_FACTOR_8 = 3,DIV_FACTOR_16 = 4,DIV_FACTOR_32 = 5,DIV_FACTOR_64 = 6,DIV_FACTOR_128 = 7
}ADC_Prescaler;


typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	 ADC_Prescaler prescaler;
}ADC_ConfigType;

void ADC_init(const ADC_ConfigType* Config_ptr);
uint16 ADC_readchannel(uint8 ch_num);

#endif /* ADC_H_ */
