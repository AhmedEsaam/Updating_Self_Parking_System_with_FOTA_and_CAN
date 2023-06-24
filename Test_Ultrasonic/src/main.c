
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_int.h"
#include "GPIO_Interface.h"
#include "SYSTICK_int.h"
#include "NVIC_interface.h"
#include "TIM_int.h"
#include "Ultrasonic.h"

extern volatile u32 Ultrasonic_Distance;

void main()
{

	/*System Clock initialization*/
	MRCC_voidInit();
	/*--------------------------------------- Timer 3 ----------------------------------------------------*/
	/*GPIO pins initialization*/
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOB);
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOC);

	MGPIO_ErrSetPinMode(GPIO_PORTA,GPIO_PIN6,GPIO_ALTERNATE_FUNCTION);
	MGPIO_ErrSetPinAlternateFunction(GPIO_PORTA,GPIO_PIN6,2);

	MGPIO_ErrSetPinMode(GPIO_PORTA,GPIO_PIN7,GPIO_OUTPUT);
	MGPIO_ErrSetPinOutputSpeed(GPIO_PORTA, GPIO_PIN7 , GPIO_LOW_SPEED);
	MGPIO_ErrSetPinPullUpPullDown(GPIO_PORTA, GPIO_PIN7 ,GPIO_OUTPUT_PUSH_PULL);
	
	MRCC_voidEnablePeripheralClock(RCC_APB1,RCC_TIM3);
	MGPIO_ErrSetPinMode(GPIO_PORTA,GPIO_PIN5,GPIO_OUTPUT);

	/*Interrupt initialization*/
	MNVIC_voidEnablePeripheralInterrupt(29); // Enable Timer3 Global Interrupt

	/*Timer initialization*/
	Timer3_voidStart();
	Timer3_voidCapture_Compare_Init();


	while(1)
	{
		MGPIO_ErrSetPinValue(GPIO_PORTA,GPIO_PIN7,LOW);

		Ultrsonic_Trigger();

		while(Ultrasonic_Distance == 0);

		if(Ultrasonic_Distance <=20)
		{
			MGPIO_ErrSetPinValue(GPIO_PORTA,GPIO_PIN7,HIGH);
		}
	}

}
