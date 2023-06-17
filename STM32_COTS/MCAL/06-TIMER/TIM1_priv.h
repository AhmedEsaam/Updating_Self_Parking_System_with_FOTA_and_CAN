/**
 * @file TIM1_priv.h
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
    volatile u32 CCMR2; // capture/compare mode register 2 
    volatile u32 CCER;   
    volatile u32 CNT;
    volatile u32 PSC;
    volatile u32 ARR;  //
    volatile u32 RCR;
    volatile u32 CCR1;
    volatile u32 CCR2;
    volatile u32 CCR3;
    volatile u32 CCR4;
    volatile u32 BDTR;
    volatile u32 DCR;
    volatile u32 DMAR;

}TIM1_t;

#define     TIM1_BASE_ADDRESS          0x40010000
#define TIM1   ((volatile TIM1_t *)TIM1_BASE_ADDRESS)

#define TIM1_PWM 0 


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
#endif /*_TIM1_PRIV_H_*/