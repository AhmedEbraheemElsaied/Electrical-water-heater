/*
 * EEPROM.h
 *
 * Created: 4/20/2024 4:54:47 AM
 *  Author: M lapan
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_write(u16 uiAddress, u8 ucData);
u8 EEPROM_read(u16 uiAddress);



#endif /* EEPROM_H_ */