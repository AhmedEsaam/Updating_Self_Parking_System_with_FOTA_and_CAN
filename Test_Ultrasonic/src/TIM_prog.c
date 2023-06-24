/**
 * @file TIM_prog.c
 * @author Doaa Hagag (doaahagag128@gmail.com)
 * @brief 	for timer2 pwm
 * @compiler:   GNU ARM-GCC
 * @controller: STM32F40ICCU6
 * @layer:      MCAL 
 * @date 2023-06-15
 * @version 2
 *
 * @copyright Copyright (c) 2023
 * 
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "TIM_int.h"
#include "TIM_priv.h"
#include "TIM_config.h"


// void MTIM1_voidInit(u32 PERIOD, u32 DUTY)
// {
//     switch ( TIM1_MODE)
//     {
//     case TIM1_PWM :
//         /* Configure the output pin */
//             /*Select the output mode by writing CCS bits in CCMRx register*/
//                 CLR_BIT (TIM1->CCMR2  , CC3S1);
//                 CLR_BIT (TIM1->CCMR2  , CC3S0);
// /**/        /*select polarity by writing the CCxP bit in CCER Register (Active high) */
//                 CLR_BIT (TIM1->CCER ,CC3P );
//         /* Select the BWM Mode (PWM1 OR PWM2) By writing OCxM bits in CCMRx register */
//             SET_BIT (TIM1->CCMR2 , OC3M2);
//             SET_BIT (TIM1->CCMR2 , OC3M1);
//             CLR_BIT (TIM1->CCMR2 , OC3M0);
//         /* Program the period and the duty cycle respectively in ARR and CCRx Registers */
// /**/        TIM1->PSC = 15999; 
//             TIM1->ARR = PERIOD;
//             TIM1->CCR3= DUTY;   /*Must be less than arr for equal toggle*/
//         /* Set the preload bit in CCMRx Register ARPE bit in the CR1 register */
//             SET_BIT(TIM1->CCMR1 , OC3PE);
// /**/        SET_BIT(TIM1->CR1,  ARPE );
//         /* Select counting mode */
//             /* PWM Edge-aligned Mode : the counter must be configured up counting or dowm counting (the default)*/ 
//             /* PWM Center aligned mode : the counter mode must be center aligned counting mode (CMS different from 00)*/
//         //TIM1->CR1 = 
        
//         /* Enable capture Mode */
//         SET_BIT (TIM1->CCER, CC3E);
//         /* Enable Counter*/
//         SET_BIT (TIM1->CR1 , CEN );
//         /**
//          * @note The PWM can be selected independently on each channel (one PWM per OCx output )
//          *        by writing 110 (PWM mode 1 ) or 111 (PWM mode 2)
//          *        in the (OCxM) bits in the TIMx-CCMRx register.
//          */
//         break;
    
//     default:
//         break;
//     }

// }


/****************************************************************************
*****************************************************************************
*****************************************************************************/

