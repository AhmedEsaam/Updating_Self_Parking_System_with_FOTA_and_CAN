/*
 * ----------------------------------------------------------------------------------
 * Filename		:	SYSTICK_private.h
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

#define SYSTICK_PRIVATE_H_
#ifdef SYSTICK_PRIVATE_H_

typedef struct
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
}SYSTICK_t;

#define     SYSTICK_BASE_ADDRESS        0xE000E010

#define     SYSTICK                     ((volatile SYSTICK_t *)SYSTICK_BASE_ADDRESS)

// SysTick control and status register (STK_CTRL)
#define     ENABLE                      0       // Counter enable
#define     TICKINT                     1       // SysTick exception request enable
#define     CLKSOURCE                   2       // Clock source selection
#define     COUNTFLAG                   16      // Returns 1 if timer counted to 0 since last time this was read

// SysTick reload value register (STK_LOAD)
#define     LOAD_BIT_MASK               0xff000000

// SysTick current value register (STK_VAL)
#define     CURRENT_BIT_MASK            0xff000000

// SysTick calibration value register (STK_CALIB)
#define     TENMS_BIT_MASK              0xff000000      // Calibration value
#define     NOREF                       31              // NOREF flag. Reads as zero. Indicates that a separate reference clock is provided
#define     SKEW                        30              // Reads as zero. Indicates whether the TENMS value is exact


#endif /* SYSTICK_PRIVATE_H_ */