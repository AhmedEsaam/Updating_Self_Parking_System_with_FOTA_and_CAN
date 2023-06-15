/**
 * @file SYSTICK_config.h
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

#ifndef _SYSTICK_CONFIG_H
#define _SYSTICK_CONFIG_H

/**
 * @choose:  ENABLE_SYSTIC_INT  
 *           DISABLE_SYSTIC_INT
 * 
 */
#define SYSTICK_INTERRUPT_STATUS    DISABLE_SYSTIC_INT



/**
 * @choose:  AHB_CLOCK
 *           AHP_CLOCK_DIV_BY_8
 * 
 * 
 */
#define SYSTICK_CLK_SOURCE  AHP_CLOCK_DIV_BY_8



/**
 * @choose:  ENABLE_SYSTIC  
 *           DISABLE_SYSTIC
 * 
 */
#define SYSTICK_ENABLE    ENABLE_SYSTIC


#endif /*_SYSTICK_CONFIG_H*/
