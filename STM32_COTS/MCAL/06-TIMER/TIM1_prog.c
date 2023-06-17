/**
 * @file TIM1_prog.c
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

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "TIM1_int.h"
#include "TIM1_priv.h"
#include "TIM1_config.h"



void MTIM1_voidInit(u8 Mode)
{
    switch ( mode)
    {
    case TIM1_PWM :
        /* Select PWM output mode */
            SET_BIT (TIM1->CCMR2 , OC4M2);
            SET_BIT (TIM1->CCMR2 , OC4M1);
            SET_BIT (TIM1->CCMR2 , OC4M0);
        /* Configure the output pin */
            /*Select the outpu mode by writing CCS bits in CCMRx register*/
            /*select polarity by writing the CCxP bit in CCER Register */
        /* Select the polarity by writing the CCxP bit in CCER Register */
        /* Select the BWM Mode (PWM1 OR PWM2) By writing OCxM bits in CCMRx register */
        /* Program the period and the duty cycle respectively in ARR and CCRx Registers */
        /* Set the preload bit in CCMRx Register ARPE bit in the CR1 register */
        /* Select counting mode */
            /* PWM Edge-aligned Mode : the counter must be configured up counting or dowm counting */
            /* PWM Center aligned mode : the counter mode must be center aligned counting mode (CMS different from 00)*/
        /* Enable capture Mode */
        /* Enable Counter*/

        /**
         * @note The PWM can be selected independently on each channel (one PWM per OCx output )
         *        by writing 110 (PWM mode 1 ) or 111 (PWM mode 2)
         *        in the (OCxM) bits in the TIMx-CCMRx register.
         */



        break;
    
    default:
        break;
    }

}