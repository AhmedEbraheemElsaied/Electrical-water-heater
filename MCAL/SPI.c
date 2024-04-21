
#include "StdTypes.h"
#include "MemMap.h"
#include "UTILS.h"
#include "SPI.h"


void SPI_Init(void )
{
	// SLAVE OR MASTER
	#if SPI_MODE
   SET_BIT(SPCR,MSTR);
   //clock 2mhz
   #else
   CLR_BIT(SPCR,MSTR);
   #endif
	
	
	//enable
	
	SET_BIT(SPCR,SPE);
}


u8 SPI_SendReceive(u8 data)
{
	// write puffer
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	//READ PUFFER
	return SPDR;
	
}