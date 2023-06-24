/*
 * ----------------------------------------------------------------------------------
 * Filename		:	SYSTICK_interface.h
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

#define SYSTICK_INTERFACE_H_
#ifdef SYSTICK_INTERFACE_H_

// SysTick Clock Selection .............................
#define         SYSTICK_CLK_AHB_DIVIDED_BY_8        0 
#define         SYSTICK_CLK_AHB                     1

// SysTick Enable ...............................
#define         SYSTICK_ENABLE                      0 
#define         SYSTICK_DISABLE                     1

// SysTick Interval Type ...............................
#define         SYSTICK_INTERVAL_SINGLE             0 
#define         SYSTICK_INTERVAL_PERIODIC           1

// SysTick Interrupt Enable ............................
#define         SYSTICK_INTERRUPT_ENABLE            1 
#define         SYSTICK_INTERRUPT_DISABLE           0



typedef enum SYSTICK_Error_t
{
    SYSTICK_Ok,
    SYSTICK_InvalidBusyWaitValue,
}SYSTICK_Error_t;


void MSYSTICK_ErrInit(void);
SYSTICK_Error_t MSYSTICK_ErrSetBusyWait(u32 Copy_u32BusyWaitInMicroSec);
SYSTICK_Error_t MSYSTICK_ErrSetPreoadValue(u32 Copy_u32PreloadValue);
SYSTICK_Error_t MSYSTICK_ErrGetElapsedTime(u32 *Copy_pu32ElapsedTimeInMicroSec);
SYSTICK_Error_t MSYSTICK_ErrGetRemainingTime(u32 *Copy_pu32RemainingTimeInMicroSec);
//
//void MSYSTICK_ErrSetIntervalSingle(void(*NotificationFunction)(void));
//void MSYSTICK_ErrSetIntervalPeriodic(void(*NotificationFunction)(void));


#endif /* SYSTICK_INTERFACE_H_ */
