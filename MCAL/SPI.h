
#ifndef SPI_H_
#define SPI_H_

#define  MASTER 1
#define  SLAVE  0


#define  SPI_MODE  MASTER



void SPI_Init(void );


u8 SPI_SendReceive(u8 data);

u8 SPI_Receive(void);





#endif /* SPI_H_ */