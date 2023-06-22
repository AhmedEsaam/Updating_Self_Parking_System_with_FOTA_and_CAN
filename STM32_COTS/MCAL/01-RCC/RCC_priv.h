

/**
 * @file        RCC_priv.h
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

#ifndef _RCC_PRIV_H_
#define _RCC_PRIV_H_

// #define RCC_BASE_ADDRESS        0x40023800
// #define RCC_CR                  (*(vloatile u32*)(RCC_BASE_ADDRESS+0x00)
// #define RCC_PLLCFGR             (*(vloatile u32*)(RCC_BASE_ADDRESS+0x00)
// #define RCC_CR                  (*(vloatile u32*)(RCC_BASE_ADDRESS+0x00)
// #define RCC_CR                  (*(vloatile u32*)(RCC_BASE_ADDRESS+0x00)
// #define RCC_CR                  (*(vloatile u32*)(RCC_BASE_ADDRESS+0x00)
// #define RCC_CR                  (*(vloatile u32*)(RCC_BASE_ADDRESS+0x00)
// #define RCC_CR                  (*(vloatile u32*)(RCC_BASE_ADDRESS+0x00)
// #define RCC_CR                  (*(vloatile u32*)(RCC_BASE_ADDRESS+0x00)

typedef struct RCC_priv
{
    /* data */
    volatile u32 CR;  // volatile to disable optimization if the reg is input 
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 AHB1RSTR;
    volatile u32 AHB2RSTR;
    volatile u32 Reserved1[2];
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 Reserved2[2];
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 Reserved3[2];
    volatile u32 APB1ENR;
    volatile u32 APB2ENR;
    volatile u32 Reserved4[2];
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 Reserved5[2];
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 Reserved6[2];
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 Reserved7[2];
    volatile u32 SSCGR;
    volatile u32 PLLI2SCFGR;
    volatile u32 reserved8;
    volatile u32 DCKCFGR;
    // u32 to skip 4 bytes which is the size of each register 
}RCC_t;

#define RCC ((volatile RCC_t*)0x40023800)

#define     DISABLE                 0
#define     ENABLE                  1

/*Prescaler For APB2*/
#define APB2_NO_DIV           0x0000
#define APB2_DIVIDE_BY_2      0x8000
#define APB2_DIVIDE_BY_4      0xA000
#define APB2_DIVIDE_BY_8      0xC000
#define APB2_DIVIDE_BY_16     0xE000


/*Prescaler For APB1*/
#define APB1_NO_DIV           0x0000
#define APB1_DIVIDE_BY_2      0x1000
#define APB1_DIVIDE_BY_4      0x1400
#define APB1_DIVIDE_BY_8      0x1800
#define APB1_DIVIDE_BY_16     0x1C00

/**
 * Prescaler for AHB
 *  System Clock Options: (HSI, HSE,PLL)
 */
#define SYS_CLOCK_NO_DIVISION   0X00
#define SYS_CLOCK_DIVIDE_BY_2   0X80
#define SYS_CLOCK_DIVIDE_BY_4   0x90
#define SYS_CLOCK_DIVIDE_BY_8   0xA0
#define SYS_CLOCK_DIVIDE_BY_16  0xB0


/***************************************************************************************************
 ************       [1]     RCC clock control register (RCC_CR) BITS                ****************
 ***************************************************************************************************/
#define     PLLI2SRDY       27 /* PLLI2S clock ready flag */
#define     PLLI2SON        26 /* PLLI2S enable */ 
#define     PLLRDY          25 /* Main PLL (PLL) clock ready flag */
#define     PLLON           24 /* Main PLL (PLL) enable */
#define     CSSON           19 /* Clock security system enable */
#define     HSEBYP          18 /*HSE clock bypass*/ 
#define     HSERDY          17 /* HSE clock ready flag */
#define     HSEON           16 /* HSE clock enable */
/*Bits  15:8 HSICAL[7:0]: Internal high-speed clock calibration*/
/*Bits 7:3 HSITRIM[4:0]: Internal high-speed clock trimming*/
/************************************************************/
#define     HSIRDY          1  /* Internal high-speed clock ready flag */
#define     HSION           0  /*HSE clock bypass*/ 

