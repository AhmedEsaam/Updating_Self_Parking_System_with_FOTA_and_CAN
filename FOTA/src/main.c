#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_int.h"
#include "GPIO_interface.h"
#include "SYSTICK_int.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "TIM_int.h"

#include "IR_interface.h"
#include "DC_Motor_interface.h"

static void intAction(void);

typedef enum {
    Idle, Scanning, Parcking,
	}states;

states local_u8State = Parcking;

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

	// ultrasonic
	u32 Distance =0;
	// 	// enable ULTRASONIC
	// HULTRASONIC_voidInit();


	MGPIO_ErrSetPinMode(GPIO_PORTA, GPIO_PIN6, GPIO_OUTPUT);
	MGPIO_ErrSetPinValue(GPIO_PORTA, GPIO_PIN6, HIGH);

	// Timer2 CHannel 3
	MRCC_voidEnablePeripheralClock(0,1); // GPIOB
	MRCC_voidEnablePeripheralClock(2,0); // Timer

	// Initialize SYSTIC
	MSYSTICK_voidInit();

	MGPIO_ErrSetPinMode(GPIO_PORTB,GPIO_PIN10,GPIO_ALTERNATE_FUNCTION);
	MGPIO_ErrSetPinAlternateFunction(GPIO_PORTB,GPIO_PIN10,MGPIO_AF1);

	MGTimer2_voidInit(CHANNEL3);
	MGTimer2_void_Prescaller(160);
	MGTimer2_void_PeriodValue(1000-1);
	MGTimer2_voidStart();

	MGTimer2_void_CompValue(CHANNEL3, 500);


	// Enable SYSTICK
	MSYSTICK_voidEnable();

	HMotor_voidMotorInit(&RightMotors);
	HMotor_voidMotorInit(&LeftMotors);

	//  move forward
	HMotor_voidMotorRotateAnticlockwise(&RightMotors);
	HMotor_voidMotorRotateAnticlockwise(&LeftMotors);
	MSYSTICK_voidSetBusyWait(2000000);

	//	IR
	IR_t Local_IR1Sensor = { GPIO_PORTA, GPIO_PIN0 };
	IR_voidInit(&Local_IR1Sensor);

	MNVIC_voidInit();
	MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);

	MEXTI_voidChangeSenseMode(MEXTI_LINE0, MEXTI_FALLING_EDGE);
	MEXTI_voidSetCallBack(MEXTI_LINE0, &intAction);
	MEXTI_voidEnableInterrupt(MEXTI_LINE0);

	while (1)
	{
		// check car mode state 
    	 switch (local_u8State)
		{
			// if case = idle -> car in stop mode  
			case Idle:
				 HMotor_voidMotorStop(&RightMotors);
				 HMotor_voidMotorStop(&LeftMotors);

			break;
			/*
			* if state is scanning 
			* start the sequance 
			* scan for sufficient  distance every 100 ms
			* after 1000 ms and the distance suitble for parking
			* go to parking mode 
			* if not 
			* start scanning again 
			*/

			// case Scanning:
			// 	 if(Distance <= 50)//
			// 	 {
			// 		// get the distance and display it on LCD 
			// 	 	HULTRASONIC_voidReadDistance(&Distance);
		    //         HLCD_voidSendNumber(Distance);
			// 	 	// _delay_ms(100);//
		    //         HLCD_voidClearDisplay();
			// 	 }
			// 	 else // distance > 50 // read the distance 10 times after find a suitble deapth  
			// 	 {
            //         u8 Local_u8Iterator = 0 ;
            //         for ( Local_u8Iterator = 0 ; Local_u8Iterator < 10 ; Local_u8Iterator ++ ) // i = 0 
            //         {
            //             HULTRASONIC_voidReadDistance(&Distance);
            //             HLCD_voidSendNumber(Distance);
            //             if (Distance < 50)
            //             {
            //                 break; 
            //             }
            //             // _delay_ms(100);
            //             HLCD_voidClearDisplay();
            //         }
                    
			// 		// if the ultrasonic find an object then reset scanning mood 
            //         if (Local_u8Iterator != 10)
            //         {
            //             local_u8State = Scanning;
            //         }
            //         else // if not then start the sequance of parking 
            //         {
            //             HMotor_voidMotorStop(&RightMotors);
            //             HMotor_voidMotorStop(&LeftMotors);
            //             _delay_ms(700);//
            //             local_u8State = Parcking;
            //         }
			// 	}

			// break;
			case Parcking:
					// move back right with suitble angle 
					for (int i=0; i <2; i++)
					{
						HMotor_voidMotorStop(&RightMotors);
						HMotor_voidMotorRotateAnticlockwise(&LeftMotors);
						MSYSTICK_voidSetBusyWait(7000000);
						// back
//						HMotor_voidMotorRotateAnticlockwise(&RightMotors);
//						HMotor_voidMotorRotateAnticlockwise(&LeftMotors);
//						MSYSTICK_voidSetBusyWait(10000);

						HMotor_voidMotorStop(&RightMotors);
						MSYSTICK_voidSetBusyWait(2000000);

					}

					// move back left with the same angle and same length 
					// for (int i=0; i <2; i++)
					// {
					// 	HMotor_voidMotorStop(&LeftMotors);
					// 	HMotor_voidMotorRotateAnticlockwise(&RightMotors);
					// 	MSYSTICK_voidSetBusyWait(70000);
					// 	// back
					// 	HMotor_voidMotorRotateAnticlockwise(&RightMotors);
					// 	HMotor_voidMotorRotateAnticlockwise(&LeftMotors);
					// 	MSYSTICK_voidSetBusyWait(10000);
					// }
					// back to idle mode 
					 local_u8State = Idle;
//				}
			break;
			default:
			break;
		}
	}

}



static void intAction(void)
{
	HMotor_voidMotorStop(&RightMotors);
	HMotor_voidMotorStop(&LeftMotors);
	while (1)
		;

	// asm("NOP"); // Do Nothing

}
