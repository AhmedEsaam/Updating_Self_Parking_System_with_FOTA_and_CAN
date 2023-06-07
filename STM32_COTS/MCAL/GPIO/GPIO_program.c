/*
 * ----------------------------------------------------------------------------------
 * Filename     :	GPIO_program.c
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAY 5, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU ARM GCC
 * Controller   :   STM32F401CCU6 (32-bit Architecture)
 * Layer        :   MCAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAY 5, 2023 		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


GPIO_Error_t MGPIO_ErrPinConfig(GPIO_Pin_t * Copy_pGPIO_PinObj)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Checking Port Name, Pin Number, Output Type, Output Speed, Alternate Function */
    if( Copy_pGPIO_PinObj->PortName           >   GPIO_PORTC                ||
        Copy_pGPIO_PinObj->PinNum             >   GPIO_PIN15                ||
        Copy_pGPIO_PinObj->PinMode            >   GPIO_ALTERNATE_FUNCTION   ||
        Copy_pGPIO_PinObj->OutputType         >   GPIO_OUTPUT_OPEN_DRAIN    ||
        Copy_pGPIO_PinObj->OutputSpeed        >   GPIO_VERY_HIGH_SPEED      ||
        Copy_pGPIO_PinObj->PullUpPullDown     >   GPIO_PULL_DOWN            ||
        Copy_pGPIO_PinObj->ALternateFunction  >   GPIO_AF15
        )
    {
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PinInvalidConfiguration;
    }
    else
    {
        /* Check for The Port Name */
        switch (Copy_pGPIO_PinObj->PortName)
        {
        case GPIO_PORTA:
            /* Set The Mode Bits of the Specific Pin */
            (GPIOA->MODER) &= ~((MODER_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 2));
            (GPIOA->MODER) |=  ((Copy_pGPIO_PinObj->PinMode)<<(Copy_pGPIO_PinObj->PinNum * 2));

            /* Check For Pin Output Type */
            switch (Copy_pGPIO_PinObj->OutputType)
            {
            case GPIO_OUTPUT_PUSH_PULL:
                /* Set Pin Output Type To 'Push/Pull' */
                CLR_BIT(GPIOA->OTYPER, Copy_pGPIO_PinObj->PinNum);
                break;

            case GPIO_OUTPUT_OPEN_DRAIN:
                /* Set Pin Output Type To 'Open Drain' */
                SET_BIT(GPIOA->OTYPER, Copy_pGPIO_PinObj->PinNum);
                break;
            
            default:
                /* Change Error State */
                Local_u8GPIOErrorState = GPIO_PinOutputTypeInvalidConfiguration;
                break;
            }

            /* Set Pin Specific Output Speed by Changing Output Speed Bits */
            (GPIOA->OSPEEDR) &= ~((OSPEEDR_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 2));
            (GPIOA->OSPEEDR) |=  ((Copy_pGPIO_PinObj->OutputSpeed)<<(Copy_pGPIO_PinObj->PinNum * 2));

            /* Set Pin Input PullUp/PullDown Configuration */
            (GPIOA->PUPDR) &= ~((PUPDR_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 2));
            (GPIOA->PUPDR) |=  ((Copy_pGPIO_PinObj->PullUpPullDown)<<(Copy_pGPIO_PinObj->PinNum * 2));

            /* Set Alternate Function */
            /* If Pin Number is from 0 to 7, Use AFRL Register */
            if (Copy_pGPIO_PinObj->PinNum <= 7)
            {
                /* Set Pin Alternate Function Configuration */
                (GPIOA->AFRL) &= ~((AFR_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 4));
                (GPIOA->AFRL) |=  ((Copy_pGPIO_PinObj->ALternateFunction)<<(Copy_pGPIO_PinObj->PinNum * 4));
            }
            /* If Pin Number is from 8 to 15, Use AFRH Register */
            else if (Copy_pGPIO_PinObj->PinNum > 7)
            {
                /* Set Pin Alternate Function Configuration */
                (GPIOA->AFRH) &= ~((AFR_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 4));
                (GPIOA->AFRH) |=  ((Copy_pGPIO_PinObj->ALternateFunction)<<(Copy_pGPIO_PinObj->PinNum * 4));
            }
            else
            {
                /* Change Error State */
                Local_u8GPIOErrorState = GPIO_PinNumberInvalidConfiguration;
            }
            break;

        break;

        case GPIO_PORTB:
            /* Set The Mode Bits of the Specific Pin */
            (GPIOB->MODER) &= ~((MODER_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 2));
            (GPIOB->MODER) |=  ((Copy_pGPIO_PinObj->PinMode)<<(Copy_pGPIO_PinObj->PinNum * 2));

            /* Check For Pin Output Type */
            switch (Copy_pGPIO_PinObj->OutputType)
            {
            case GPIO_OUTPUT_PUSH_PULL:
                /* Set Pin Output Type To 'Push/Pull' */
                CLR_BIT(GPIOB->OTYPER, Copy_pGPIO_PinObj->PinNum);
                break;

            case GPIO_OUTPUT_OPEN_DRAIN:
                /* Set Pin Output Type To 'Open Drain' */
                SET_BIT(GPIOB->OTYPER, Copy_pGPIO_PinObj->PinNum);
                break;
            
            default:
                /* Change Error State */
                Local_u8GPIOErrorState = GPIO_PinOutputTypeInvalidConfiguration;
                break;
            }

            /* Set Pin Specific Output Speed by Changing Output Speed Bits */
            (GPIOB->OSPEEDR) &= ~((OSPEEDR_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 2));
            (GPIOB->OSPEEDR) |=  ((Copy_pGPIO_PinObj->OutputSpeed)<<(Copy_pGPIO_PinObj->PinNum * 2));

            /* Set Pin Input PullUp/PullDown Configuration */
            (GPIOB->PUPDR) &= ~((PUPDR_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 2));
            (GPIOB->PUPDR) |=  ((Copy_pGPIO_PinObj->PullUpPullDown)<<(Copy_pGPIO_PinObj->PinNum * 2));

            /* Set Alternate Function */
            /* If Pin Number is from 0 to 7, Use AFRL Register */
            if (Copy_pGPIO_PinObj->PinNum <= 7)
            {
                /* Set Pin Alternate Function Configuration */
                (GPIOB->AFRL) &= ~((AFR_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 4));
                (GPIOB->AFRL) |=  ((Copy_pGPIO_PinObj->ALternateFunction)<<(Copy_pGPIO_PinObj->PinNum * 4));
            }
            /* If Pin Number is from 8 to 15, Use AFRH Register */
            else if (Copy_pGPIO_PinObj->PinNum > 7)
            {
                /* Set Pin Alternate Function Configuration */
                (GPIOB->AFRH) &= ~((AFR_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 4));
                (GPIOB->AFRH) |=  ((Copy_pGPIO_PinObj->ALternateFunction)<<(Copy_pGPIO_PinObj->PinNum * 4));
            }
            else
            {
                /* Change Error State */
                Local_u8GPIOErrorState = GPIO_PinNumberInvalidConfiguration;
            }
            break;

        break;

        case GPIO_PORTC:
            /* Set The Mode Bits of the Specific Pin */
            (GPIOC->MODER) &= ~((MODER_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 2));
            (GPIOC->MODER) |=  ((Copy_pGPIO_PinObj->PinMode)<<(Copy_pGPIO_PinObj->PinNum * 2));

            /* Check For Pin Output Type */
            switch (Copy_pGPIO_PinObj->OutputType)
            {
            case GPIO_OUTPUT_PUSH_PULL:
                /* Set Pin Output Type To 'Push/Pull' */
                CLR_BIT(GPIOC->OTYPER, Copy_pGPIO_PinObj->PinNum);
                break;

            case GPIO_OUTPUT_OPEN_DRAIN:
                /* Set Pin Output Type To 'Open Drain' */
                SET_BIT(GPIOC->OTYPER, Copy_pGPIO_PinObj->PinNum);
                break;
            
            default:
                /* Change Error State */
                Local_u8GPIOErrorState = GPIO_PinOutputTypeInvalidConfiguration;
                break;
            }

            /* Set Pin Specific Output Speed by Changing Output Speed Bits */
            (GPIOC->OSPEEDR) &= ~((OSPEEDR_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 2));
            (GPIOC->OSPEEDR) |=  ((Copy_pGPIO_PinObj->OutputSpeed)<<(Copy_pGPIO_PinObj->PinNum * 2));

            /* Set Pin Input PullUp/PullDown Configuration */
            (GPIOC->PUPDR) &= ~((PUPDR_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 2));
            (GPIOC->PUPDR) |=  ((Copy_pGPIO_PinObj->PullUpPullDown)<<(Copy_pGPIO_PinObj->PinNum * 2));

            /* Set Alternate Function */
            /* If Pin Number is from 0 to 7, Use AFRL Register */
            if (Copy_pGPIO_PinObj->PinNum <= 7)
            {
                /* Set Pin Alternate Function Configuration */
                (GPIOC->AFRL) &= ~((AFR_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 4));
                (GPIOC->AFRL) |=  ((Copy_pGPIO_PinObj->ALternateFunction)<<(Copy_pGPIO_PinObj->PinNum * 4));
            }
            /* If Pin Number is from 8 to 15, Use AFRH Register */
            else if (Copy_pGPIO_PinObj->PinNum > 7)
            {
                /* Set Pin Alternate Function Configuration */
                (GPIOC->AFRH) &= ~((AFR_BIT_MASK)<<(Copy_pGPIO_PinObj->PinNum * 4));
                (GPIOC->AFRH) |=  ((Copy_pGPIO_PinObj->ALternateFunction)<<(Copy_pGPIO_PinObj->PinNum * 4));
            }
            else
            {
                /* Change Error State */
                Local_u8GPIOErrorState = GPIO_PinNumberInvalidConfiguration;
            }
            break;

        break;
        
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
            break;
        }
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for The Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set The Mode Bits of the Specific Pin */
        (GPIOA->MODER) &= ~((MODER_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOA->MODER) |=  ((Copy_u8PinMode)<<(Copy_u8Pin * 2));
        break;

    case GPIO_PORTB:
        /* Set The Mode Bits of the Specific Pin */
        (GPIOB->MODER) &= ~((MODER_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOB->MODER) |=  ((Copy_u8PinMode)<<(Copy_u8Pin * 2));
        break;

    case GPIO_PORTC:
        /* Set The Mode Bits of the Specific Pin */
        (GPIOC->MODER) &= ~((MODER_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOC->MODER) |=  ((Copy_u8PinMode)<<(Copy_u8Pin * 2));
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPortMode(u8 Copy_u8Port, u8 Copy_u8PortMode)
{
    /* Variable to Store Port Mode Register Value */
    u32 Local_u32PortModeValue;
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check Port Mode */
    switch (Copy_u8PortMode)
    {
    case GPIO_INPUT:
        Local_u32PortModeValue = GPIO_PORT_INPUT;
        break;

    case GPIO_OUTPUT:
        Local_u32PortModeValue = GPIO_PORT_OUTPUT;
        break;

    case GPIO_ALTERNATE_FUNCTION:
        Local_u32PortModeValue = GPIO_PORT_ALTERNATE_FUNCTION;
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortModeInvalidConfiguration;
        break;
    }

    /* Check for The Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set Port Mode */
        (GPIOA->MODER) = Local_u32PortModeValue;
        break;

    case GPIO_PORTB:
        /* Set Port Mode */
        (GPIOB->MODER) = Local_u32PortModeValue;
        break;

    case GPIO_PORTC:
        /* Set Port Mode */
        (GPIOC->MODER) = Local_u32PortModeValue;
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPortSpecificMode(u8 Copy_u8Port, u32 Copy_u32PortMode)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for The Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set Port Mode */
        (GPIOA->MODER) = Copy_u32PortMode;
        break;

    case GPIO_PORTB:
        /* Set Port Mode */
        (GPIOB->MODER) = Copy_u32PortMode;
        break;

    case GPIO_PORTC:
        /* Set Port Mode */
        (GPIOC->MODER) = Copy_u32PortMode;
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutputType)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Check For Pin Output Type */
        switch (Copy_u8PinOutputType)
        {
        case GPIO_OUTPUT_PUSH_PULL:
            /* Set Pin Output Type To 'Push/Pull' */
            CLR_BIT(GPIOA->OTYPER, Copy_u8Pin);
            break;

        case GPIO_OUTPUT_OPEN_DRAIN:
            /* Set Pin Output Type To 'Open Drain' */
            SET_BIT(GPIOA->OTYPER, Copy_u8Pin);
            break;
        
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinOutputTypeInvalidConfiguration;
            break;
        }
        break;

    case GPIO_PORTB:
        /* Check For Pin Output Type */
        switch (Copy_u8PinOutputType)
        {
        case GPIO_OUTPUT_PUSH_PULL:
            /* Set Pin Output Type To 'Push/Pull' */
            CLR_BIT(GPIOB->OTYPER, Copy_u8Pin);
            break;

        case GPIO_OUTPUT_OPEN_DRAIN:
            /* Set Pin Output Type To 'Open Drain' */
            SET_BIT(GPIOB->OTYPER, Copy_u8Pin);
            break;
        
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinOutputTypeInvalidConfiguration;
            break;
        }
        break;

    case GPIO_PORTC:
        /* Check For Pin Output Type */
        switch (Copy_u8PinOutputType)
        {
        case GPIO_OUTPUT_PUSH_PULL:
            /* Set Pin Output Type To 'Push/Pull' */
            CLR_BIT(GPIOC->OTYPER, Copy_u8Pin);
            break;

        case GPIO_OUTPUT_OPEN_DRAIN:
            /* Set Pin Output Type To 'Open Drain' */
            SET_BIT(GPIOC->OTYPER, Copy_u8Pin);
            break;
        
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinOutputTypeInvalidConfiguration;
            break;
        }
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPortOutputType(u8 Copy_u8Port, u8 Copy_u8PortOutputType)
{
    /* Variable to Store Port Output Type Register Value */
    u32 Local_u32PortOutputTypeValue;
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check Port Output Type */
    switch (Copy_u8PortOutputType)
    {
    case GPIO_OUTPUT_PUSH_PULL:
        Local_u32PortOutputTypeValue = GPIO_PORT_OUTPUT_PUSH_PULL;
        break;

    case GPIO_OUTPUT_OPEN_DRAIN:
        Local_u32PortOutputTypeValue = GPIO_OUTPUT_OPEN_DRAIN;
        break;

    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortOutputTypeInvalidConfiguration;
        break;
    }

    /* Check for The Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set Port Output Type */
        (GPIOA->OTYPER) = Local_u8GPIOErrorState;
        break;

    case GPIO_PORTB:
        /* Set Port Output Type */
        (GPIOB->OTYPER) = Local_u8GPIOErrorState;
        break;

    case GPIO_PORTC:
        /* Set Port Output Type */
        (GPIOC->OTYPER) = Local_u8GPIOErrorState;
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPortSpecificOutputType(u8 Copy_u8Port, u32 Copy_u32PortOutputType)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for The Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set Port Output Type */
        (GPIOA->OTYPER) = Copy_u32PortOutputType;
        break;

    case GPIO_PORTB:
        /* Set Port Output Type */
        (GPIOB->OTYPER) = Copy_u32PortOutputType;
        break;

    case GPIO_PORTC:
        /* Set Port Output Type */
        (GPIOC->OTYPER) = Copy_u32PortOutputType;
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPinOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutputSpeed)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set Pin Specific Output Speed by Changing Output Speed Bits */
        (GPIOA->OSPEEDR) &= ~((OSPEEDR_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOA->OSPEEDR) |=  ((Copy_u8PinOutputSpeed)<<(Copy_u8Pin * 2));
        break;

    case GPIO_PORTB:
        /* Set Pin Specific Output Speed by Changing Output Speed Bits */
        (GPIOB->OSPEEDR) &= ~((OSPEEDR_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOB->OSPEEDR) |=  ((Copy_u8PinOutputSpeed)<<(Copy_u8Pin * 2));
        break;

    case GPIO_PORTC:
        /* Set Pin Specific Output Speed by Changing Output Speed Bits */
        (GPIOC->OSPEEDR) &= ~((OSPEEDR_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOC->OSPEEDR) |=  ((Copy_u8PinOutputSpeed)<<(Copy_u8Pin * 2));
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPortOutputSpeed(u8 Copy_u8Port, u8 Copy_u8PortOutputSpeed)
{
    /* Variable to Store Port Output Speed Register Value */
    u32 Local_u32PortOutputSpeedValue;
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check Port Output Speed */
    switch (Copy_u8PortOutputSpeed)
    {
    case GPIO_LOW_SPEED:
        Local_u32PortOutputSpeedValue = GPIO_PORT_LOW_SPEED;
        break;

    case GPIO_MEDIUM_SPEED:
        Local_u32PortOutputSpeedValue = GPIO_PORT_MEDIUM_SPEED;
        break;

    case GPIO_HIGH_SPEED:
        Local_u32PortOutputSpeedValue = GPIO_PORT_HIGH_SPEED;
        break;

    case GPIO_VERY_HIGH_SPEED:
        Local_u32PortOutputSpeedValue = GPIO_PORT_VERY_HIGH_SPEED;
        break;

    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortOutputSpeedInvalidConfiguration;
        break;
    }

    /* Check for The Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set Port Output Type */
        (GPIOA->OSPEEDR) = Local_u32PortOutputSpeedValue;
        break;

    case GPIO_PORTB:
        /* Set Port Output Type */
        (GPIOB->OSPEEDR) = Local_u32PortOutputSpeedValue;
        break;

    case GPIO_PORTC:
        /* Set Port Output Type */
        (GPIOC->OSPEEDR) = Local_u32PortOutputSpeedValue;
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPortSpecificOutputSpeed(u8 Copy_u8Port, u32 Copy_u32PortOutputSpeed)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for The Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set Port Output Type */
        (GPIOA->OSPEEDR) = Copy_u32PortOutputSpeed;
        break;

    case GPIO_PORTB:
        /* Set Port Output Type */
        (GPIOB->OSPEEDR) = Copy_u32PortOutputSpeed;
        break;

    case GPIO_PORTC:
        /* Set Port Output Type */
        (GPIOC->OSPEEDR) = Copy_u32PortOutputSpeed;
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPinPullUpPullDown(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinPullUpPullDown)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set Pin Input PullUp/PullDown Configuration */
        (GPIOA->PUPDR) &= ~((PUPDR_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOA->PUPDR) |=  ((Copy_u8PinPullUpPullDown)<<(Copy_u8Pin * 2));
        break;

    case GPIO_PORTB:
        /* Set Pin Input PullUp/PullDown Configuration */
        (GPIOB->PUPDR) &= ~((PUPDR_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOB->PUPDR) |=  ((Copy_u8PinPullUpPullDown)<<(Copy_u8Pin * 2));
        break;

    case GPIO_PORTC:
        /* Set Pin Input PullUp/PullDown Configuration */
        (GPIOC->PUPDR) &= ~((PUPDR_BIT_MASK)<<(Copy_u8Pin * 2));
        (GPIOC->PUPDR) |=  ((Copy_u8PinPullUpPullDown)<<(Copy_u8Pin * 2));
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPortPullUpPullDown(u8 Copy_u8Port, u8 Copy_u8PortPullUpPullDown)
{
    /* Variable to Store Port Input PullUp/PullDown Register Value */
    u32 Local_u32PortInputPullUpPullDownValue;
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check Port Input PullUp/PullDown */
    switch (Copy_u8PortPullUpPullDown)
    {
    case GPIO_NO_PULL_UP_PULL_DOWN:
        Local_u32PortInputPullUpPullDownValue = GPIO_PORT_NO_PULL_UP_PULL_DOWN;
        break;

    case GPIO_PULL_UP:
        Local_u32PortInputPullUpPullDownValue = GPIO_PORT_PULL_UP;
        break;

    case GPIO_PULL_DOWN:
        Local_u32PortInputPullUpPullDownValue = GPIO_PORT_PULL_DOWN;
        break;

    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortInputPullUpPullDownInvalidConfiguration;
        break;
    }

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set Port Input PullUp/PullDown Configuration */
        (GPIOA->PUPDR) = Local_u32PortInputPullUpPullDownValue;
        break;

    case GPIO_PORTB:
        /* Set Port Input PullUp/PullDown Configuration */
        (GPIOB->PUPDR) = Local_u32PortInputPullUpPullDownValue;
        break;

    case GPIO_PORTC:
        /* Set Port Input PullUp/PullDown Configuration */
        (GPIOC->PUPDR) = Local_u32PortInputPullUpPullDownValue;
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPortSpecificPullUpPullDown(u8 Copy_u8Port, u32 Copy_u32PortPullUpPullDown)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for The Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set Port Input PullUp/PullDown Configuration */
        (GPIOA->PUPDR) = Copy_u32PortPullUpPullDown;
        break;

    case GPIO_PORTB:
        /* Set Port Input PullUp/PullDown Configuration */
        (GPIOB->PUPDR) = Copy_u32PortPullUpPullDown;
        break;

    case GPIO_PORTC:
        /* Set Port Input PullUp/PullDown Configuration */
        (GPIOC->PUPDR) = Copy_u32PortPullUpPullDown;
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPinAlternateFunction(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinAlternativeFunction)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* If Pin Number is from 0 to 7, Use AFRL Register */
        if (Copy_u8Pin < 8)
        {
            /* Set Pin Alternate Function Configuration */
            (GPIOA->AFRL) &= ~((AFR_BIT_MASK)<<(Copy_u8Pin * 4));
            (GPIOA->AFRL) |=  ((Copy_u8PinAlternativeFunction)<<(Copy_u8Pin * 4));
        }
        /* If Pin Number is from 8 to 15, Use AFRH Register */
        else if (Copy_u8Pin >= 8)
        {
            /* Set Pin Alternate Function Configuration */
            (GPIOA->AFRH) &= ~((AFR_BIT_MASK)<<((Copy_u8Pin - 8) * 4));
            (GPIOA->AFRH) |=  ((Copy_u8PinAlternativeFunction)<<((Copy_u8Pin - 8) * 4));
        }
        else
        {
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinNumberInvalidConfiguration;
        }
        break;

    case GPIO_PORTB:
        /* If Pin Number is from 0 to 7, Use AFRL Register */
        if (Copy_u8Pin < 8)
        {
            /* Set Pin Alternate Function Configuration */
            (GPIOB->AFRL) &= ~((AFR_BIT_MASK)<<(Copy_u8Pin * 4));
            (GPIOB->AFRL) |=  ((Copy_u8PinAlternativeFunction)<<(Copy_u8Pin * 4));
        }
        /* If Pin Number is from 8 to 15, Use AFRH Register */
        else if (Copy_u8Pin >= 8)
        {
            /* Set Pin Alternate Function Configuration */
            (GPIOB->AFRH) &= ~((AFR_BIT_MASK)<<((Copy_u8Pin - 8) * 4));
            (GPIOB->AFRH) |=  ((Copy_u8PinAlternativeFunction)<<((Copy_u8Pin - 8) * 4));
        }
        else
        {
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinNumberInvalidConfiguration;
        }
        break;

    case GPIO_PORTC:
        /* If Pin Number is from 0 to 7, Use AFRL Register */
        if (Copy_u8Pin < 8)
        {
            /* Set Pin Alternate Function Configuration */
            (GPIOC->AFRL) &= ~((AFR_BIT_MASK)<<(Copy_u8Pin * 4));
            (GPIOC->AFRL) |=  ((Copy_u8PinAlternativeFunction)<<(Copy_u8Pin * 4));
        }
        /* If Pin Number is from 8 to 15, Use AFRH Register */
        else if (Copy_u8Pin >= 8)
        {
            /* Set Pin Alternate Function Configuration */
            (GPIOC->AFRH) &= ~((AFR_BIT_MASK)<<((Copy_u8Pin - 8) * 4));
            (GPIOC->AFRH) |=  ((Copy_u8PinAlternativeFunction)<<((Copy_u8Pin - 8) * 4));
        }
        else
        {
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinNumberInvalidConfiguration;
        }
        break;

    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Check for Pin Value */
        switch (Copy_u8PinValue)
        {
        case HIGH:
            /* Change Pin Output Value To High */
            SET_BIT(GPIOA->ODR, Copy_u8Pin);
            // GPIOA->BSRR = Global_u32SetPin[Copy_u8Pin];
            break;
        case LOW:
            /* Change Pin Output Value To Low */
            CLR_BIT(GPIOA->ODR, Copy_u8Pin);
            break;
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinValueInvalidConfiguration;
            break;
        }
        break;
    
    case GPIO_PORTB:
        /* Check for Pin Value */
        switch (Copy_u8PinValue)
        {
        case HIGH:
            /* Change Pin Output Value To High */
            SET_BIT(GPIOB->ODR, Copy_u8Pin);
            break;
        case LOW:
            /* Change Pin Output Value To Low */
            CLR_BIT(GPIOB->ODR, Copy_u8Pin);
            break;
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinValueInvalidConfiguration;
            break;
        }
        break;

    case GPIO_PORTC:
        /* Check for Pin Value */
        switch (Copy_u8PinValue)
        {
        case HIGH:
            /* Change Pin Output Value To High */
            SET_BIT(GPIOC->ODR, Copy_u8Pin);
            break;
        case LOW:
            /* Change Pin Output Value To Low */
            CLR_BIT(GPIOC->ODR, Copy_u8Pin);
            break;
        default:
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_PinValueInvalidConfiguration;
            break;
        }
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrSetPortValue(u8 Copy_u8Port, u8 Copy_u8PortValue)
{
     /* Variable to Store Port Output Value Register Value */
    u32 Local_u32PortOutputValue;
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check Port Input PullUp/PullDown */
    switch (Copy_u8PortValue)
    {
    case LOW:
        Local_u32PortOutputValue = PORT_ODR_LOW;
        break;

    case HIGH:
        Local_u32PortOutputValue = PORT_ODR_HIGH;
        break;

    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortValueInvalidConfiguration;
        break;
    }

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set Port Output Value */
        (GPIOA->ODR) = Local_u32PortOutputValue;
        break;

    case GPIO_PORTB:
        /* Set Port Output Value */
        (GPIOB->ODR) = Local_u32PortOutputValue;
        break;

    case GPIO_PORTC:
        /* Set Port Output Value */
        (GPIOC->ODR) = Local_u32PortOutputValue;
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}

GPIO_Error_t MGPIO_ErrSetPortSpecificValue(u8 Copy_u8Port, u32 Copy_u32PortValue)
{
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Set Port Output Value */
        (GPIOA->ODR) = Copy_u32PortValue;
        break;

    case GPIO_PORTB:
        /* Set Port Output Value */
        (GPIOB->ODR) = Copy_u32PortValue;
        break;

    case GPIO_PORTC:
        /* Set Port Output Value */
        (GPIOC->ODR) = Copy_u32PortValue;
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* return Error State */
    return Local_u8GPIOErrorState;
}


GPIO_Error_t MGPIO_ErrGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 * Copy_pu8PinValue)
{
    /* Create Varibale To Store Pin Input Value */
    u8 Local_u8PinInputValue;    

    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;
    
    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Read Pin Value */
        Local_u8PinInputValue = GET_BIT(GPIOA->IDR, Copy_u8Pin);
        break;

    case GPIO_PORTB:
        /* Read Pin Value */
        Local_u8PinInputValue = GET_BIT(GPIOB->IDR, Copy_u8Pin);
        break;

    case GPIO_PORTC:
        /* Read Pin Value */
        Local_u8PinInputValue = GET_BIT(GPIOC->IDR, Copy_u8Pin);
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* Update PinValue Pointer Dereferenced Value */
    *Copy_pu8PinValue = Local_u8PinInputValue;

    /* return Error State */
    return Local_u8GPIOErrorState;
}

GPIO_Error_t MGPIO_ErrGetPortValue(u8 Copy_u8Port, u32 * Copy_pu32PortValue)
{
    /* Create Varibale To Store Port Input Value */
    u8 Local_u8PortInputValue;    

    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;
    
    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Read Port Value */
        Local_u8PortInputValue = GPIOA->IDR;
        break;

    case GPIO_PORTB:
        /* Read Port Value */
        Local_u8PortInputValue = GPIOB->IDR;
        break;

    case GPIO_PORTC:
        /* Read Port Value */
        Local_u8PortInputValue = GPIOC->IDR;
        break;
    
    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    }

    /* Update PinValue Pointer Dereferenced Value */
    *Copy_pu32PortValue = Local_u8PortInputValue;

    /* return Error State */
    return Local_u8GPIOErrorState;
}



GPIO_Error_t MGPIO_ErrLockPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    /* Create Variables To Help With Word-Accessing The LCKR Register */
    u32 Local_u32LockRegister;
    u32 Local_u32LockRegisterLCKK0;
    u32 Local_u32LockRegisterLCKK1;
    u32 Local_u32LCKKBitValue;
    
    /* Set Error Handling Initial State */
    GPIO_Error_t Local_u8GPIOErrorState;
    Local_u8GPIOErrorState = GPIO_OK;

    /* Check for Port Name */
    switch (Copy_u8Port)
    {
    case GPIO_PORTA:
        /* Make a Copy Of the LCKR Register */
        Local_u32LockRegister = GPIOA->LCKR;
        SET_BIT(Local_u32LockRegister, Copy_u8Pin);
        /* Make a Copy Of The Register With LCKK bit set to 0*/
        Local_u32LockRegisterLCKK0 = Local_u32LockRegister;
        CLR_BIT(Local_u32LockRegisterLCKK0, LCKR_LCKK);
        /* Make a Copy Of The Register With LCKK bit set to 1*/
        Local_u32LockRegisterLCKK1 = Local_u32LockRegister;
        SET_BIT(Local_u32LockRegisterLCKK1, LCKR_LCKK);

        /* Start The Lock Key Write Sequence */
        GPIOA->LCKR = Local_u32LockRegisterLCKK1;
        GPIOA->LCKR = Local_u32LockRegisterLCKK0;
        GPIOA->LCKR = Local_u32LockRegisterLCKK1;
        Local_u32LockRegister = GPIOA->LCKR;
        Local_u32LCKKBitValue = GET_BIT(GPIOA->LCKR, LCKR_LCKK);
        /* Check if The LCKK key bit is 1 */
        if(Local_u32LCKKBitValue == 1)
        {
            /* Do Nothing*/
        }
        else
        {
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_LockKeyBitInvalidConfiguration;
        }
        break;

    case GPIO_PORTB:
        /* Make a Copy Of the LCKR Register */
        Local_u32LockRegister = GPIOB->LCKR;
        SET_BIT(Local_u32LockRegister, Copy_u8Pin);
        /* Make a Copy Of The Register With LCKK bit set to 0*/
        Local_u32LockRegisterLCKK0 = Local_u32LockRegister;
        CLR_BIT(Local_u32LockRegisterLCKK0, LCKR_LCKK);
        /* Make a Copy Of The Register With LCKK bit set to 1*/
        Local_u32LockRegisterLCKK1 = Local_u32LockRegister;
        SET_BIT(Local_u32LockRegisterLCKK1, LCKR_LCKK);

        /* Start The Lock Key Write Sequence */
        GPIOB->LCKR = Local_u32LockRegisterLCKK1;
        GPIOB->LCKR = Local_u32LockRegisterLCKK0;
        GPIOB->LCKR = Local_u32LockRegisterLCKK1;
        Local_u32LockRegister = GPIOB->LCKR;
        Local_u32LCKKBitValue = GET_BIT(GPIOB->LCKR, LCKR_LCKK);
        /* Check if The LCKK key bit is 1 */
        if(Local_u32LCKKBitValue == 1)
        {
            /* Do Nothing*/
        }
        else
        {
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_LockKeyBitInvalidConfiguration;
        }
        break;
    
    case GPIO_PORTC:
        /* Make a Copy Of the LCKR Register */
        Local_u32LockRegister = GPIOC->LCKR;
        SET_BIT(Local_u32LockRegister, Copy_u8Pin);
        /* Make a Copy Of The Register With LCKK bit set to 0*/
        Local_u32LockRegisterLCKK0 = Local_u32LockRegister;
        CLR_BIT(Local_u32LockRegisterLCKK0, LCKR_LCKK);
        /* Make a Copy Of The Register With LCKK bit set to 1*/
        Local_u32LockRegisterLCKK1 = Local_u32LockRegister;
        SET_BIT(Local_u32LockRegisterLCKK1, LCKR_LCKK);

        /* Start The Lock Key Write Sequence */
        GPIOC->LCKR = Local_u32LockRegisterLCKK1;
        GPIOC->LCKR = Local_u32LockRegisterLCKK0;
        GPIOC->LCKR = Local_u32LockRegisterLCKK1;
        Local_u32LockRegister = GPIOC->LCKR;
        Local_u32LCKKBitValue = GET_BIT(GPIOC->LCKR, LCKR_LCKK);
        /* Check if The LCKK key bit is 1 */
        if(Local_u32LCKKBitValue == 1)
        {
            /* Do Nothing*/
        }
        else
        {
            /* Change Error State */
            Local_u8GPIOErrorState = GPIO_LockKeyBitInvalidConfiguration;
        }
        break;

    default:
        /* Change Error State */
        Local_u8GPIOErrorState = GPIO_PortNameInvalidConfiguration;
        break;
    } 

    /* return Error State */
    return Local_u8GPIOErrorState;
}