#include "transmit_command.h" 
/*
Gui tin hieu cho IMU gom 3 buoc
	Gui lenh unlock
	Gui lenh can thuc hien
	Gui lenh save
*/

//Lenh gui mac dinh
char unlock[]= {0xFF,0xAA,0x69,0x88,0xB5};
char save[]= {0xFF,0xAA,0x00,0x00,0x00};

uint32_t current_time = 0;
uint8_t flag_data = 1;
void transmit_data(UART_HandleTypeDef *huartx, char command[] , uint32_t time)
{
	//Moi lenh gui cach nhau 200ms va lap lai viec gui 3 lenh la 'time' ms
	if (HAL_GetTick() - current_time == 100 && flag_data == 1)
	{
		HAL_UART_Transmit(huartx, (uint8_t*)unlock, 5,100);
		flag_data = 2;
	}
	else if (HAL_GetTick() - current_time == 300 && flag_data == 2)
	{
		HAL_UART_Transmit(huartx, (uint8_t*)command, 5,100);
		flag_data = 3;
	}
	else if (HAL_GetTick() - current_time == 500 && flag_data == 3)
	{
		HAL_UART_Transmit(huartx, (uint8_t*)save,5,100);
		flag_data = 1;
	}
	else if (HAL_GetTick() - current_time >= time)
	{
		current_time = HAL_GetTick();
	}
}