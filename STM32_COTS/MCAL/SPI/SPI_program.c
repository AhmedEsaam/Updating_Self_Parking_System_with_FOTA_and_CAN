/*
 * ----------------------------------------------------------------------------------
 * Filename     :	DC_Motor_interface.h
 * Author       :	Abdelrhman Nasr Farag
 * Created on   :	june 15, 2023
 * Version      :	v1.0
 * Compiler     :	GNU ARM-GCC
 * Controller   :  	STM32F401CCU6 (32-bit Architecture)
 * Processor    :   Cortex M4 (32-bit Architecture)
 * Layer        :   MCAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    june 15, 2023	Abdelrhman Nasr Farag		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void MSPI1_voidInit(void)
{
    MGPIO_voidSetPinMode(MSPI1_MOSI_PORTPIN, MGPIO_AF); // PA7 MOSI
	MGPIO_voidSetPinMode(MSPI1_SCK_PORTPIN, MGPIO_AF);  // PA5 SCK

	MGPIO_voidSetPinSpeed(MSPI1_MOSI_PORTPIN, MGPIO_LOW_SPEED);
	MGPIO_voidSetPinSpeed(MSPI1_SCK_PORTPIN, MGPIO_LOW_SPEED);

	MGPIO_voidSetAlternativeFunction(MSPI1_MOSI_PORTPIN, 5);
	MGPIO_voidSetAlternativeFunction(MSPI1_SCK_PORTPIN, 5);

	MGPIO_voidSetPinMode(MSPI1_NSS_PORTPIN, MGPIO_AF);	// PA4 NSS
	MGPIO_voidSetPinPullUPDown(MSPI1_NSS_PORTPIN, MGPIO_PULLUP);
	MGPIO_voidSetAlternativeFunction(MSPI1_NSS_PORTPIN, 5);

    /*Set The CPHA = 1, Write of the leading edge */
    SPI1 -> CR1 = 0x0347;    
}

u8 MSPI_u8TrancieveSynchronous(u8 Copy_u8Data, u8 * Copy_pu8ReceivedData)
{
    u8 Local_u8ReceivedData;
    SPI1 -> DR = Copy_u8Data;
    while(GET_BIT(SPI1 -> SR, 7) == 1);
    Local_u8ReceivedData = SPI1 -> DR;
    return Local_u8ReceivedData;
}
