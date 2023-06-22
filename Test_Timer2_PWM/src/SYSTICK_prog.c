/**
 * @file SYSTICK_prog.c
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
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SYSTICK_int.h"
#include "SYSTICK_priv.h"
#include "SYSTICK_config.h"

//u8 u8IntervalFlag == 
static void (*pvCallBackFunction)(void) = NULL;
static u8 u8IntervalFlag = SINGLE_INTERVAL;

void MSYSTICK_voidInit(void)
{
    //Check Interrupt
    #if SYSTICK_INTERRUPT_STATUS  ==  ENABLE_SYSTIC_INT
        SET_BIT (SYSTICK->CTRL ,TICKINT_BIT);
    #elif SYSTICK_INTERRUPT_STATUS  ==  DISABLE_SYSTIC_INT
        CLR_BIT (SYSTICK->CTRL ,TICKINT_BIT);
    #else
        #error "Configuration of SYSTICK_INTERRUPT_STATUS if False"
    #endif 

    //Choose CLK Source 
    #if SYSTICK_CLK_SOURCE == AHP_CLOCK_DIV_BY_8
        CLR_BIT (SYSTICK->CTRL ,CLKSOURCE_BIT);
    #elif SYSTICK_CLK_SOURCE == AHP_CLOCK
        SET_BIT (SYSTICK->CTRL ,CLKSOURCE_BIT);
    #else
        #error "Configuration of SYSTICK_INTERRUPT_STATUS if False"
    #endif 

    //Enable SYSTICK
    #if SYSTICK_ENABLE  ==  ENABLE_SYSTIC
    SET_BIT(SYSTICK->CTRL, ENABLE_BIT);
    #elif SYSTICK_ENABLE  ==  DISABLE_SYSTIC
    CLR_BIT(SYSTICK->CTRL, ENABLE_BIT);
    #else 
        #error "Configuration of SYSTICK_ENABLE if False"
    #endif 
}
void MSYSTICK_voidSetBusyWait(u32 Time_usec)
{
    SYSTICK -> LOAD = Time_usec ;
    while (GET_BIT(SYSTICK->CTRL ,COUNTFLAG_BIT )==0 );
    SYSTICK ->VAL =0 ;
}

void MSYSTICK_voidEnable(void)
{
    SET_BIT(SYSTICK->CTRL, ENABLE_BIT);
}
void MSYSTICK_voidDisable(void)
{
    CLR_BIT(SYSTICK->CTRL, ENABLE_BIT);
}
void MSYSTICK_voidEnableInterrupt(void)
{
    SET_BIT (SYSTICK->CTRL ,TICKINT_BIT);
}
void MSYSTICK_voidDisableInterrupt(void)
{
    CLR_BIT (SYSTICK->CTRL ,TICKINT_BIT);
}

void MSYSTICK_voidSetIntervalSingle(void (*NotificationFunction)(void)) // int once
{
    //enable int 
    SET_BIT (SYSTICK->CTRL ,TICKINT_BIT);
    pvCallBackFunction = NotificationFunction;
	u8IntervalFlag = SINGLE_INTERVAL;

}
void MSYSTICK_voidSetIntervalPeriodic(void (*NotificationFunction)(void))
{
    //enable int 
    SET_BIT (SYSTICK->CTRL ,TICKINT_BIT);
    pvCallBackFunction = NotificationFunction;
	u8IntervalFlag = PERIODIC_INTERVAL;

}

void MSYSTICK_voidGetElapsedTime(u32 * Local_pu32ElapsedTime)
{
    Local_pu32ElapsedTime = SYSTICK->LOAD - SYSTICK->VAL;

}
void MSYSTICK_voidGetRemainingTime(u32 *Local_pu32RemainingTime)
{
    Local_pu32RemainingTime=  SYSTICK->VAL;
}

void MSYSTICK_voidSetPreLoadValue(u32 Copy_u8LoadValue)
{
	SYSTICK -> LOAD = Copy_u8LoadValue;
}

void MSYSTICK_voidResetSysTick(void)
{
	SYSTICK -> VAL = 0;
}

void SysTick_Handler(void)
{
	u32 Local_u32TempVar;
	if(u8IntervalFlag == SINGLE_INTERVAL)
	{
		SYSTICK->LOAD = 0;
		SYSTICK->VAL = 0;
		CLR_BIT(SYSTICK->CTRL, ENABLE_BIT);
	}
	if(pvCallBackFunction != NULL)
	{
		pvCallBackFunction();
	}
	Local_u32TempVar = GET_BIT(SYSTICK->CTRL, COUNTFLAG_BIT);
}



