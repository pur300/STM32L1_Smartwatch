#ifndef BATTERY_H
#define BATTERY_H

#include "math.h"
#include "stm32l1xx.h"

#define VDDA 3.3
#define MAX_V 3.0
#define MIN_V 2.45

// GPIO MODER register offsets and values
#define BAT_MODER2_OFFSET 0x4
#define BAT_MODER2_VALUE 0x3
// GPIO OSPEEDR register offsets and values
#define BAT_OSPEEDR2_OFFSET 0x4
#define BAT_OSPEEDR2_VALUE 0x3

// NVIC ISER0 register offsets and values
#define BAT_RS17_OFFSET ADC1_IRQn
#define BAT_RS17_VALUE 0x1
// NVIC IP register offsets and values
#define BAT_IP17_OFFSET ADC1_IRQn // Priority
#define BAT_IP17_VALUE 0x0 // Priority

// ADC1 CR1 register offsets and values
#define BAT_PDI_OFFSET 11
#define BAT_EOCIE_OFFSET 0x5
#define BAT_PDI_VALUE 0x1
#define BAT_EOCIE_VALUE 0x1
// ADC1 CR2 register value
#define BAT_ADON_OFFSET 0x0
#define BAT_ADON_VALUE 0x1
#define BAT_EOCS_OFFSET 0xA
#define BAT_EOCS_VALUE 0x1
// ADC1 SMPR3 register offsets and values
#define BAT_SMP2_OFFSET 0x6
#define BAT_SMP2_VALUE 0x7
// ADC1 SQR5
#define BAT_SQ1_OFFSET 0x0
#define BAT_SQ1_VALUE 0x2


void battery_t(void);
void ADC1_IRQHandler(void);

#endif
