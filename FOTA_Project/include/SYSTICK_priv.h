/**
 * @file SYSTICK_priv.h
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

#ifndef _SYSTICK_PRIV_H
#define _SYSTICK_PRIV_H

// #define STK_CTRL    (*(volatile u32 * )0xE000E010)
// #define STK_LOAD    (*(volatile u32 * )0xE000E014)
// #define STK_VAL     (*(volatile u32 * )0xE000E018)
// #define STK_CALIB   (*(volatile u32 * )0xE000E01C)


typedef struct SYSTICK_priv
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
}STK_t;

#define SYSTICK   ((volatile STK_t *)0xE000E010)

/***************************************************************************************************
 ************       [1] SysTick control and status register (STK_CTRL) BITS         ****************
 ***************************************************************************************************/
#define ENABLE_BIT      0           /*SYSTICK enable*/
#define TICKINT_BIT     1           /*SysTick exception request enable*/
#define CLKSOURCE_BIT   2           /*Clock source selection*/
#define COUNTFLAG_BIT   16          /*COUNTFLAG :Returns 1 if timer counted to 0 since last time this was read*/

/***************************************************************************************************
 ************       [4] SysTick calibration value register (STK_CALIB)BITS          ****************
 ***************************************************************************************************/
#define NOREF           31
#define SKEW            30

/**************************************/
#define ENABLE_SYSTIC_INT   0
#define DISABLE_SYSTIC_INT  1
/**************************************/
#define AHB_CLOCK          1
#define AHP_CLOCK_DIV_BY_8 0
/**************************************/

#define ENABLE_SYSTIC   1 
#define DISABLE_SYSTIC  0


/*************************************/
#define     SINGLE_INTERVAL         0
#define     PERIODIC_INTERVAL       1


#endif /*_SYSTICK_PRIV_H*/