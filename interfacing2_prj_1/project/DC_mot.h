/*
 * DC_mot.h
 *
 *  Created on: Oct 5, 2022
 *      Author: dell
 */

#ifndef DC_MOT_H_
#define DC_MOT_H_

#include "std_types.h"

#define DC_MOT_INT1_Port_ID     PORTB_ID
#define DC_MOT_INT1_PIN_ID      PIN6_ID

#define DC_MOT_INT2_Port_ID     PORTB_ID
#define DC_MOT_INT2_PIN_ID      PIN5_ID

typedef enum
{
	STOP,CLOCKWISE,ANTICLOCKWISE

}DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* DC_MOT_H_ */
