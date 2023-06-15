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
 * @brief Function to initialize Systick
 * 
 * @return ** void 
 */
void MSYSTICK_voidInit(void);
/**
 * @brief Set Busy Wait (Time in microseconds )
 * 
 * @param Time_usec 
 * @return ** void 
 */
void MSYSTICK_voidSetBusyWait(u32 Time_usec);
/**
 * @brief  Enable systick
 * 
 * @return ** void 
 */
void MSYSTICK_voidEnable(void);
/**
 * @brief  Disable Systick
 * 
 * @return ** void 
 */
void MSYSTICK_voidDisable(void);
/**
 * @brief Enable Interrupt for Systick
 * 
 * @return ** void 
 */
void MSYSTICK_voidEnableInterrupt(void);
/**
 * @brief Disable Interrupt for Systick
 * 
 * @return ** void 
 */
void MSYSTICK_voidDisableInterrupt(void);
/**
 * @brief   Make interrupt only once
 * 
 * @param NotificationFunction 
 * @return ** void 
 */
void MSYSTICK_voidSetIntervalSingle(void (*NotificationFunction)(void) );
/**
 * @brief  Make interrupt every period
 * 
 * @param NotificationFunction 
 * @return ** void 
 */
void MSYSTICK_voidSetIntervalPeriodic(void (*NotificationFunction)(void));
/**
 * @brief  function to get the elapsed time 
 * 
 * @param Local_pu32ElapsedTime 
 * @return ** void 
 */
void MSYSTICK_voidGetElapsedTime(u32 * Local_pu32ElapsedTime);
/**
 * @brief  function to get the remaining time
 * 
 * @param Local_pu32RemainingTime 
 * @return ** void 
 */
void MSYSTICK_voidGetRemainingTime(u32 *Local_pu32RemainingTime);
/**
 * @brief set the preload value
 * 
 * @param Copy_u8LoadValue 
 */
void MSYSTICK_voidSetPreLoadValue(u32 Copy_u8LoadValue);
/**
 * @brief Reset Systick
 * 
 * @return ** void 
 */
void MSYSTICK_voidResetSysTick(void);





#endif /*_SYSTICK_INT_H*/