/***************************************************************************************************
 *************       [2]     RCC PLL configuration register (RCC_PLLCFGR) BITS       ***************
 ***************************************************************************************************/
#define PLLQ3   27
#define PLLQ2   26
#define PLLQ1   25
#define PLLQ0   24
#define PLLSRC  22
#define PLLP1   17
#define PLLP0   16
#define DIVISION_FACTOR_PLL_MAIN_SYSCLK_MASK    0XFFF0FFFF  /*PLLP: Main PLL (PLL) division factor for main system clock*/
#define MULTIPLICATION_FACTOR_PLLN_MASK         0XFFFF003F  /*PLLN: Main PLL (PLL) multiplication factor for VCO*/
#define DIVISION_FACTOR_PLLM_MASK               0XFFFFFFC0  /*PLLM: Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock*/ 

/***************************************************************************************************
 ************       [3]     RCC clock configuration register (RCC_CFGR) BITS        ****************
 ***************************************************************************************************/
#define MCO2_b1     31  /*Microcontroller clock output 2 bit1*/
#define MCO2_b0     30  /*Microcontroller clock output 2 bit0*/
#define MCO2PRE_b2  29  /*MCO2 prescaler bit2*/
#define MCO2PRE_b1  28  /*MCO2 prescaler bit1*/
#define MCO2PRE_b0  27  /*MCO2 prescaler bit0*/
#define MCO1PRE_b2  26  /*MCO1 prescaler bit2*/
#define MCO1PRE_b1  25  /*MCO1 prescaler bit1*/
#define MCO1PRE_b0  24  /*MCO1 prescaler bit0*/
#define I2SSRC      23  /*I2S clock selection*/
#define MCO1_b1     22  /*Microcontroller clock output 1 bit1*/
#define MCO1_b0     21  /*Microcontroller clock output 1 bit0*/
#define HSE_DIV_FACTOR_FOR_RTC_CLK_MASK 0XFFE0FFFF    /*RTCPRE: HSE division factor for RTC clock*/
#define APB_HIGH_SPEED_PRESCALER_MASK   0XFFFF1FFF    /*PPRE2: APB high-speed prescaler (APB2)*/
#define APB_LOW_SPEED_PRESCALLER_MASK   0XFFFFE3FF    /*PPRE1: APB Low speed prescaler (APB1)*/ 
#define AHB_PRESCALER_MASK 0XFFFFFF0F       /*HPRE: AHB prescaler Mask*/
#define SWS_b1  3                           /*System clock switch status bit1 (Set by HW for verification)*/
#define SWS_b0  2                           /*System clock switch status bit0 (Set by HW for verification)*/
#define SW_b1   1                           /*System clock switch bit 1 */
#define SW_b0   0                           /*System clock switch bit 0 */
/***************************************************************************************************
 *************      [4]     RCC clock interrupt register (RCC_CIR) BITS             ****************
 ***************************************************************************************************/

/***************************************************************************************************
 ************       [5]     RCC AHB1 peripheral reset register (RCC_AHB1RSTR) BITS  ****************
 ***************************************************************************************************/
#define AHB1RSTR_GPIOA_BIT  0
#define AHB1RSTR_GPIOB_BIT  1
#define AHB1RSTR_GPIOC_BIT  2
#define AHB1RSTR_GPIOD_BIT  3
#define AHB1RSTR_GPIOE_BIT  4
#define AHB1RSTR_GPIOH_BIT  7
#define AHB1RSTR_CRCRST_BIT 12
#define AHB1RSTR_DMA1_BIT   21
#define AHB1RSTR_DMA2_BIT   22

/***************************************************************************************************
 *************      [6]     RCC AHB2 peripheral reset register (RCC_AHB2RSTR) BITS  ****************
 ***************************************************************************************************/
#define AHB2RSTR_OTGFS_BIT  22 


