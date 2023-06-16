/*
 * ----------------------------------------------------------------------------------
 * Filename     :	IR_program.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	JUN 14, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU ARM GCC
 * Controller   :   STM32F401CCU6 (32-bit Architecture)
 * Layer        :   MCAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    JUN 14, 2023 		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"

/**
 *@brief Set pin mode to be Input
 * 			and output speed to be low
 *
 *@param Copy_pIR_tObj 
*/
void IR_voidInit(IR_t *Copy_pIR_tObj)
{
    MGPIO_ErrSetPinMode(Copy_pIR_tObj->IR_u8PORT, Copy_pIR_tObj->IR_u8PIN, GPIO_INPUT);
    MGPIO_ErrSetPinPullUpPullDown(Copy_pIR_tObj->IR_u8PORT, Copy_pIR_tObj->IR_u8PIN, GPIO_PULL_UP);    
}

/**
 *@brief Get pin value and return it via a pointer
 *
 *@param Copy_pIR_tObj 
 *@param Copy_pu8IRValue 
*/
void IR_voidGetValue(IR_t *Copy_pIR_tObj, u8 *Copy_pu8IRValue)
{
	MGPIO_ErrGetPinValue(Copy_pIR_tObj->IR_u8PORT, Copy_pIR_tObj->IR_u8PIN, &Copy_pu8IRValue);
}
