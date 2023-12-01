/*
 * lock.h
 *
 *  Created on: Nov 20, 2023
 *      Author: saaci
 */

#ifndef INC_LOCK_H_
#define INC_LOCK_H_
#include "stm32l4xx_hal.h"

#include <stdint.h>
extern uint8_t ultrasonicSensorEnabled;

void lock_init(void);
void lock_sequence_handler(uint8_t key);
uint8_t Rx_USART1(void);
void lock_control_ultrasonic_sensor(uint8_t key);
uint8_t Flag_USART1(void);
void lock_sequence(void);
#endif /* INC_LOCK_H_ */
