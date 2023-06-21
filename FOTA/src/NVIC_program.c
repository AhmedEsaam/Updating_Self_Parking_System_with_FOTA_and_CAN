/*
 * ----------------------------------------------------------------------------------
 * Filename     :	NVIC_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAY 21, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU ARM GCC
 * Controller   :   STM32F401CCU6 (32-bit Architecture)
 * Layer        :   MCAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAY 21, 2023 		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidInit(void)
{
    /* Set The Group And Sub Priorities Distribution */
    SCB_AIRCR |= (AIRCR_PRIVKEY << 16) | (MNVIC_GRP_SUB_DISTRIBUTION << 8);
}

void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PeripheralID / 32;
    MNVIC->ISER[Local_u8ISERIndex] = (1 << (Copy_u8PeripheralID % 32));
}

void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PeripheralID / 32;
    MNVIC->ICER[Local_u8ISERIndex] = (1 << (Copy_u8PeripheralID % 32));
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PeripheralID / 32;
    MNVIC->ISPR[Local_u8ISERIndex] = (1 << (Copy_u8PeripheralID % 32));
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PeripheralID / 32;
    MNVIC->ICPR[Local_u8ISERIndex] = (1 << (Copy_u8PeripheralID % 32));  
}

void MNVIC_voidGetActiveFlag(u8 Copy_u8PeripheralID, u8 *Copy_u8ActiveFlag)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PeripheralID / 32;
    *Copy_u8ActiveFlag = GET_BIT(MNVIC->IAPR[Local_u8ISERIndex], (Copy_u8PeripheralID % 32));
}

void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority)
{
    MNVIC->IPR[Copy_u8PeripheralID] = (Copy_u8Priority << 4);
}
