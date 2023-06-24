/*
 * ----------------------------------------------------------------------------------
 * Filename		:	SYSTICK_program.c
 *
 * Author		:	Ahmed Essam El-Mogy
 * Created on	:	MAY 8, 2023
 * Version		:	v1.0
 * C Standard	:	C99
 * Compiler		:	GNU ARM GCC
 * Controller	:	STM32F401CCU6 (32-bit Architecture)
 * Layer		:	MCAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version 		Date 				Author 						Describtion
 * v1.0 		MAY 8, 2023 		Ahmed Essam El-Mogy 		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_int.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

/* Global Variable To Save IntervalType */
u8 Global_u8IntervalSinglePeriodic;


/**
 *@brief    Initialize SysTick Timer
 *
*/
void MSYSTICK_ErrInit(void)
{
    /* Select SysTick Clock Source */
    #if SYSTICK_CLK_SOURCE == SYSTICK_CLK_AHB_DIVIDED_BY_8
        /* Set SysTick Clock Source As AHB/8 */
        CLR_BIT(SYSTICK->CTRL, CLKSOURCE);

    #elif SYSTICK_CLK_SOURCE == SYSTICK_CLK_AHB
        /* Set SysTick Clock Source As AHB */
        SET_BIT(SYSTICK->CTRL, CLKSOURCE);

    #else
        #error "SYSTICK Clock Source Configuration Error"

    #endif

    /* Check Interrupt Enable */
    #if SYSTICK_INTERRUPT_EN == SYSTICK_INTERRUPT_ENABLE
        /* Enable Interrupt */
        SET_BIT(SYSTICK->CTRL, TICKINT);

    #elif SYSTICK_INTERRUPT_EN == SYSTICK_INTERRUPT_DISABLE
        /* Disable Interrupt */
        CLR_BIT(SYSTICK->CTRL, TICKINT);

    #else
        #error "SYSTICK Interrupt Enabling Configuration Error"

    #endif

    /* Check Interrupt Enable */
    #if SYSTICK_EN == SYSTICK_ENABLE
        /* Enable Interrupt */
        SET_BIT(SYSTICK->CTRL, TICKINT);

    #elif SYSTICK_EN == SYSTICK_DISABLE
        /* Disable Interrupt */
        CLR_BIT(SYSTICK->CTRL, TICKINT);

    #else
        #error "SYSTICK Enable Configuration Error"

    #endif
    
}

// enable/disble systick..............................................
// enable/disble interrupt............................................

SYSTICK_Error_t MSYSTICK_ErrSetBusyWait(u32 Copy_u32BusyWaitInMicroSec)
{
    /* Put Busy Wait Value Into Reload Register */
    (SYSTICK->LOAD) &= LOAD_BIT_MASK;
    (SYSTICK->LOAD) |= Copy_u32BusyWaitInMicroSec;
    /* Clear Current Value */
    SYSTICK->VAL = 0;

    while(GET_BIT(SYSTICK->CTRL, COUNTFLAG) == 0);
    /* Clear Current Value */
    SYSTICK->VAL = 0;
}


/**
 *@brief    Set SysTick Timer Busy-Wait Time In MicroSeconds
 *
 *@param    Copy_u32BusyWaitInMicroSec 
 *@return   SYSTICK_Error_t 
*/
SYSTICK_Error_t MSYSTICK_ErrSetPreoadValue(u32 Copy_u32PreloadValue)
{
    /* Set Error Handling Initial State */
    SYSTICK_Error_t Local_u8SYSTICKErrorState;
    Local_u8SYSTICKErrorState = SYSTICK_Ok;

    /* Checking Busy Wait Value in usec is within 24 Bits */
    if (Copy_u32PreloadValue > 0x00FFFFFF)
    {
        /* Change Error State */
        Local_u8SYSTICKErrorState = SYSTICK_InvalidBusyWaitValue;
    }
    else
    {
        /* Put Busy Wait Value Into Reload Register */
        (SYSTICK->LOAD) &= LOAD_BIT_MASK;
        (SYSTICK->LOAD) |= Copy_u32PreloadValue;
        // synchronous
    }

    /* return Error State */
    return Local_u8SYSTICKErrorState;
}


/**
 *@brief    Get SystTick Timer Elapsed Time In MicroSeconds
 *
 *@param    Copy_pu32ElapsedTimeInMicroSec 
 *@return   SYSTICK_Error_t 
*/
SYSTICK_Error_t MSYSTICK_ErrGetElapsedTime(u32 *Copy_pu32ElapsedTimeInMicroSec)
{
    /* Declare Variables to Store SysTick Reload and Current Values */
    u32 Local_u32ElapsedTime;
    u32 Local_u32ReloadValue;
    u32 Local_u32CurrentValue;

    /* Set Error Handling Initial State */
    SYSTICK_Error_t Local_u8SYSTICKErrorState;
    Local_u8SYSTICKErrorState = SYSTICK_Ok;

    /* Calculate Elapsed Time */
    Local_u32ReloadValue = (SYSTICK->LOAD) & ~(LOAD_BIT_MASK);
    Local_u32CurrentValue = (SYSTICK->VAL) & ~(CURRENT_BIT_MASK);
    Local_u32ElapsedTime = Local_u32ReloadValue - Local_u32CurrentValue;

    /* Change The Dereferenced Value of the Elapsed Time Pointer */
    *Copy_pu32ElapsedTimeInMicroSec = Local_u32ElapsedTime;

    /* return Error State */
    return Local_u8SYSTICKErrorState;
}


/**
 *@brief    Get SysTick Remaining Time In MicroSeconds
 *
 *@param    Copy_pu32RemainingTimeInMicroSec 
 *@return   SYSTICK_Error_t 
*/
SYSTICK_Error_t MSYSTICK_ErrGetRemainingTime(u32 *Copy_pu32RemainingTimeInMicroSec)
{
    /* Declare Variable to Store Current Value */
    u32 Local_u32CurrentValue;

    /* Get Remaining Time In MicroSeconds */
    Local_u32CurrentValue = (SYSTICK->VAL) & ~(CURRENT_BIT_MASK);

    /* Change The Dereferenced Value of the Remaining Time Pointer */
    *Copy_pu32RemainingTimeInMicroSec = Local_u32CurrentValue;

    /* return Error State */
    return SYSTICK_Ok;
}


///**
// *@brief    Set SysTick Timer Interval Type as Single
// *
//*/
//void MSYSTICK_ErrSetIntervalSingle(void)
//{
//    /* Set Interval Type To Be Single */
//    Global_u8IntervalSinglePeriodic = SYSTICK_INTERVAL_SINGLE;
//    /* SysTick Exception Interrupt enable */
//    SET_BIT(SYSTICK->CTRL, TICKINT);
//}
//
//
///**
// *@brief    Set SysTick Timer Interval Type as Periodic
// *
//*/
//void MSYSTICK_ErrSetIntervalPeriodic(void)
//{
//    /* Set Interval Type To Be Periodic */
//    Global_u8IntervalSinglePeriodic = SYSTICK_INTERVAL_PERIODIC;
//    /* SysTick Exception Interrupt enable */
//    SET_BIT(SYSTICK->CTRL, TICKINT);
//}
//



