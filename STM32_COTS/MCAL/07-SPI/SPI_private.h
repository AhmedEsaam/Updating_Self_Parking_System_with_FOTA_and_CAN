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
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H



typedef struct
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 CRCPR;
    volatile u32 RXCRCR;
    volatile u32 TXCRCR;
    volatile u32 I2SCFGR;
    volatile u32 I2SPR;
}SPI_t;


#define     SPI1         ((volatile SPI_t *)0x40013000)


#endif
