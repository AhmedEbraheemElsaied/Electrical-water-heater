
#include "StdTypes.h"
#include "ADC_Interface.h"
#include "Sensors_Cfg.h"
#include "Sensors_Interface.h"
#define  ADC_X  0
#define POINTS  10
#define  TEMP_Y 1

// u16 arr[POINTS][2]={    {0,10}
// 				,	{100,20}
// 					{200,33}
// 					{300,60}
// 					{400,100}
// 					{0,10}
// 					{0,10}};
						
// u16 temp(u16 adc)//370
// {
// 	u8 i;
// 	for (i=0;i<POINTS;i++)
// 	{
// 		if (adc<arr[i][ADC_X])
// 		{
// 			temp=inter(adc,arr[i-1][ADC_X],arr[i][ADC_X],arr[i][TEMP_Y-1],arr[i][TEMP_Y-1]);
// 		}
// 	}
// }						





u16 TEMP_Read(void)
{
	u16 volt=ADC_VoltRead(LM35_CH);
	u16 temp;
	
	temp=volt/10;   
	
	return temp;
	
}

u16 PRESS_Read(void)
{
	u16 adc=ADC_Read(NPX4115_CH);
	
	u16 press= ((((u32)1000*(adc-55))+460)/921)+150;
	
	return press;
	
}


u8 POT_Read(void)
{
	
}