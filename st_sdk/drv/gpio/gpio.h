
#ifndef __GPIO_H
#define __GPIO_H

#define RCC_BASE_ADDRESS 0x40021000
#define GPIOB_BASE_ADDRESS  0x48000400
#define GPIOA_BASE_ADDRESS  0x48000000
#define GPIOC_BASE_ADDRESS  0x48000800
#define GPIOD_BASE_ADDRESS 0X48000C00
#define GPIOE_BASE_ADDRESS 0x48001000
#define GPIOF_BASE_ADDRESS 0x48001400
#define GPIOG_BASE_ADDRESS 0x48001800
#define GPIOH_BASE_ADDRESS 0x48001C00
#define GPIOI_BASE_ADDRESS 0x48002400

#define RCC_AHB2ENR_OFFSET 0x4c
#define GPIOx_MODER_OFFSET 0x00
#define GPIO_BSRR_OFFSET 0x18
#define GPIO_IDR_OFFSET 0x10
#define GPIO_OTYPER_OFFSET 0x04
#define GPIO_SPEEDR_OFFSET 0x08
#define GPIO_PUPDR_OFFSET 0x0c

#define RCC_AHB1ENR (*((volatile uint32_t*) (RCC_BASE_ADDRESS + RCC_AHB2ENR_OFFSET)))
#define GPIOB_MODER (*((volatile uint32_t*) (GPIOB_BASE_ADDRESS + GPIOx_MODER_OFFSET)))
#define GPIOA_MODER (*((volatile uint32_t*) (GPIOA_BASE_ADDRESS + GPIOx_MODER_OFFSET)))
#define GPIOC_MODER (*((volatile uint32_t*) (GPIOC_BASE_ADDRESS + GPIOx_MODER_OFFSET)))
#define GPIOD_MODER (*((volatile uint32_t*) (GPIOD_BASE_ADDRESS + GPIOx_MODER_OFFSET)))
#define GPIOE_MODER (*((volatile uint32_t*) (GPIOE_BASE_ADDRESS + GPIOx_MODER_OFFSET)))
#define GPIOF_MODER (*((volatile uint32_t*) (GPIOF_BASE_ADDRESS + GPIOx_MODER_OFFSET)))
#define GPIOG_MODER (*((volatile uint32_t*) (GPIOG_BASE_ADDRESS + GPIOx_MODER_OFFSET)))
#define GPIOH_MODER (*((volatile uint32_t*) (GPIOH_BASE_ADDRESS + GPIOx_MODER_OFFSET)))
#define GPIOI_MODER (*((volatile uint32_t*) (GPIOI_BASE_ADDRESS + GPIOx_MODER_OFFSET)))

#define GPIOA_BSRR  (*((volatile uint32_t*) (GPIOA_BASE_ADDRESS + GPIO_BSRR_OFFSET)))
#define GPIOB_BSRR  (*((volatile uint32_t*) (GPIOB_BASE_ADDRESS + GPIO_BSRR_OFFSET)))
#define GPIOC_BSRR  (*((volatile uint32_t*) (GPIOC_BASE_ADDRESS + GPIO_BSRR_OFFSET)))
#define GPIOD_BSRR  (*((volatile uint32_t*) (GPIOD_BASE_ADDRESS + GPIO_BSRR_OFFSET)))
#define GPIOE_BSRR  (*((volatile uint32_t*) (GPIOE_BASE_ADDRESS + GPIO_BSRR_OFFSET)))
#define GPIOF_BSRR  (*((volatile uint32_t*) (GPIOF_BASE_ADDRESS + GPIO_BSRR_OFFSET)))
#define GPIOG_BSRR  (*((volatile uint32_t*) (GPIOG_BASE_ADDRESS + GPIO_BSRR_OFFSET)))
#define GPIOH_BSRR  (*((volatile uint32_t*) (GPIOH_BASE_ADDRESS + GPIO_BSRR_OFFSET)))
#define GPIOI_BSRR  (*((volatile uint32_t*) (GPIOI_BASE_ADDRESS + GPIO_BSRR_OFFSET)))
#define GPIOF_IDR (*((volatile uint32_t*)(GPIOF_BASE_ADDRESS + GPIO_IDR_OFFSET)))

#define GPIOF_OTYPER (*((volatile uint32_t*)(GPIOF_BASE_ADDRESS +  GPIO_OTYPER_OFFSET)))
#define GPIO_SPEEDR  (*((volatile uint32_t*)(GPIOF_BASE_ADDRESS + GPIO_SPEEDR_OFFSET )))
#define GPIO_PUPDR  (*((volatile uint32_t*)(GPIOF_BASE_ADDRESS + GPIO_PUPDR_OFFSET)))

#endif