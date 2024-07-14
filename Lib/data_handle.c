#include "data_handle.h" 
//Chuyen tu hex sang float
float data_handle(uint8_t L,uint8_t H)
{
	float data = (float)((short)((short)(H)<<8|L)/32768.0*180);
	return data;
}

