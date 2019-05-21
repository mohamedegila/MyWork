/*
 * DIO_prog.c

 *
 *  Created on: ??‏/??‏/????
 *      Author: Mohammed
 */
#include "LSTD_TYPES.h"
#include "LUTILS.h"
#include "MDIO_interface.h"
#include "MDIO_private.h"
#include "MDIO_config.h"

static volatile u8*  MDIO_u8RWPortDirArr[DIO_u8PORTNUMBERS] = { DDRA, DDRB,DDRC, DDRD };
static volatile u8*  MDIO_u8ReadPortArr[DIO_u8PORTNUMBERS] = { PINA, PINB,PINC, PIND };
static volatile u8*  MDIO_u8WritePortArr[DIO_u8PORTNUMBERS] = { PORTA,PORTB, PORTC, PORTD };

void MDIO_voidInitilization(void)
{
       DDRA |= MDIO_u8PORTA_DIR; 
	   DDRB |= MDIO_u8PORTB_DIR; 
	   DDRC |= MDIO_u8PORTC_DIR; 
	   DDRD |= MDIO_u8PORTD_DIR; 
	   
	   PORTA |= MDIO_u8PORTA_VAL; 
	   PORTB |= MDIO_u8PORTB_VAL; 
	   PORTC |= MDIO_u8PORTC_VAL; 
	   PORTD |= MDIO_u8PORTD_VAL; 
}
void MDIO_voidReadPinVal(u8 Copy_u8PinIdx, u8 * Copy_u8PtrToVal)
{
			* Copy_u8PtrToVal = GET_BIT(MDIO_u8ReadPortArr[Copy_u8PinIdx / MDIO_u8PORTSIZE],
											MDIO_u8ReadPortArr[Copy_u8PinIdx % MDIO_u8PORTSIZE]);
}


void MDIO_voidWritePinVal(u8 Copy_u8PinIdx, u8 Copy_u8PinVal)
{
		ASSIGN_BIT(MDIO_u8WritePortArr[Copy_u8PinIdx / MDIO_u8PORTSIZE],
		                       MDIO_u8ReadPortArr[Copy_u8PinIdx % MDIO_u8PORTSIZE],Copy_u8PinVal); 
}

void MDIO_voidReadPortVal(u8 Copy_u8PortIdx, u8* Copy_u8PtrVal)
{
    * Copy_u8PtrVal =   MDIO_u8ReadPortArr[Copy_u8PortIdx];    
}
void MDIO_voidWritePortVal(u8 Copy_u8PortIdx, u8 Copy_u8PortVal)
{
		MDIO_u8WritePortArr[Copy_u8PortIdx] = Copy_u8PortVal;
}

void MDIO_voidWritePinDir(u8 Copy_u8PinIdx, u8 Copy_u8PinDir)
{
		ASSIGN_BIT(MDIO_u8RWPortDirArr[Copy_u8PinIdx / MDIO_u8PORTSIZE],
		                       MDIO_u8ReadPortArr[Copy_u8PinIdx % MDIO_u8PORTSIZE],Copy_u8PinDir); 
}
void MDIO_voidWritePortDir(u8 Copy_u8PortIdx, u8 Copy_u8PortDir)
{
      MDIO_u8RWPortDirArr[Copy_u8PortIdx] = Copy_u8PortDir;
}
void MDIO_voidReadPinDir(u8 Copy_u8PinIdx, u8 * Copy_u8PtrToDir)
{
		* Copy_u8PtrToDir = GET_BIT(MDIO_u8RWPortDirArr[Copy_u8PinIdx / MDIO_u8PORTSIZE],
											MDIO_u8ReadPortArr[Copy_u8PinIdx % MDIO_u8PORTSIZE]);
}
void MDIO_voidReadPortDir(u8 Copy_u8PortIdx, u8* Copy_u8PtrDir)
{
			*Copy_u8PtrDir = MDIO_u8RWPortDirArr[Copy_u8PortIdx];
}


