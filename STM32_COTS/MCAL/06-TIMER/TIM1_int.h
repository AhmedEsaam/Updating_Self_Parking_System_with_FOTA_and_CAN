/**
 * @file TIM1_int.h
 * @author your name (you@domain.com)
 * @brief 
 * @compiler:   GNU ARM-GCC
 * @controller: STM32F40ICCU6
 * @layer:      MCAL 
 * @version 0.1
 * @date 2023-06-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _TIM1_INT_H_
#define _TIM1_INT_H_

#define TIM1_MODE   TIM1_PWM

void MTIM1_voidInit(u8 Mode);


#endif /*_TIM1_INT_H_*/