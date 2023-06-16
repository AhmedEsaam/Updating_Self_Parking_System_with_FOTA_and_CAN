/*
 * ----------------------------------------------------------------------------------
 * Filename     :	GPIO_interface.h
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

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

// GPIO Ports
#define     GPIO_PORTA                          0 
#define     GPIO_PORTB                          1 
#define     GPIO_PORTC                          2

// GPIO Pins
#define     GPIO_PIN0                           0 
#define     GPIO_PIN1                           1 
#define     GPIO_PIN2                           2 
#define     GPIO_PIN3                           3 
#define     GPIO_PIN4                           4 
#define     GPIO_PIN5                           5 
#define     GPIO_PIN6                           6 
#define     GPIO_PIN7                           7 
#define     GPIO_PIN8                           8 
#define     GPIO_PIN9                           9 
#define     GPIO_PIN10                          10 
#define     GPIO_PIN11                          11
#define     GPIO_PIN12                          12
#define     GPIO_PIN13                          13
#define     GPIO_PIN14                          14
#define     GPIO_PIN15                          15

// GPIO Pin Mode
#define     GPIO_INPUT                          0b00
#define     GPIO_OUTPUT                         1
#define     GPIO_ALTERNATE_FUNCTION             2

// GPIO Pin Output Type
#define     GPIO_OUTPUT_PUSH_PULL               0
#define     GPIO_OUTPUT_OPEN_DRAIN              1

// GPIO Pin Output Speed
#define     GPIO_LOW_SPEED                      0b00             
#define     GPIO_MEDIUM_SPEED                   1             
#define     GPIO_HIGH_SPEED                     2             
#define     GPIO_VERY_HIGH_SPEED                3      

// GPIO Pin Pullup/Pulldown
#define     GPIO_NO_PULL_UP_PULL_DOWN           0b00             
#define     GPIO_PULL_UP                        1             
#define     GPIO_PULL_DOWN                      2     

// GPIO Pin Function Selection
#define     MGPIO_AF0                            0b0000              
#define     MGPIO_AF1                            1              
#define     MGPIO_AF2                            2              
#define     MGPIO_AF3                            3              
#define     MGPIO_AF4                            4              
#define     MGPIO_AF5                            5              
#define     MGPIO_AF6                            6              
#define     MGPIO_AF7                            7              
#define     MGPIO_AF8                            8              
#define     MGPIO_AF9                            9              
#define     MGPIO_AF10                           10             
#define     MGPIO_AF11                           11             
#define     MGPIO_AF12                           12             
#define     MGPIO_AF13                           13             
#define     MGPIO_AF14                           14             
#define     MGPIO_AF15                           15    

// GPIO Pin Values
#define     LOW                                 0
#define     HIGH                                1
#define     GPIO_OUTPUT_LOW                     0
#define     GPIO_OUTPUT_HIGH                    1


typedef struct GPIO_Pin_t
{
    u8 PortName;
    u8 PinNum;
    u8 PinMode;
    u8 OutputType;
    u8 OutputSpeed;
    u8 PullUpPullDown;
    u8 ALternateFunction;
}GPIO_Pin_t;

// Error Handling
typedef enum GPIO_Error_t
{
    GPIO_OK,
    GPIO_PinInvalidConfiguration,
    GPIO_PortNameInvalidConfiguration,
    GPIO_PinNumberInvalidConfiguration,
    GPIO_PinOutputTypeInvalidConfiguration,
    GPIO_PinValueInvalidConfiguration,
    GPIO_LockKeyBitInvalidConfiguration,
    GPIO_PortModeInvalidConfiguration,
    GPIO_PortOutputTypeInvalidConfiguration,
    GPIO_PortOutputSpeedInvalidConfiguration,
    GPIO_PortInputPullUpPullDownInvalidConfiguration,
    GPIO_PortValueInvalidConfiguration,
}GPIO_Error_t;

// Linking-Time Configuration
GPIO_Error_t MGPIO_ErrPinConfig(GPIO_Pin_t * Copy_pGPIO_PinObj);

/* Post-Build Configuration */
// Set Mode
GPIO_Error_t MGPIO_ErrSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode);
GPIO_Error_t MGPIO_ErrSetPortMode(u8 Copy_u8Port, u8 Copy_u8PortMode);
GPIO_Error_t MGPIO_ErrSetPortSpecificMode(u8 Copy_u8Port, u32 Copy_u32PortMode);
// Output Type
GPIO_Error_t MGPIO_ErrSetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutputType);
GPIO_Error_t MGPIO_ErrSetPortOutputType(u8 Copy_u8Port, u8 Copy_u8PortOutputType);
GPIO_Error_t MGPIO_ErrSetPortSpecificOutputType(u8 Copy_u8Port, u32 Copy_u32PortOutputType);
// Output Speed
GPIO_Error_t MGPIO_ErrSetPinOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinOutputSpeed);
GPIO_Error_t MGPIO_ErrSetPortOutputSpeed(u8 Copy_u8Port, u8 Copy_u8PortOutputSpeed);
GPIO_Error_t MGPIO_ErrSetPortSpecificOutputSpeed(u8 Copy_u8Port, u32 Copy_u32PortOutputSpeed);
// Pull Up / Pull Down
GPIO_Error_t MGPIO_ErrSetPinPullUpPullDown(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinPullUpPullDown);
GPIO_Error_t MGPIO_ErrSetPortPullUpPullDown(u8 Copy_u8Port, u8 Copy_u8PortPullUpPullDown);
GPIO_Error_t MGPIO_ErrSetPortSpecificPullUpPullDown(u8 Copy_u8Port, u32 Copy_u32PortPullUpPullDown);
// Alternate Function
GPIO_Error_t MGPIO_ErrSetPinAlternateFunction(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinAlternativeFunction);
GPIO_Error_t MGPIO_ErrSetPortSpecificAlternateFunctionHigh(u8 Copy_u8Port, u32 Copy_u32PortAlternateFunctionHigh);
GPIO_Error_t MGPIO_ErrSetPortSpecificAlternateFunctionLow(u8 Copy_u8Port, u32 Copy_u32PortAlternateFunctionLow);
// Set Value
GPIO_Error_t MGPIO_ErrSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue);
GPIO_Error_t MGPIO_ErrSetPortValue(u8 Copy_u8Port, u8 Copy_u8PortValue);
GPIO_Error_t MGPIO_ErrSetPortSpecificValue(u8 Copy_u8Port, u32 Copy_u32PortValue);
// Get Value
GPIO_Error_t MGPIO_ErrGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 * Copy_pu8PinValue);
GPIO_Error_t MGPIO_ErrGetPortValue(u8 Copy_u8Port, u32 * Copy_pu32PortValue);
// Lock
GPIO_Error_t MGPIO_ErrLockPin(u8 Copy_u8Port, u8 Copy_u8Pin);
GPIO_Error_t MGPIO_ErrLockPort(u8 Copy_u8Port);


#endif /* GPIO_INTERFACE_H */
