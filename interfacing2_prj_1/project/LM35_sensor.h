/*
 * LM35_sensor.h
 *
 *  Created on: Oct 5, 2022
 *      Author: dell
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

#define SENSOR_CHANNEL_ID       2
#define SENSOR_MAX_VOLT        1.5
#define SENSOR_MAX_TEMP        150

uint8 LM35_get_temp();


#endif /* LM35_SENSOR_H_ */
