#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Interface.h"
#include "SYSTICK_int.h"

#include "TIM_int.h"
#include "Ultrasonic.h"
#include "Ultrasonic_conf.h"

volatile u16 Ultrasonic_Distance;
u32 IC_Val1;
u32 IC_Val2;
u32 Time;
u8 flag;
/*40 kHZ freq*/
void TIM3_IRQHandler(void)
{

	if (flag == 0)
	{
		IC_Val1 = Timer3_voidReadCaptureVal();
		flag = 1;
	}
	else if(flag == 1)
	{
		IC_Val2 = Timer3_voidReadCaptureVal();
		Timer3_u16Count(0);
		flag = 0;
		Time = IC_Val2 - IC_Val1;
		Ultrasonic_Distance = Time * .343 / 3.85;
	}
}
void Ultrsonic_Trigger(void)
{
	MSYSTICK_voidInit();

	MGPIO_ErrSetPinValue(UltraPort,Trigger_Pin,HIGH);
	MSYSTICK_voidSetBusyWait(15);
	MGPIO_ErrSetPinValue(UltraPort,Trigger_Pin,LOW);
}
