#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_int.h"
#include "GPIO_interface.h"
#include "SYSTICK_int.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

#include "IR_interface.h"
#include "DC_Motor_interface.h"

static void intAction(void);

Motor_t RightMotors = 
{ 
	.MotorClockwisePort = GPIO_PORTA, 
	.MotorClockwisePin = GPIO_PIN1, 
	.MotorAnticlockwisePort = GPIO_PORTA,
	.MotorAnticlockwisePin = GPIO_PIN2, 
};

Motor_t LeftMotors = 
{ 
	.MotorClockwisePort = GPIO_PORTA, 
	.MotorClockwisePin = GPIO_PIN3, 
	.MotorAnticlockwisePort = GPIO_PORTA,
	.MotorAnticlockwisePin = GPIO_PIN4, 
};

void main(void) 
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, RCC_GPIOA);

	HMotor_voidMotorInit(&RightMotors);
	HMotor_voidMotorInit(&LeftMotors);

	HMotor_voidMotorRotateAnticlockwise(&RightMotors);
	HMotor_voidMotorRotateAnticlockwise(&LeftMotors);

	//	IR
	IR_t Local_IR1Sensor = { GPIO_PORTA, GPIO_PIN0 };
	IR_voidInit(&Local_IR1Sensor);

	MNVIC_voidInit();
	MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);

	MEXTI_voidChangeSenseMode(MEXTI_LINE0, MEXTI_FALLING_EDGE);
	MEXTI_voidSetCallBack(MEXTI_LINE0, &intAction);
	MEXTI_voidEnableInterrupt(MEXTI_LINE0);

	while (1)
		;

}

static void intAction(void) {
	HMotor_voidMotorStop(&RightMotors);
	HMotor_voidMotorStop(&LeftMotors);
	while (1)
		;
}
