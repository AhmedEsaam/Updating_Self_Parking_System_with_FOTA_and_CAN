/*
 * ----------------------------------------------------------------------------------
 * Filename     :	GPIO_private.h
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
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

typedef struct
{
    volatile u32 MODER;
    volatile u32 OTYPER;
    volatile u32 OSPEEDR;
    volatile u32 PUPDR;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR;
    volatile u32 LCKR;
    volatile u32 AFRL;
    volatile u32 AFRH;
}GPIO_t;

#define     GPIOA_BASE_ADDRESS          0x40020000
#define     GPIOB_BASE_ADDRESS          0x40020400
#define     GPIOC_BASE_ADDRESS          0x40020800

#define     GPIOA                       ((volatile GPIO_t *)GPIOA_BASE_ADDRESS)
#define     GPIOB                       ((volatile GPIO_t *)GPIOB_BASE_ADDRESS)
#define     GPIOC                       ((volatile GPIO_t *)GPIOC_BASE_ADDRESS)

// GPIO port mode register (GPIOx_MODER) (x = A, B, and C)
#define     MODER_BIT_MASK              0b11
#define     MODER0_BIT_MASK             0xfffffffc
#define     MODER1_BIT_MASK             0xfffffff3
#define     MODER2_BIT_MASK             0xffffffcf
#define     MODER3_BIT_MASK             0xffffff3f
#define     MODER4_BIT_MASK             0xfffffcff
#define     MODER5_BIT_MASK             0xfffff3ff
#define     MODER6_BIT_MASK             0xffffcfff
#define     MODER7_BIT_MASK             0xffff3fff
#define     MODER8_BIT_MASK             0xfffcffff
#define     MODER9_BIT_MASK             0xfff3ffff
#define     MODER10_BIT_MASK            0xffcfffff
#define     MODER11_BIT_MASK            0xff3fffff
#define     MODER12_BIT_MASK            0xfcffffff
#define     MODER13_BIT_MASK            0xf3ffffff
#define     MODER14_BIT_MASK            0xcfffffff
#define     MODER15_BIT_MASK            0x3fffffff

// GPIO Port Mode
#define     GPIO_PORT_INPUT                     0x00000000
#define     GPIO_PORT_OUTPUT                    0x55555555
#define     GPIO_PORT_ALTERNATE_FUNCTION        0xaaaaaaaa

// GPIO Port Output Type
#define     GPIO_PORT_OUTPUT_PUSH_PULL          0x00000000
#define     GPIO_PORT_OUTPUT_OPEN_DRAIN         0x0000ffff

// GPIO port output speed register (GPIOx_OSPEEDR) (x = A, B, and C)
#define     OSPEEDR_BIT_MASK            0b11
#define     OSPEEDR0_BIT_MASK           0xfffffffc
#define     OSPEEDR1_BIT_MASK           0xfffffff3
#define     OSPEEDR2_BIT_MASK           0xffffffcf
#define     OSPEEDR3_BIT_MASK           0xffffff3f
#define     OSPEEDR4_BIT_MASK           0xfffffcff
#define     OSPEEDR5_BIT_MASK           0xfffff3ff
#define     OSPEEDR6_BIT_MASK           0xffffcfff
#define     OSPEEDR7_BIT_MASK           0xffff3fff
#define     OSPEEDR8_BIT_MASK           0xfffcffff
#define     OSPEEDR9_BIT_MASK           0xfff3ffff
#define     OSPEEDR10_BIT_MASK          0xffcfffff
#define     OSPEEDR11_BIT_MASK          0xff3fffff
#define     OSPEEDR12_BIT_MASK          0xfcffffff
#define     OSPEEDR13_BIT_MASK          0xf3ffffff
#define     OSPEEDR14_BIT_MASK          0xcfffffff
#define     OSPEEDR15_BIT_MASK          0x3fffffff

// GPIO Port Output Speed
#define     GPIO_PORT_LOW_SPEED                 0x00000000             
#define     GPIO_PORT_MEDIUM_SPEED              0x55555555             
#define     GPIO_PORT_HIGH_SPEED                0xaaaaaaaa    
#define     GPIO_PORT_VERY_HIGH_SPEED           0xffffffff    

// GPIO port pull-up/pull-down register (GPIOx_PUPDR) (x = A, B, and C)
#define     PUPDR_BIT_MASK              0b11
#define     PUPDR0_BIT_MASK             0xfffffffc
#define     PUPDR1_BIT_MASK             0xfffffff3
#define     PUPDR2_BIT_MASK             0xffffffcf
#define     PUPDR3_BIT_MASK             0xffffff3f
#define     PUPDR4_BIT_MASK             0xfffffcff
#define     PUPDR5_BIT_MASK             0xfffff3ff
#define     PUPDR6_BIT_MASK             0xffffcfff
#define     PUPDR7_BIT_MASK             0xffff3fff
#define     PUPDR8_BIT_MASK             0xfffcffff
#define     PUPDR9_BIT_MASK             0xfff3ffff
#define     PUPDR10_BIT_MASK            0xffcfffff
#define     PUPDR11_BIT_MASK            0xff3fffff
#define     PUPDR12_BIT_MASK            0xfcffffff
#define     PUPDR13_BIT_MASK            0xf3ffffff
#define     PUPDR14_BIT_MASK            0xcfffffff
#define     PUPDR15_BIT_MASK            0x3fffffff

// GPIO Port Pullup/Pulldown
#define     GPIO_PORT_NO_PULL_UP_PULL_DOWN      0x00000000             
#define     GPIO_PORT_PULL_UP                   0x55555555             
#define     GPIO_PORT_PULL_DOWN                 0xaaaaaaaa   

// // GPIO port configuration lock register (GPIOx_LCKR) (x = A, B, and C)
#define     LCKR_LCKK                   16

// GPIO Pin Set/Reset
// Set Pin (ex: BSRR = SET_PIN3)
#define     SET_PIN0                            0x1 
#define     SET_PIN1                            0x2
#define     SET_PIN2                            0x4
#define     SET_PIN3                            0x8
#define     SET_PIN4                            0x10
#define     SET_PIN5                            0x20
#define     SET_PIN6                            0x40
#define     SET_PIN7                            0x80
#define     SET_PIN8                            0x100
#define     SET_PIN9                            0x200
#define     SET_PIN10                           0x400
#define     SET_PIN11                           0x800
#define     SET_PIN12                           0x1000
#define     SET_PIN13                           0x2000
#define     SET_PIN14                           0x4000
#define     SET_PIN15                           0x8000
// Reset Pin
#define     RESET_PIN0                          0x10000 
#define     RESET_PIN1                          0x20000
#define     RESET_PIN2                          0x40000
#define     RESET_PIN3                          0x80000
#define     RESET_PIN4                          0x100000
#define     RESET_PIN5                          0x200000
#define     RESET_PIN6                          0x400000
#define     RESET_PIN7                          0x800000
#define     RESET_PIN8                          0x1000000
#define     RESET_PIN9                          0x2000000
#define     RESET_PIN10                         0x4000000
#define     RESET_PIN11                         0x8000000
#define     RESET_PIN12                         0x10000000
#define     RESET_PIN13                         0x20000000
#define     RESET_PIN14                         0x40000000
#define     RESET_PIN15                         0x80000000

// GPIO alternate function low register (GPIOx_AFRL) (x = A, B, and C)
#define     AFR_BIT_MASK               0b1111
#define     AFRL0_BIT_MASK             0xfffffff0
#define     AFRL1_BIT_MASK             0xffffff0f
#define     AFRL2_BIT_MASK             0xfffff0ff
#define     AFRL3_BIT_MASK             0xffff0fff
#define     AFRL4_BIT_MASK             0xfff0ffff
#define     AFRL5_BIT_MASK             0xff0fffff
#define     AFRL6_BIT_MASK             0xf0ffffff
#define     AFRL7_BIT_MASK             0x0fffffff

// GPIO alternate function high register (GPIOx_AFRH) (x = A, B, and C)
#define     AFRH8_BIT_MASK             0xfffffff0
#define     AFRH9_BIT_MASK             0xffffff0f
#define     AFRH10_BIT_MASK            0xfffff0ff
#define     AFRH11_BIT_MASK            0xffff0fff
#define     AFRH12_BIT_MASK            0xfff0ffff
#define     AFRH13_BIT_MASK            0xff0fffff
#define     AFRH14_BIT_MASK            0xf0ffffff
#define     AFRH15_BIT_MASK            0x0fffffff

// GPIO Port Values
#define     PORT_ODR_LOW               0x00000000
#define     PORT_ODR_HIGH              0x0000ffff


#endif /* GPIO_PRIVATE_H */
