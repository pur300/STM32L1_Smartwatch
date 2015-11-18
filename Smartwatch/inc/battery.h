#ifndef BATTERY_H
#define BATTERY_H

#include "math.h"
#include "stm32l1xx.h"

#define VDDA 3.3
#define MAX_V 3.0
#define MIN_V 2.45

// GPIO MODER register offsets and values
#define MODER2_OFFSET 0x4
#define MODER2_VALUE 0x3
// GPIO OSPEEDR register offsets and values
#define OSPEEDR2_OFFSET 0x4
#define OSPEEDR2_VALUE 0x3

// NVIC ISER0 register offsets and values
#define RS17_OFFSET ADC1_IRQn
#define RS17_VALUE 0x1
// NVIC IP register offsets and values
#define IP17_OFFSET ADC1_IRQn // Priority
#define IP17_VALUE 0x0 // Priority

// ADC1 CR1 register offsets and values
#define PDI_OFFSET 11
#define EOCIE_OFFSET 0x5
#define PDI_VALUE 0x1
#define EOCIE_VALUE 0x1
// ADC1 CR2 register offsets and values
#define ADON_OFFSET 0x0
#define ADON_VALUE 0x1
// ADC1 SMPR3 register offsets and values
#define SMP2_OFFSET 0x6
#define SMP2_VALUE 0x7
// ADC1 SQR5
#define SQ1_OFFSET 0x0
#define SQ1_VALUE 0x2
#define EOCS_OFFSET 0xA
#define EOCS_VALUE 0x1

void ADC1_IRQHandler(void);

#endif
