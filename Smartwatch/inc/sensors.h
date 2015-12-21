#ifndef SENSORS_H
#define SENSORS_H

#include "stm32l1xx.h"


// I2C1 speed in Hz
#define I2C1_SPEED 100000

// I2C1 directions
#define I2C1_WRITE 0
#define I2C1_READ 1

// SHT21 address
#define SHT21_ADDR 0x40
// SHT21 commands
#define CMD_HUMIDITY 0b11110101
#define CMD_TEMPERATURE 0b11110011

// GPIOB MODER register offsets and values
#define SENS_MODER6_OFFSET 0xC
#define SENS_MODER6_VALUE 0x2
#define SENS_MODER7_OFFSET 0xE
#define SENS_MODER7_VALUE 0x2
// GPIOB OTYPER register offsets and values
#define SENS_OTYPER6_OFFSET 0x6
#define SENS_OTYPER6_VALUE 0x1
#define SENS_OTYPER7_OFFSET 0x7
#define SENS_OTYPER7_VALUE 0x1
// GPIOB OSPEEDR register offsets and values
#define SENS_OSPEEDR6_OFFSET 0xC
#define SENS_OSPEEDR6_VALUE 0x2
#define SENS_OSPEEDR7_OFFSET 0xE
#define SENS_OSPEEDR7_VALUE 0x2
// GPIOB PUPDR register offsets and values ... Delete when tests are finished!!!!!!
#define SENS_PUPDR6_OFFSET 0xC
#define SENS_PUPDR6_VALUE 0x1
#define SENS_PUPDR7_OFFSET 0xE
#define SENS_PUPDR7_VALUE 0x1
//GPIOB AFRL register offsets and values
#define SENS_AFRL6_OFFSET 0x18
#define SENS_AFRL6_VALUE 0x4
#define SENS_AFRL7_OFFSET 0x1C
#define SENS_AFRL7_VALUE 0x4

//I2C1 CR1 register offsets and values
#define SENS_PE_OFFSET 0x0
#define SENS_PE_VALUE 0x1
#define SENS_START_OFFSET 0x8
#define SENS_START_VALUE 0x1
#define SENS_STOP_OFFSET 0x9
#define SENS_STOP_VALUE 0x1
#define SENS_ACK_OFFSET 0xA
#define SENS_ACK_VALUE 0x1
//I2C1 CR2 register offsets and values
#define SENS_FREQ_OFFSET 0x0
#define SENS_FREQ_VALUE 0x20
//I2C1 CCR register offsets and values
#define SENS_CCR_OFFSET 0x0
#define SENS_CCR_VALUE 0xA0
//I2C1 TRISE register offsets and values
#define SENS_TRISE_OFFSET 0x0
#define SENS_TRISE_VALUE 0x21

#endif

void sensors_t(void);
