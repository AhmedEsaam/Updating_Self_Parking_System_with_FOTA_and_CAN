/**
 * @file SYSTICK_int.h
 * @author Doaa Hagag (doaahagag128@gmail.com)
 * @brief 
 * @compiler:   GNU ARM-GCC
 * @controller: STM32F40ICCU6
 * @layer:      MCAL 
 * @version 1.0
 * @date 2023-05-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef _SYSTICK_INT_H
#define _SYSTICK_INT_H


/**
 * @brief 
 * 
 * @return ** void 
 */
void MSYSTICK_voidInit(void);
/**
 * @brief 
 * 
 * @param Time_usec 
 * @return ** void 
 */
void MSYSTICK_voidSetBusyWait(u32 Time_usec);
/**
 * @brief 
 * 
 * @return ** void 
 */
void MSYSTICK_voidEnable(void);
/**
 * @brief 
 * 
 * @return ** void 
 */
void MSYSTICK_voidDisable(void);
/**
 * @brief 
 * 
 * @return ** void 
 */
void MSYSTICK_voidEnableInterrupt(void);
/**
 * @brief 
 * 
 * @return ** void 
 */
void MSYSTICK_voidDisableInterrupt(void);
/**
 * @brief 
 * 
 * @param NotificationFunction 
 * @return ** void 
 */
void MSYSTICK_voidSetIntervalSingle(void (*NotificationFunction)(void) );
void MSYSTICK_voidSetIntervalPeriodic(void (*NotificationFunction)(void));
void MSYSTICK_voidGetElapsedTime(u32 * Local_pu32ElapsedTime);
void MSYSTICK_voidGetRemainingTime(u32 *Local_pu32RemainingTime);
void MSYSTICK_voidSetPreLoadValue(u32 Copy_u8LoadValue);
void MSYSTICK_voidResetSysTick(void);





#endif /*_SYSTICK_INT_H*/
