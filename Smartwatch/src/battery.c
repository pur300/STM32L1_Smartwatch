#include "battery.h"

static void battery_peripheralInit(void);
static uint8_t battery_getCapacity(short dr);
static void ADC1_StartConversion(void);

volatile uint8_t batteryCapacity;

void battery_t(void){

    // Init battery peripherals
    battery_peripheralInit();

}

static void battery_peripheralInit(void){
    
    // Enable GPIOA peripheral clock
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    // Enable ADC1 peripheral clock
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    /* GPIO configuration */
    
    // MODER register configuration
    GPIOA->MODER |= BAT_MODER2_VALUE << BAT_MODER2_OFFSET;
    // OSPEEDR register configuration
    GPIOA->OSPEEDR |= BAT_OSPEEDR2_VALUE << BAT_OSPEEDR2_OFFSET;

    /* SCB configuration */

    // Set AIRCR register
    SCB->AIRCR |= BAT_VECTKEY_VALUE << BAT_VECTKEY_OFFSET;
    SCB->AIRCR |= BAT_PRIGROUP_VALUE << BAT_PRIGROUP_OFFSET;

    /* NVIC configuration */

    // ISER0 register configuration
    NVIC->ISER[0] |= BAT_RS18_VALUE << BAT_RS18_OFFSET;
    // IPR register configuration
    NVIC->IP[BAT_IP18_OFFSET] |= BAT_IP18_VALUE << 4;

    /* ADC1 configuration */

    // CR1 register configuration
    ADC1->CR1 |= (BAT_PDI_VALUE << BAT_PDI_OFFSET) | (BAT_EOCIE_VALUE << BAT_EOCIE_OFFSET);
    // SMPR3 register configuration
    ADC1->SMPR3 |= BAT_SMP2_VALUE << BAT_SMP2_OFFSET;
    // SQR5 register configuration
    ADC1->SQR5 |= BAT_SQ1_VALUE << BAT_SQ1_OFFSET;
    // CR2 register configuration
    ADC1->CR2 |= (BAT_EOCS_VALUE << BAT_EOCS_OFFSET) | (BAT_ADON_VALUE << BAT_ADON_OFFSET);
    // Wait until ADC is ready to convert
    while(!(ADC1->SR & ADC_SR_ADONS));

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

static void ADC1_StartConversion(void){

    while(ADC1->SR & ADC_SR_EOC);
    // Start conversion
    ADC1->CR2 |= ADC_CR2_SWSTART;

}

void ADC1_IRQHandler(void){   

    batteryCapacity = battery_getCapacity(ADC1->DR);
    ADC1->SR &= ~ADC_SR_EOC;

}
