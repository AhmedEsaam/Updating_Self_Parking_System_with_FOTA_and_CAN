/*
 * ----------------------------------------------------------------------------------
 * Filename     :	DC_Motor_interface.h
 * Author       :	Abdelrhman Nasr Farag
 * Created on   :	june 9, 2023
 * Version      :	v1.0
 * Compiler     :	GNU ARM-GCC
 * Controller   :  	STM32F401CCU6 (32-bit Architecture)
 * Processor    :   Cortex M4 (32-bit Architecture)
 * Layer        :   HAL (ECUAL)
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    june 9, 2023	Abdelrhman Nasr Farag		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "DC_Motor_interface.h"
#include "DC_Motor_config.h"
#include "DC_Motor_private.h"



void HMotor_voidMotorInit(Motor_t* Copy_pMotor_t_Obj)
{
	MGPIO_ErrSetPinMode (Copy_pMotor_t_Obj->MotorClockwisePort , Copy_pMotor_t_Obj->MotorClockwisePin , GPIO_OUTPUT);
	MGPIO_ErrSetPinMode (Copy_pMotor_t_Obj->MotorAnticlockwisePort , Copy_pMotor_t_Obj->MotorAnticlockwisePin , GPIO_OUTPUT);

}

void HMotor_voidMotorRotateClockwise(Motor_t* Copy_pMotor_t_Obj)
{
	MGPIO_ErrSetPinValue(Copy_pMotor_t_Obj->MotorClockwisePort , Copy_pMotor_t_Obj->MotorClockwisePin , HIGH);
	MGPIO_ErrSetPinValue(Copy_pMotor_t_Obj->MotorAnticlockwisePort , Copy_pMotor_t_Obj->MotorAnticlockwisePin , LOW);
}

void HMotor_voidMotorRotateAnticlockwise(Motor_t* Copy_pMotor_t_Obj)
{
	MGPIO_ErrSetPinValue(Copy_pMotor_t_Obj->MotorClockwisePort , Copy_pMotor_t_Obj->MotorClockwisePin , LOW);
	MGPIO_ErrSetPinValue(Copy_pMotor_t_Obj->MotorAnticlockwisePort , Copy_pMotor_t_Obj->MotorAnticlockwisePin , HIGH);
}

void HMotor_voidMotorStop(Motor_t* Copy_pMotor_t_Obj)
{
	MGPIO_ErrSetPinValue(Copy_pMotor_t_Obj->MotorClockwisePort , Copy_pMotor_t_Obj->MotorClockwisePin , LOW);
	MGPIO_ErrSetPinValue(Copy_pMotor_t_Obj->MotorAnticlockwisePort , Copy_pMotor_t_Obj->MotorAnticlockwisePin , LOW);
}



// void HMotor_void
