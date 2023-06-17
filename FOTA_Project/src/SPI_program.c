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
	MGPIO_ErrSetPinMode(MSPI1_MOSI_PORTPIN, GPIO_ALTERNATE_FUNCTION); // PA7 MOSI
	MGPIO_ErrSetPinMode(MSPI1_SCK_PORTPIN, GPIO_ALTERNATE_FUNCTION);  // PA5 SCK

	MGPIO_ErrSetPinOutputSpeed(MSPI1_MOSI_PORTPIN, GPIO_LOW_SPEED);
	MGPIO_ErrSetPinOutputSpeed(MSPI1_SCK_PORTPIN, GPIO_LOW_SPEED);

	MGPIO_ErrSetPinAlternateFunction(MSPI1_MOSI_PORTPIN, MGPIO_AF5);
	MGPIO_ErrSetPinAlternateFunction(MSPI1_SCK_PORTPIN, MGPIO_AF5);

	MGPIO_ErrSetPinMode(MSPI1_NSS_PORTPIN, GPIO_ALTERNATE_FUNCTION);	// PA4 NSS
	MGPIO_ErrSetPinPullUpPullDown(MSPI1_NSS_PORTPIN, GPIO_PULL_UP);
	MGPIO_ErrSetPinAlternateFunction(MSPI1_NSS_PORTPIN, MGPIO_AF5);


    /*Set The CPHA = 1, Write of the leading edge */
    SPI1 -> CR1 = 0x0347;    
}

void MSPI_u8TrancieveSynchronous(u8 Copy_u8Data, u8 * Copy_pu8ReceivedData)
{
    u8 Local_u8ReceivedData;
    SPI1 -> DR = Copy_u8Data;
    while(GET_BIT(SPI1 -> SR, 7) == 1);
    Local_u8ReceivedData = SPI1 -> DR;
    * Copy_pu8ReceivedData = Local_u8ReceivedData;
}
