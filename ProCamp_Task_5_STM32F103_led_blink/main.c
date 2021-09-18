#include "stm32f3xx.h"                  // Device header

void delay(void);												// Delay Function
void init(void);												// Init Function

static unsigned int i;

void delay()
{
	for(i=0;i<1000000;i++);
}

void init()
{
	RCC -> AHBENR |= (1<<21);							// Configure PORT E for Clock using RCC
	GPIOE -> MODER |= 0x55550000;					// Configure PORT E pins 8-15 for output
}

int main()
{
	while(1) {
		delay();
		GPIOE -> ODR |= 0x0000FF00;					// Pins 8-15 ODR Output Data Register set to 1
		delay();
		GPIOE -> ODR &= (unsigned int) ~(0x0000FF00); // Pins 8-15 ODR Output Data Register set to 0
	}		
}
