/*
 * ----------------------------------------------------------------------------------
 * Filename     :	IR_interface.h
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

#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_


typedef struct 
{
	u8 IR_u8PORT;
	u8 IR_u8PIN;
}IR_t;

/**
 *@brief IR Initialization
 *
 *@param Copy_pIR_tObj 
*/
void IR_voidInit(IR_t *Copy_pIR_tObj);

/**
 *@brief Get pin value
 *
 *@param Copy_pIR_tObj 
 *@param Copy_pu8IRValue 
*/
void IR_voidGetValue(IR_t *Copy_pIR_tObj, u8 *Copy_pu8IRValue);

#endif
