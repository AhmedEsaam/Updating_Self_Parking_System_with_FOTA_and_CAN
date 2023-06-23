/**
 * @file TIM_int.h
 * @author Doaa Hagag (doaahagag128@gmail.com)
 * @brief 		for timer2 pwm
 * @compiler:   GNU ARM-GCC
 * @controller: STM32F40ICCU6
 * @layer:      MCAL 
 * @version 2
 * @date 2023-06-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _TIM1_INT_H_
#define _TIM1_INT_H_

//#define TIM1_MODE   TIM1_PWM

//void MTIM1_voidInit(u32 PERIOD, u32 DUTY);

typedef enum
{
	TIMER2,
	TIMER3,
	TIMER4,
	TIMER5
}TIMERN_t;

typedef enum
{
	CHANNEL1 = 1,
	CHANNEL2,
	CHANNEL3,
	CHANNEL4
}CHANNE_t;

void MGTimer2_voidInit(CHANNE_t Copy_Timer_Channel);
void MGTimer2_void_Prescaller( u16 Copy_u16Prescaller);
void MGTimer2_void_PeriodValue( u16 Copy_u16Value);
void MGTimer2_void_CompValue(CHANNE_t Copy_Timer_Channel, u16 Copy_u16Value);
void MGTimer2_voidStart(void);
void MGTimer2_voidStop(void);




#endif /*_TIM1_INT_H_*/
