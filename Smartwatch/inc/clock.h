#ifndef CLOCK_H
#define CLOCK_H

#include "stm32l1xx.h"
#include "structures.h"

// PWR CR register offsets and values
#define CLK_DBP_OFFSET 0x8
#define CLK_DBP_VALUE 0x1

// RCC CSR register offsets and values
#define CLK_RTCSEL_OFFSET 0x10
#define CLK_RTCSEL_VALUE 0x1
#define CLK_RTCRST_OFFSET 0x17
#define CLK_RTCRST_VALUE 0x1

// RTC CR register offsets and values
#define CLK_ALRAE_OFFSET 0x8
#define CLK_ALRAE_VALUE 0x1
#define CLK_ALRAIE_OFFSET 0xC
#define CLK_ALRAIE_VALUE 0x1
// RTC WPR register values
#define CLK_WPR1 0xCA
#define CLK_WPR2 0x53
// RTC ISR register offsets and values
#define CLK_INIT_OFFSET 0x7
#define CLK_INIT_VALUE 0x1
// RTC PRER register offsets and values
#define CLK_PREDIV_S_OFFSET 0x0
#define CLK_PREDIV_S_VALUE 0xFA
#define CLK_PREDIV_A_OFFSET 0x10
#define CLK_PREDIV_A_VALUE 0x80
// RTC ALRMAR register offsets and values
#define CLK_MSK2_OFFSET 0xF
#define CLK_MSK2_VALUE 0x1
#define CLK_MSK3_OFFSET 0x17
#define CLK_MSK3_VALUE 0x1
#define CLK_MSK4_OFFSET 0x1F
#define CLK_MSK4_VALUE 0x1
// RTC DR register offsets
#define CLK_YT_OFFSET 0x14
#define CLK_YU_OFFSET 0x10
#define CLK_MT_OFFSET 0xC
#define CLK_MU_OFFSET 0x8
#define CLK_DT_OFFSET 0x4
#define CLK_DU_OFFSET 0x0
// RTC TR register offsets
#define CLK_HT_OFFSET 0x14
#define CLK_HU_OFFSET 0x10
#define CLK_MNT_OFFSET 0xC
#define CLK_MNU_OFFSET 0x8
#define CLK_ST_OFFSET 0x4
#define CLK_SU_OFFSET 0x0

// EXTI IMR register offsets and values
#define CLK_IMR17_OFFSET 0x11
#define CLK_IMR17_VALUE 0x1
// EXTI RTSR register offsets and values
#define CLK_RTSR17_OFFSET 0x11
#define CLK_RTSR17_VALUE 0x1

// NVIC ISER1 register offsets and values
#define CLK_RS8_OFFSET (RTC_Alarm_IRQn % 32)
#define CLK_RS8_VALUE 0x1
// NVIC IP register offsets and values
#define CLK_IP8_OFFSET RTC_Alarm_IRQn // Priority
#define CLK_IP8_VALUE 0x3 // Priority

void clock_t(void);
void RTC_Alarm_IRQHandler(void);

#endif
