/**
 * @file TIM_priv.h
 * @author Doaa Hagag (doaahagag128@gmail.com)
 * @brief 
 * @compiler:   GNU ARM-GCC
 * @controller: STM32F40ICCU6
 * @layer:      MCAL 
 * @version 2
 * @date 2023-06-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _TIM1_PRIV_H_
#define _TIM1_PRIV_H_

typedef struct TIM1_priv
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SMCR;
    volatile u32 DIER; 
    volatile u32 SR;
    volatile u32 EGR;
    volatile u32 CCMR1;
    volatile u32 CCMR2;     /* capture/compare mode register 2 */
    volatile u32 CCER;      /* capture/compare enable register */
    volatile u32 CNT;
    volatile u32 PSC;       /* Timer Prescaler */
    volatile u32 ARR;       /**/
    volatile u32 RCR;
    volatile u32 CCR1;
    volatile u32 CCR2;
    volatile u32 CCR3;
    volatile u32 CCR4;
    volatile u32 BDTR;
    volatile u32 DCR;
    volatile u32 DMAR;

}TIM1_t;

typedef	struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 RESERVED_1;
	volatile u32 CCR1;						//capture/compare mode register
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 RESERVED_2;
	volatile u32 DCR;
	volatile u32 DMAR;
	volatile u32 OR;
}TIM_t;

#define     TIM1_BASE_ADDRESS          0x40010000
#define 	TIM1   ((volatile TIM1_t *)TIM1_BASE_ADDRESS)



#define 	TIMER2_BASE		((volatile TIM_t *)0x40000000)
#define 	TIMER3_BASE		((volatile TIM_t *)0x40000400)
#define 	TIMER4_BASE		((volatile TIM_t *)0x40000800)
#define 	TIMER5_BASE		((volatile TIM_t *)0x40000C00)


#define TIM1_PWM 0 

/**CR1**/
#define     CKD1    9
#define     CKD0    8
#define     ARPE    7
#define     CMS1    6
#define     CMS0    5
#define     DIR     4
#define     OPM     3
#define     URS     2
#define     UDIS    1
#define     CEN     0

/**CCMR2**/
#define     OC4CE   15  /* Output compare 4 clear enable*/
#define     OC4M2   14  /* Output compare 4 mode bit 2 */
#define     OC4M1   13  /* Output compare 4 mode bit 1 */
#define     OC4M0   12  /* Output compare 4 mode bit 0 */
#define     OC4PE   11  /* Output compare 4 preload enable*/
#define     OC4FE   10  /* Output compare 4 fast enable*/
#define     CC4S1    9  /* Capture/Compare 4 selection bit 1*/
#define     CC4S0    8  /* Capture/Compare 4 selection bit 0*/
#define     OC3CE    7  /* Output compare 3 clear enable */
#define     OC3M2    6  /* Output compare 3 mode bit 2*/
#define     OC3M1    5  /* Output compare 3 mode bit 1*/
#define     OC3M0    4  /* Output compare 3 mode bit 0*/
#define     OC3PE    3  /* Output compare 3 preload enable*/
#define     OC3FE    2  /* Output compare 3 fast enable */
#define     CC3S1    1  /* Capture/Compare 3 selection bit 1*/
#define     CC3S0    0  /* Capture/Compare 3 selection bit 0*/
     
/*CCER*/             
#define     CC4P    13  /* Capture/Compare 4 output polarity */
#define     CC4E    12  /* Capture/Compare 4 output enable */
#define     CC3NP   11  /* Capture/Compare 3 complementary output polarity */
#define     CC3NE   10  /* Capture/Compare 3 complementary output enable */
#define     CC3P    9   /* Capture/Compare 3 output polarity */
#define     CC3E    8   /* Capture/Compare 3 output enable */
#define     CC2NP   7   /* Capture/Compare 2 complementary output polarity */
#define     CC2NE   6   /* Capture/Compare 2 complementary output enable */
#define     CC2P    5   /* Capture/Compare 2 output polarity */
#define     CC2E    4   /* Capture/Compare 2 output enable */
#define     CC1NP   3   /* Capture/Compare 1 complementary output polarity */
#define     CC1NE   2   /* Capture/Compare 1 complementary output enable */
#define     CC1P    1   /* Capture/Compare 1 output polarity */
#define     CC1E    0   /* Capture/Compare 1 output enable */


/***********************/

#define CR1_CEN			0
#define CR1_OPM			3
#define CR1_ARPE		7

//#define EGR_UG
//
//#define CCMR1_OC1M
#define CCMR1_OC1PE			3
#define CCMR1_OC2PE			11
#define CCMR2_OC3PE			3
#define CCMR2_OC4PE			11

//#define CCER_CC4P			//enable 4 channel

#define CCER_CC1E			0
#define CCER_CC2E			4
#define CCER_CC3E			8
#define CCER_CC4E			12

#define CCER_CC1P			1
#define CCER_CC2P			5
#define CCER_CC3P			9
#define CCER_CC4P			13



#endif /*_TIM1_PRIV_H_*/