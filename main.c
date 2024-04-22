/*
 * Smart_Home.c
 *
 * Created: 4/3/2024 3:28:41 PM
 * Author : Ahmed Ebraheem
 */ 

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Inteface.h"
#include "MOTOR_Interface.h"
#include "LCD_Interface.h"
#include "KeyPad_Interface.h"
#include "ADC_Interface.h"
#include "Sensors_Interface.h"
#include "EX_Interrupt_Interface.h"
#include "Timers.h"
#include "Timers_Services.h"
#include "UART_Interface.h"
#include "UART_Services.h"
#include "EEPROM.h"



#define  HEATING PINC0
#define  COOLING PINC1
#define MAX 75
#define  MINI 35


u8 volatile desired_temp=60;
u8 volatile flag=1;
u16 volatile temp=0;

void Increase_Temp(void){
	if(desired_temp==MAX){
		EEPROM_write(0,MAX);
	}
	else{
	desired_temp=EEPROM_read(0);
	EEPROM_write(0,desired_temp+5);
	}
	
	
	
	
	
		
}
void decrease_Temp(void){
	if(desired_temp==MINI){
		EEPROM_write(0,MINI);
	}
	else{
	desired_temp=EEPROM_read(0);
	EEPROM_write(0,desired_temp-5);
	}
	
}
void ON_OFF(void){
	
flag++;	
}
void Sensor_Read(void){
	static u8 c=0;
	TCNT1=15536;
	c++;
	if(c==2){
		temp=TEMP_Read();
		DIO_TogglePin(PINC3);
		c=0;
	}
	
}


int main(void)
{   DIO_Init();
	LCD_Init();
	KEYPAD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_8);
	EXI_Init();
	UART_Init();
	sei();
	Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8);
	TCNT1 =15536;
	
	Timer1_OVF_InterruptEnable();
	EXI_Enable(EX_INT1);
	EXI_Enable(EX_INT0);
	EXI_Enable(EX_INT2);
	
	desired_temp=EEPROM_read(0);
	EEPROM_write(0,desired_temp);
   
  
  
    while (1) 
    {
		//DIO_TogglePin(PINC3);
		
		 desired_temp=EEPROM_read(0);
		Timer1_OVF_SetCallBack(Sensor_Read);
		EXI_SetCallBack(EX_INT0,Increase_Temp);
		EXI_SetCallBack(EX_INT1,decrease_Temp);
		EXI_SetCallBack(EX_INT2,ON_OFF);
		
	if (flag%2!=0){
		LCD_Clear();
	}
	else{
		LCD_GoTo(0,0);
		LCD_WriteString("Desired Temp");
		LCD_GoTo(0,12);
		LCD_WriteNumber(desired_temp);
		LCD_GoTo(1,0);
		LCD_WriteString("Real Temp");
		LCD_GoTo(1,11);
		LCD_WriteNumber(temp);
	}
		
		if(temp<desired_temp-5 && flag%2==0){
			DIO_WritePin(HEATING,HIGH);
			
		}
		else if (temp>desired_temp+5 || flag%2!=0){
			DIO_WritePin(HEATING,LOW);
		}
		
		if(temp>desired_temp+5 && flag%2==0){
			DIO_WritePin(COOLING,HIGH);
			
		}
		 else if  (temp<desired_temp-5 || flag%2!=0){
			DIO_WritePin(COOLING,LOW);
		}
		
		
		
		
		
		
		
    }
}