void MGTimer2_voidInit(CHANNE_t Copy_Timer_Channel)
{	
	switch(Copy_Timer_Channel)
		{
		case CHANNEL1:

			/*Select output mode*/
			CLR_BIT(TIMER2_BASE -> CCMR1, 0);
			CLR_BIT(TIMER2_BASE -> CCMR1, 1);
			/*Select polarity as Active High*/
			CLR_BIT(TIMER2_BASE -> CCER, CCER_CC1P);
			/*Select PWM mode 1*/
#if 	PWM_MODE == PWM_MODE1
			CLR_BIT(TIMER2_BASE -> CCMR1,4);
			SET_BIT(TIMER2_BASE -> CCMR1,5);
			SET_BIT(TIMER2_BASE -> CCMR1,6);
#elif 	PWM_MODE == PWM_MODE2
			SET_BIT(TIMER2_BASE -> CCMR1,4);
			SET_BIT(TIMER2_BASE -> CCMR1,5);
			SET_BIT(TIMER2_BASE -> CCMR1,6);
#endif
			/*Set preload value*/
			SET_BIT(TIMER2_BASE -> CCMR1,CCMR1_OC1PE);
			/*Enable capture compare*/
			SET_BIT(TIMER2_BASE -> CCER, CCER_CC1E);
			break;
		case CHANNEL2:
			/*Select output mode*/
			CLR_BIT(TIMER2_BASE -> CCMR1, 8);
			CLR_BIT(TIMER2_BASE -> CCMR1, 9);
			/*Select polarity as Active High*/
			CLR_BIT(TIMER2_BASE -> CCER, CCER_CC2P);
			/*Select PWM mode 1*/
#if 	PWM_MODE == PWM_MODE1
			CLR_BIT(TIMER2_BASE -> CCMR1,12);
			SET_BIT(TIMER2_BASE -> CCMR1,13);
			SET_BIT(TIMER2_BASE -> CCMR1,14);
#elif 	PWM_MODE == PWM_MODE2
			SET_BIT(TIMER2_BASE -> CCMR1,12);
			SET_BIT(TIMER2_BASE -> CCMR1,13);
			SET_BIT(TIMER2_BASE -> CCMR1,14);
#endif
			SET_BIT(TIMER2_BASE -> CCMR1,CCMR1_OC2PE);
			/*Enable capture compare*/
			SET_BIT(TIMER2_BASE -> CCER, CCER_CC2E);
			break;
		case CHANNEL3:
			/*Select output mode*/
			CLR_BIT(TIMER2_BASE -> CCMR2, 0);
			CLR_BIT(TIMER2_BASE -> CCMR2, 1);
			/*Select polarity as Active High*/
			CLR_BIT(TIMER2_BASE -> CCER, CCER_CC3P);
			/*Select PWM mode 1*/
#if 	PWM_MODE == PWM_MODE1
			CLR_BIT(TIMER2_BASE -> CCMR2,4);
			SET_BIT(TIMER2_BASE -> CCMR2,5);
			SET_BIT(TIMER2_BASE -> CCMR2,6);
#elif 	PWM_MODE == PWM_MODE2
			SET_BIT(TIMER2_BASE -> CCMR2,4);
			SET_BIT(TIMER2_BASE -> CCMR2,5);
			SET_BIT(TIMER2_BASE -> CCMR2,6);
#endif
			SET_BIT(TIMER2_BASE -> CCMR2,CCMR2_OC3PE);
			/*Enable capture compare*/
			SET_BIT(TIMER2_BASE -> CCER, CCER_CC3E);
			break;
		case CHANNEL4:
			/*Select output mode*/
			CLR_BIT(TIMER2_BASE -> CCMR2, 8);
			CLR_BIT(TIMER2_BASE -> CCMR2, 9);
			/*Select polarity as Active High*/
			CLR_BIT(TIMER2_BASE -> CCER, CCER_CC2P);
			/*Select PWM mode 1*/
#if 	PWM_MODE == PWM_MODE1
			CLR_BIT(TIMER2_BASE -> CCMR2,12);
			SET_BIT(TIMER2_BASE -> CCMR2,13);
			SET_BIT(TIMER2_BASE -> CCMR2,14);
#elif 	PWM_MODE == PWM_MODE2
			SET_BIT(TIMER2_BASE -> CCMR2,12);
			SET_BIT(TIMER2_BASE -> CCMR2,13);
			SET_BIT(TIMER2_BASE -> CCMR2,14);
#endif
			SET_BIT(TIMER2_BASE -> CCMR2,CCMR2_OC4PE);
			/*Enable capture compare*/
			SET_BIT(TIMER2_BASE -> CCER, CCER_CC4E);
			break;
		default: 								break;
		}
		CLR_BIT(TIMER2_BASE -> CR1,CR1_ARPE);
		/*Select counting mode*/
		CLR_BIT(TIMER2_BASE -> CR1,4);
		CLR_BIT(TIMER2_BASE -> CR1,5);
		CLR_BIT(TIMER2_BASE -> CR1,6);
}
void MGTimer2_void_Prescaller( u16 Copy_u16Prescaller)
{
	CLR_REG(TIMER2_BASE -> PSC);
	TIMER2_BASE -> PSC |=Copy_u16Prescaller;
}
void MGTimer2_void_PeriodValue( u16 Copy_u16Value)
{
	TIMER2_BASE -> ARR =Copy_u16Value;
}
void MGTimer2_void_CompValue(CHANNE_t Copy_Timer_Channel, u16 Copy_u16Value)
{
	
	switch(Copy_Timer_Channel)
	{
	case CHANNEL1:
		TIMER2_BASE -> CCR1 =Copy_u16Value;
		break;
	case CHANNEL2:
		TIMER2_BASE -> CCR2 =Copy_u16Value;
		break;
	case CHANNEL3:
		TIMER2_BASE -> CCR3 =Copy_u16Value;
		break;
	case CHANNEL4:
		TIMER2_BASE -> CCR4 =Copy_u16Value;
		break;
	default:
		break;
	}
}
void MGTimer2_voidStart(void)
{
	/*Enable Counter*/
	SET_BIT(TIMER2_BASE -> CR1, CR1_CEN);
}
void MGTimer2_voidStop(void)
{
	CLR_BIT(TIMER2_BASE -> CR1, CR1_CEN);
}


void Timer3_voidStart(void)
{
	SET_BIT(TIMER3_BASE -> CR1 , 0);			/* Enable Counter */

	CLR_BIT(TIMER3_BASE -> CR1 , 4);		/* counter mode is up counting */
}

void Timer3_u16Count(u16 Copy_u16Count)
{
	TIMER3_BASE -> CNT = Copy_u16Count;	/* Intial Value Of TIMER3_BASE */
}

u32  Timer3_voidReadCaptureVal(void)
{
	return TIMER3_BASE -> CCR1;			/* Return Captured Value */
}

void Timer3_voidPrescale(u16 Copy_u16Prescaler)
{
	TIMER3_BASE -> PSC = Copy_u16Prescaler -1 ;	/* TIMER3_BASE Prescaler */
}



void Timer3_voidCapture_Compare_Init(void)
{
	/*DIER Register*/

	SET_BIT(TIMER3_BASE -> DIER , 1);	/* Capture/Compare interrupt enable */

	/*CCMR1 Register*/

	SET_BIT(TIMER3_BASE -> CCMR1 , 0);	/* configure TIMER3_BASE ch1 as input */
	CLR_BIT(TIMER3_BASE -> CCMR1 , 1);

	CLR_BIT(TIMER3_BASE -> CCMR1 , 2);	/* configure TIMER3_BASE ch1 to capture at every edge detected */
	CLR_BIT(TIMER3_BASE -> CCMR1 , 3);


	CLR_BIT(TIMER3_BASE -> CCMR1 , 6);
	CLR_BIT(TIMER3_BASE -> CCMR1 , 7);

	/*CCER Register*/

	SET_BIT(TIMER3_BASE -> CCER , 0);	/* Capture Enabled */


	SET_BIT(TIMER3_BASE -> CCER , 1);	/* Capture/Compare channel captures on both edges (rising & falling) */
	SET_BIT(TIMER3_BASE -> CCER , 3);

	Timer3_voidPrescale(72);

	TIMER3_BASE -> ARR = 65535;			/*Max of Ticks*/

}
