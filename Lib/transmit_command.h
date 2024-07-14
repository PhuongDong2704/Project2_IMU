#ifndef TRANSMIT_COMMAND_H
#define TRANSMIT_COMMAND_H

#include "stm32f1xx_hal.h"

void transmit_data(UART_HandleTypeDef *huartx, char command[] , uint32_t time);
#endif
