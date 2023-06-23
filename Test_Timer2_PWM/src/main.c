/**
 * @file main.c
 * @author Doaa Hagag (doaahagag128@gmail.com)
 * @brief 	for timer2 pwm test on led intensity
 * @compiler:   GNU ARM-GCC
 * @controller: STM32F40ICCU6
 * @layer:      MCAL
 * @version 2
 * @date 2023-06-20
 * @copyright Copyright (c) 2023
 *
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_int.h"
#include "GPIO_interface.h"
#include "TIM_int.h"
#include "SYSTICK_int.h"
void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(0,1);
	MRCC_voidEnablePeripheralClock(2,0);

	// Initialize SYSTIC
	MSYSTICK_voidInit();

	MGPIO_ErrSetPinMode(GPIO_PORTB,GPIO_PIN10,GPIO_ALTERNATE_FUNCTION);
	MGPIO_ErrSetPinAlternateFunction(GPIO_PORTB,GPIO_PIN10,MGPIO_AF1);

	MGTimer2_voidInit(CHANNEL3);
	MGTimer2_void_Prescaller(160);
	MGTimer2_void_PeriodValue(1000-1);
	MGTimer2_voidStart();
	// Enable SYSTICK
	MSYSTICK_voidEnable();

	while(1)
	{

		MGTimer2_void_CompValue( CHANNEL3, 700);
		// Busy wait for 1 sec
		MSYSTICK_voidSetBusyWait(2000000);

		MGTimer2_void_CompValue( CHANNEL3,100);
		// Busy wait for 1 sec
		MSYSTICK_voidSetBusyWait(2000000);

	}


}
