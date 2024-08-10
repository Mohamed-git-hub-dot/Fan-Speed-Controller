/*
 * main.c
 *
 *  Created on: Oct 5, 2022
 *      Author: dell
 */

#include "lcd.h"
#include "LM35_sensor.h"
#include "DC_mot.h"
#include "adc.h"

int main()
{
	uint8 temp = 0;
	ADC_ConfigType* adc_ptr;
	adc_ptr -> ref_volt = Internal_REF_VOLT;
	adc_ptr -> prescaler = DIV_FACTOR_8;
	ADC_init(adc_ptr);
	LCD_init();
	DcMotor_Init();

	LCD_displayString("Fan is");
	LCD_moveCursor(1,0);
	LCD_displayString("Temp =     C");

	while(1)
	{
		temp = LM35_get_temp();

		if(temp < 30)
		{
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

			DcMotor_Rotate(STOP,0);
			LCD_moveCursor(0,7);
			LCD_displayString("OFF");
		}

		else if(temp >= 30 && temp < 60)
		{
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

			DcMotor_Rotate(CLOCKWISE,25);
			LCD_moveCursor(0,7);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}

		else if(temp >= 60 && temp < 90)
		{
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');


			DcMotor_Rotate(CLOCKWISE,50);
			LCD_moveCursor(0,7);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}

		else if(temp >= 90 && temp < 120)
		{
			if(temp >= 100)
			{
				LCD_moveCursor(1,7);
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_moveCursor(1,7);
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}

			DcMotor_Rotate(CLOCKWISE,75);
			LCD_moveCursor(0,7);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}

		else if(temp >= 120)
		{
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);

			DcMotor_Rotate(CLOCKWISE,100);
			LCD_moveCursor(0,7);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}
	}
	return 0;
}
