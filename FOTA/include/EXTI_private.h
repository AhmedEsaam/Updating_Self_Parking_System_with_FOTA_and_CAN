/*
 * ----------------------------------------------------------------------------------
 * Filename     :	EXTI_private.h
 *
 * Author       :	Ahmed Essam El-Mogy
 * Created on   :	MAY 22, 2023
 * Version      :	v1.0
 * C Standard   :	C99
 * Compiler     :	GNU ARM GCC
 * Controller   :   STM32F401CCU6 (32-bit Architecture)
 * Layer        :   MCAL
 * ----------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------
 * Version		Date 		        Author			        Description
 * v1.0		    MAY 22, 2023 		Ahmed Essam El-Mogy		Initial Creation
 * ----------------------------------------------------------------------------------
 */
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;

#define     MEXTI_BASE_ADDRESS          0x40013C00

#define     MEXTI                       ((volatile EXTI_t *)MEXTI_BASE_ADDRESS)

#define     SYSCFG_EXTICR1              *((volatile u32*)0x40013808)


#endif /* EXTI_PRIVATE_H */
