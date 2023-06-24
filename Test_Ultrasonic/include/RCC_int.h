
/**
 * @file        RCC_int.h
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
#ifndef _RCC_INT_H_
#define _RCC_INT_H_

#define     RCC_AHB1        0
#define     RCC_AHB2        1
#define     RCC_APB1        2
#define     RCC_APB2        3

#define     RCC_GPIOA       0
#define     RCC_GPIOB       1
#define     RCC_GPIOC       2

#define RCC_TIM1            0
#define RCC_USART1          4
#define RCC_USART6          5
#define RCC_ADC1            8
#define RCC_SDIO            11
#define RCC_SPI1            12
#define RCC_SPI4            13
#define RCC_SYSCFG          14
#define RCC_TIM9            16
#define RCC_TIM10           17
#define RCC_TIM11           18

#define RCC_TIM5			3
#define RCC_TIM4			2
#define RCC_TIM3			1
#define RCC_TIM2			0


typedef enum{
    RCC_CLOCK_HSI,
    RCC_CLOCK_HSE,
    RCC_CLOCK_PLL,

}RCC_CLOCK_t;

/**
 * @brief Function to Initialize The System Clock Source 
 *          prebuild Configuration 
 * @return ** void 
 */
void MRCC_voidInit(void);

/**
 * @brief Function To Enable Peripheral Clock
 * 
 * @param Copy_u8PeripheralBus 
 *          Choose From : RCC_AHB1, RCC_AHB2, RCC_APB1, RCC_APB2
 * @param Copy_u8PeripheralID 
 *          for RCC_AHB1 choose From : RCC_GPIOA, RCC_GPIOB, RCC_GPIOC
 *          for RCC_APB2 choose from : RCC_TIM1, RCC_USART1, RCC_USART6, RCC_ADC1,
 *                                     RCC_SDIO, RCC_SPI1, RCC_SPI4, RCC_SYSCFG, 
 *                                     RCC_TIM9, RCC_TIM10, RCC_TIM11
 * @return ** void 
 */
void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeriperhalID);

/**
 * @brief Function To Disable Peripheral Clock
 * 
 * @param Copy_u8PeripheralBus 
 *          Choose From : RCC_AHB1, RCC_AHB2, RCC_APB1, RCC_APB2
 * @param Copy_u8PeripheralID 
 *          choose From : RCC_GPIOA, RCC_GPIOB, RCC_GPIOC
 * @return ** void 
 */
void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeriperhalID);

/**
 * @brief  Function To Set PLL Clock Source 
 * 
 * @param clock  choose from  (RCC_CLOCK_HSI, RCC_CLOCK_HSE,RCC_CLOCK_PLL)
 * @return ** void 
 */
void RCC_SetPLLClockSource(const RCC_CLOCK_t clock);

/**
 * @brief  Function To Set RCC Clock Source 
 * 
 * @param clock  choose from  (RCC_CLOCK_HSI, RCC_CLOCK_HSE,RCC_CLOCK_PLL)
 * @return ** void 
 */
void RCC_SetClockSource(const RCC_CLOCK_t clock);

#endif /*_RCC_INT_H_*/
