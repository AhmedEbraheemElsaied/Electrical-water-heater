/*
 * KeyPad_Cfg.h
 *
 * Created: 6/17/2023 9:07:14 PM
 *  Author: lenovo
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


#define  ROWS   4
#define  COLS   4

#define NO_KEY  'T'

#define FIRST_OUTPUT   PINB4
#define FIRST_INPUT    PIND0


#if KEYPAD_PRG

const u8 KeysArr[ROWS][COLS]={ {'7','8','9','/'}
						      ,{'4','5','6','*'}
						      ,{'1','2','3','-'}
						      ,{'C','0','=','+'}};
#endif							

#endif /* KEYPAD_CFG_H_ */