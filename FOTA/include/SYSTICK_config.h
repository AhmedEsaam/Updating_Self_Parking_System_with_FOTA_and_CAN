/*
 * ----------------------------------------------------------------------------------
 * Filename		:	SYSTICK_config.h
 *
 * Author		:	Ahmed Essam El-Mogy
 * Created on	:	MAY 8, 2023
 * Version		:	v1.0
 * C Standard	:	C99
 * Compiler		:	GNU ARM GCC
 * Controller	:	STM32F401CCU6 (32-bit Architecture)
 * Layer		:	MCAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version 		Date 				Author 						Describtion
 * v1.0 		MAY 8, 2023 		Ahmed Essam El-Mogy 		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#define SYSTICK_CONFIG_H_
#ifdef SYSTICK_CONFIG_H_


/* options:
    SYSTICK_CLK_AHB_DIVIDED_BY_8
    SYSTICK_CLK_AHB
*/
#define     SYSTICK_CLK_SOURCE              SYSTICK_CLK_AHB_DIVIDED_BY_8

#define     SYSTICK_INTERRUPT_EN            SYSTICK_INTERRUPT_ENABLE

#define     SYSTICK_EN                      SYSTICK_ENABLE





#endif /* SYSTICK_CONFIG_H_*/