/***************************************************************************************************
 ************       [7]     RCC APB1 peripheral reset register for (RCC_APB1RSTR) BITS  ************
 ***************************************************************************************************/
#define  APB1RSTR_PWR_BIT           28
#define  APB1RSTR_I2C3_BIT          23
#define  APB1RSTR_I2C2_BIT          22
#define  APB1RSTR_I2C1_BIT          21
#define  APB1RSTR_USART2_BIT        17
#define  APB1RSTR_SPI3_BIT          15
#define  APB1RSTR_SPI2_BIT          14
#define  APB1RSTR_WWDG_BIT          11
#define  APB1RSTR_TIM5_BIT          3
#define  APB1RSTR_TIM4_BIT          2
#define  APB1RSTR_TIM3_BIT          1
#define  APB1RSTR_TIM2_BIT          0

/***************************************************************************************************
 *************      [8]     RCC APB2 peripheral reset register (RCC_APB2RSTR) BITS     *************
 ***************************************************************************************************/
#define  APB2RSTR_TIM11      18
#define  APB2RSTR_TIM10      17
#define  APB2RSTR_TIM9       16
#define  APB2RSTR_YSCFG      14
#define  APB2RSTR_SPI4       13
#define  APB2RSTR_SPI1       12
#define  APB2RSTR_SDIO       11
#define  APB2RSTR_ADC1       8
#define  APB2RSTR_USART6     5
#define  APB2RSTR_USART1     4
#define  APB2RSTR_TIM1       0

/***************************************************************************************************
 ************       [9]     RCC AHB1 peripheral clock enable register (RCC_AHB1ENR) BITS ***********
 ***************************************************************************************************/
// #define  
// #define  
// #define  
// #define  
// #define  
// #define  
// #define  
// #define  
// #define  
// #define  
// #define  
// #define  

/***************************************************************************************************
 *************      [10]     RCC AHB2 peripheral clock enable register (RCC_AHB2ENR) BITS  *********
 ***************************************************************************************************/


/***************************************************************************************************
 ************       [11]    RCC APB1 peripheral clock enable register (RCC_APB1ENR) BITS  **********
 ***************************************************************************************************/

/***************************************************************************************************
 *************      [12]     RCC APB2 peripheral clock enable register (RCC_APB2ENR) BITS   ********
 ***************************************************************************************************/
#define TIM1_EN 0   /* 0 is the peripheral ID */


/***************************************************************************************************
 ************       [13]     RCC AHB1 peripheral clock enable in low power mode register        ****
 ************                    (RCC_AHB1LPENR) BITS                                ***************
 ***************************************************************************************************/


/***************************************************************************************************
 *************      [14]     RCC AHB2 peripheral clock enable in low power mode register        ****
 *************                  (RCC_AHB2LPENR) BITS                                 ***************
 ***************************************************************************************************/


/***************************************************************************************************
 ************       [15]     RCC APB1 peripheral clock enable in low power mode register        ****
 ************                   (RCC_APB1LPENR) BITS                                 ***************
 ***************************************************************************************************/


/***************************************************************************************************
 *************      [16]     RCC APB2 peripheral clock enabled in low power mode register       ****
 *************                      (RCC_APB2LPENR) BITS                             ***************
 ***************************************************************************************************/

/***************************************************************************************************
 ************       [17]     RCC Backup domain control register (RCC_BDCR) BITS      ***************
 ***************************************************************************************************/


/***************************************************************************************************
 *************      [18]     RCC clock control & status register (RCC_CSR) BITS      ***************
 ***************************************************************************************************/


/***************************************************************************************************
 ************       [19]     RCC spread spectrum clock generation register (RCC_SSCGR) BITS ********
 ***************************************************************************************************/


/***************************************************************************************************
 *************      [20]     RCC PLLI2S configuration register (RCC_PLLI2SCFGR) BITS      **********
 ***************************************************************************************************/

/***************************************************************************************************
 ************       [21]     RCC Dedicated Clocks Configuration Register (RCC_DCKCFGR) BITS  *******
 ***************************************************************************************************/



#endif /*_RCC_PRIV_H_*/