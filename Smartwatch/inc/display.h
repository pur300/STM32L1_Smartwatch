#ifndef DISPLAY_H
#define DISPLAY_H

#include "stm32l1xx.h"
#include "picture.h"

// Commands
#define CLEAR_DISPLAY 0b00100000
#define SET_PICTURE 0b10000000

// GPIO pins
#define DISPLAY_ENABLE 0x4
#define SPI_CS 0x4

// GPIO(C) MODER register offsets and values
#define DISP_MODER4C_OFFSET 0x8
#define DISP_MODER4C_VALUE 0x1
// GPIO(C) OSPEEDR register offsets and values
#define DISP_OSPEEDR4C_OFFSET 0x8
#define DISP_OSPEEDR4C_VALUE 0x2
// GPIO(A) MODER register offsets and values
#define DISP_MODER4A_OFFSET 0x8
#define DISP_MODER4A_VALUE 0x1
#define DISP_MODER5A_OFFSET 0xA
#define DISP_MODER5A_VALUE 0x2
#define DISP_MODER6A_OFFSET 0xC
#define DISP_MODER6A_VALUE 0x2
#define DISP_MODER7A_OFFSET 0xE
#define DISP_MODER7A_VALUE 0x2
// GPIO(A) OSPEEDR register offsets and values
#define DISP_OSPEEDR4A_OFFSET 0x8
#define DISP_OSPEEDR4A_VALUE 0x2
#define DISP_OSPEEDR5A_OFFSET 0xA
#define DISP_OSPEEDR5A_VALUE 0x2
#define DISP_OSPEEDR6A_OFFSET 0xC
#define DISP_OSPEEDR6A_VALUE 0x2
#define DISP_OSPEEDR7A_OFFSET 0xE
#define DISP_OSPEEDR7A_VALUE 0x2
// GPIO(A) AFR register offsets and values
#define DISP_AFRL5_OFFSET 0x14
#define DISP_AFRL5_VALUE 0x5
#define DISP_AFRL6_OFFSET 0x18
#define DISP_AFRL6_VALUE 0x2
#define DISP_AFRL7_OFFSET 0x1C
#define DISP_AFRL7_VALUE 0x5
// TIM3 CR1 register offsets and values
#define DISP_CEN_OFFSET 0x0
#define DISP_CEN_VALUE 0x1
// TIM3 PSC register value
#define DISP_PSC_VALUE 128
// TIM3 ARR register value
#define DISP_ARR_VALUE 2070
// TIM3 EGR register offsets and values
#define DISP_UG_OFFSET 0x0
#define DISP_UG_VALUE 0x1
// TIM3 CCMR1 register offsets and values
#define DISP_OC1M_OFFSET 0x4
#define DISP_OC1M_VALUE 0x3
// TIM3 CCER register offsets and values
#define DISP_CC1E_OFFSET 0x0
#define DISP_CC1E_VALUE 0x1
// TIM3 CCR1 value
#define DISP_CCR1_VALUE 2070
// SPI1 CR1 register offsets and values
#define DISP_BIDIMODE_OFFSET 0xF
#define DISP_BIDIMODE_VALUE 0x1
#define DISP_BIDIOE_OFFSET 0xE
#define DISP_BIDIOE_VALUE 0x1
#define DISP_SSI_OFFSET 0x8
#define DISP_SSI_VALUE 0x1
#define DISP_SSM_OFFSET 0x9
#define DISP_SSM_VALUE 0x1
#define DISP_SPE_OFFSET 0x6
#define DISP_SPE_VALUE 0x1
#define DISP_BR_OFFSET 0x3
#define DISP_BR_VALUE 0x4
#define DISP_MSTR_OFFSET 0x2
#define DISP_MSTR_VALUE 0x1

void display_t(void);

#endif
