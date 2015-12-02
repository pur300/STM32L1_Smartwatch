#include "battery.h"

static void battery_peripheralInit(void);
static void battery_StartADCConversion(void);
static uint8_t battery_getCapacity(short dr);
static uint8_t ADC1_flagStatus(uint16_t flag);
static void ADC1_clearFlag(uint16_t flag);

volatile uint8_t batteryCapacity;

static void battery_peripheralInit(void){
    
    // Enable GPIOA peripheral clock
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    // Enable ADC1 peripheral clock
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    /* GPIO configuration */
    
    // MODER register configuration
    GPIOA->MODER |= MODER2_VALUE << MODER2_OFFSET;
    // OSPEEDR register configuration
    GPIOA->OSPEEDR |= OSPEEDR2_VALUE << OSPEEDR2_OFFSET;

    /* NVIC configuration */

    // ISER0 register configuration
    NVIC->ISER[0] |= RS17_VALUE << RS17_OFFSET;
    NVIC->IP[IP17_OFFSET] |= IP17_VALUE;

    /* ADC1 configuration */

    // CR1 register configuration
    ADC1->CR1 |= (PDI_VALUE << PDI_OFFSET) | (EOCIE_VALUE << EOCIE_OFFSET);
    // SMPR3 register configuration
    ADC1->SMPR3 |= SMP2_VALUE << SMP2_OFFSET;
    // SQR5 register configuration
    ADC1->SQR5 |= SQ1_VALUE << SQ1_OFFSET;
    // CR2 register configuration
    ADC1->CR2 |= (EOCS_VALUE << EOCS_OFFSET) | (ADON_VALUE << ADON_OFFSET);
    // Wait until ADC is ready to convert
    while(!ADC1_flagStatus(ADC_SR_ADONS));

}

static uint8_t battery_getCapacity(short dr){

    float voltage = (float)dr / pow(2, 12) * VDDA;

    if(voltage > MAX_V)
        return 100;
    else if(voltage < MIN_V)
        return 0;
    else
        return (voltage / MAX_V) * 100;


}

static void battery_StartADCConversion(void){

    while(!ADC1_flagStatus(ADC_SR_EOC))
    // Start conversion
    ADC1->CR2 |= ADC_CR2_SWSTART;

}

static uint8_t ADC1_flagStatus(uint16_t flag){

    if(!(ADC1->SR & flag))
        return 0;
    return 1;
}

static void ADC1_clearFlag(uint16_t flag){

    ADC1->SR = ~(uint32_t)flag;

}

void ADC1_IRQHandler(void){   

    batteryCapacity = battery_getCapacity(ADC1->DR);
    ADC1_clearFlag(ADC_SR_EOC);

}
