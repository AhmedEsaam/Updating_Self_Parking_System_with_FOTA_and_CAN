/*
 * ----------------------------------------------------------------------------------
 * Filename     :	EXTI_interface.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAY 22, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU ARM GCC
 * Controller   :   STM32F401CCU6 (32-bit Architecture)
 * Layer        :   MCAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAY 22, 2023 		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define MEXTI_SENSE_SIGNAL      MEXTI_RISING_EDGE

#define MEXTI_RISING_EDGE       0
#define MEXTI_FALLING_EDGE      1
#define MEXTI_ON_CHANGE         2

#define MEXTI_LINE0             0

void MEXTI_voidInit(void);
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILine);
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILine);
void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTILine, u8 Copy_u8SenseSignal);
void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*pvNotificationFunction)(void));


#endif /* EXTI_INTERFACE_H */
