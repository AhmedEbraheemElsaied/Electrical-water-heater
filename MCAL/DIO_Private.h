/*
 * DIO_Private.h
 *
 * Created: 6/9/2023 10:52:02 PM
 *  Author: lenovo
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

extern const DIO_PinStatus_type DIO_PinsStatusArr[TOTAL_PINS];
static void DIO_InitPin(DIO_Pin_type pin ,DIO_PinStatus_type status);


#endif /* DIO_PRIVATE_H_ */