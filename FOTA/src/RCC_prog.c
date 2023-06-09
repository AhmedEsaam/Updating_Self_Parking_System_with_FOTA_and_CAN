/**
 * @file        RCC_prog.c
 * @author      Doaa Hagag (doaahagag128@gmail.com)
 * @compiler:   GNU ARM-GCC
 * @controller: STM32F40ICCU6
 * @layer:      MCAL 
 * @version     0.2
 * @date        2023-05-27
 * @brief       Add 2 post build configuration functions 
 *              RCC_SetPLLClockSource
 *              RCC_SetClockSource
 * @copyright   Copyright (c) 2023
 * 
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_int.h"
#include "RCC_priv.h"
#include "RCC_config.h"

void MRCC_voidInit(void) // prebuild
{
    #if CPU_CLK_SOURCE == HSI
        /**enable HSI**/
        SET_BIT(RCC ->CR ,HSION);
        /**select HSI As System CLK(CPU CLK)**/
        CLR_BIT(RCC ->CFGR,SW_b0);
        CLR_BIT(RCC ->CFGR,SW_b1);
        while (GET_BIT(RCC ->CR , HSIRDY) ==0 ); /*Busy wait until HSI to be Stable*/
    #elif CPU_CLK_SOURCE == HSE
        /**Enable HSE**/
        SET_BIT(RCC ->CR ,HSEON);
        /**select HSE As System CLK(CPU CLK)**/
        SET_BIT(RCC ->CFGR,SW_b0);
        CLR_BIT(RCC ->CFGR,SW_b1);   
        while (GET_BIT(RCC ->CR , HSERDY) ==0 ); /*Busy wait until HSE to be Stable*/    
    #elif CPU_CLK_SOURCE == PLL
        #if PLL_SOURCE   ==  HSI
            /**Enable HSI**/
            SET_BIT(RCC ->CR ,HSION);
            while (GET_BIT(RCC ->CR , HSIRDY) ==0 ); /*Busy wait until HSI to be Stable*/
            /**Select HSI As PLL Source**/
            CLR_BIT(RCC ->PLLCFGR ,PLLSRC )
            /**Enable PLL**/
            SET_BIT(RCC->CR , PLLON);
            /*Select PLL as system CLK (CPU Clock)*/
            CLR_BIT(RCC ->CFGR,SW_b0);
            SET_BIT(RCC ->CFGR,SW_b1); 
            
        #elif PLL_SOURCE  ==   HSE
            /**Enable HSE**/
            SET_BIT(RCC ->CR ,HSEON);
            while (GET_BIT(RCC ->CR , HSERDY) ==0 ); /*Busy wait until HSE to be Stable*/ 
            /*Select HSE as PLL source*/
            SET_BIT(RCC ->PLLCFGR ,PLLSRC )
            /**Enable PLL**/
            SET_BIT(RCC->CR , PLLON);
            /*Select PLL as system CLK (CPU Clock)*/
            CLR_BIT(RCC ->CFGR,SW_b0);
            SET_BIT(RCC ->CFGR,SW_b1); 
        #else 
            #error "RCC PLL_SOURCE   Configuration Error"
        #endif
        while (GET_BIT(RCC ->CR , PLLRDY) ==0 ); /*Busy wait until PLL to be Stable*/
    #else 
        #error  "RCC CPU_CLK_SOURCE  Configuration Error"
    #endif

    /* Set Prescaler For AHB*/
    RCC->CFGR |=AHB_PRESCALER;

    /* Set Prescaler For APB1 and APB2 */
    RCC->CFGR |= APB1_PRESCALER;
    RCC->CFGR |= APB2_PRESCALER;




}


void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID) //postbuild
{
    switch(Copy_u8PeripheralBus)
    {
        case RCC_AHB1:
            SET_BIT(RCC->AHB1ENR, Copy_u8PeripheralID);
        break;
        case RCC_AHB2:
            SET_BIT(RCC->AHB2ENR, Copy_u8PeripheralID);
        break;
        case RCC_APB1:
            SET_BIT(RCC->APB1ENR, Copy_u8PeripheralID);
        break;
        case RCC_APB2:
            SET_BIT(RCC->APB2ENR, Copy_u8PeripheralID);
        break;
        default:
            // return error
        break;
    }

}

void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID ) //postbuild
{
    switch(Copy_u8PeripheralBus)
    {
        case RCC_AHB1:
            CLR_BIT(RCC->AHB1ENR, Copy_u8PeripheralID);
        break;
        case RCC_AHB2:
            CLR_BIT(RCC->AHB2ENR, Copy_u8PeripheralID);
        break;
        case RCC_APB1:
            CLR_BIT(RCC->APB1ENR, Copy_u8PeripheralID);
        break;
        case RCC_APB2:
            CLR_BIT(RCC->APB2ENR, Copy_u8PeripheralID);
        break;
        default:
            // return error
        break;
    }
}

void RCC_SetPLLClockSource(const RCC_CLOCK_t clock) {
    switch(clock) {
        case RCC_CLOCK_HSI:
            /**Enable HSI**/
            SET_BIT(RCC ->CR ,HSION);
            while (GET_BIT(RCC ->CR , HSIRDY) ==0 ); /*Busy wait until HSI to be Stable*/
            /**Select HSI As PLL Source**/
            CLR_BIT(RCC ->PLLCFGR ,PLLSRC );
            break;
        case RCC_CLOCK_HSE:
            /**Enable HSE**/
            SET_BIT(RCC ->CR ,HSEON);
            while (GET_BIT(RCC ->CR , HSERDY) ==0 ); /*Busy wait until HSE to be Stable*/ 
            /*Select HSE as PLL source*/
            SET_BIT(RCC ->PLLCFGR ,PLLSRC );
            break;
        default:
            break;
    }

}

void RCC_SetClockSource(const RCC_CLOCK_t clock) {
    switch(clock) {
        case RCC_CLOCK_HSI:
            /**enable HSI**/
            SET_BIT(RCC ->CR ,HSION);            
            /**select HSI As System CLK(CPU CLK)**/
            CLR_BIT(RCC ->CFGR,SW_b0);
            CLR_BIT(RCC ->CFGR,SW_b1);
            while (GET_BIT(RCC ->CR , HSIRDY) ==0 ); /*Busy wait until HSI to be Stable*/
            break;
        case RCC_CLOCK_HSE:
            /**Enable HSE**/
            SET_BIT(RCC ->CR ,HSEON);
            /**select HSE As System CLK(CPU CLK)**/
            SET_BIT(RCC ->CFGR,SW_b0);
            CLR_BIT(RCC ->CFGR,SW_b1);   
            while (GET_BIT(RCC ->CR , HSERDY) ==0 ); /*Busy wait until HSE to be Stable*/ 
            break;
        case RCC_CLOCK_PLL:
            /**Enable PLL**/
            SET_BIT(RCC->CR , PLLON);
            /*Select PLL as system CLK (CPU Clock)*/
            CLR_BIT(RCC ->CFGR,SW_b0);
            SET_BIT(RCC ->CFGR,SW_b1); 
            break;
        default:
            break;
    }
}

