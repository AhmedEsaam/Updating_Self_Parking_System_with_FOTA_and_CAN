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


#define PERIOD 1000
#define DUTY	500

void MTIM1_voidInit()
{
    switch ( TIM1_MODE)
    {
    case TIM1_PWM :
        /* Configure the output pin */
            /*Select the output mode by writing CCS bits in CCMRx register*/
                CLR_BIT (TIM1->CCMR2  , CC3S1);
                CLR_BIT (TIM1->CCMR2  , CC3S0);
/**/        /*select polarity by writing the CCxP bit in CCER Register (Active high) */
                CLR_BIT (TIM1->CCER ,CC3P );
        /* Select the BWM Mode (PWM1 OR PWM2) By writing OCxM bits in CCMRx register */
            SET_BIT (TIM1->CCMR2 , OC3M2);
            SET_BIT (TIM1->CCMR2 , OC3M1);
            CLR_BIT (TIM1->CCMR2 , OC3M0);
        /* Program the period and the duty cycle respectively in ARR and CCRx Registers */
/**/        TIM1->PSC = 15999; 
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