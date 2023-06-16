/*
 * ----------------------------------------------------------------------------------
 * Filename     :	NVIC_interface.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAY 21, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU ARM GCC
 * Controller   :   STM32F401CCU6 (32-bit Architecture)
 * Layer        :   MCAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAY 21, 2023 		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#define     MNVIC_EXTI0     6 
#define     MNVIC_EXTI1     7 

void MNVIC_voidInit(void);
void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8PeripheralID);
void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8PeripheralID);
void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID);
void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID);
void MNVIC_voidGetActiveFlag(u8 Copy_u8PeripheralID, u8 *Copy_u8ActiveFlag);
void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority);

#endif /* NVIC_INTERFACE_H */
