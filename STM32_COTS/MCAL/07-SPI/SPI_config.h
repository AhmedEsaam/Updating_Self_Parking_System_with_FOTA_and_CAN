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
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define MSPI1_MOSI_PORTPIN		MGPIO_PORTA,MGPIO_PIN7
#define MSPI1_MISO_PORTPIN		MGPIO_PORTA,MGPIO_PIN6
#define MSPI1_SCK_PORTPIN		MGPIO_PORTA,MGPIO_PIN5
#define MSPI1_NSS_PORTPIN		MGPIO_PORTA,MGPIO_PIN4

#endif