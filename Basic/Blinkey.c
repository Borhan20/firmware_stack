#include <stm32f446xx.h>

int main(){
	RCC->AHB1ENR |= 0x1; //Enable the clock for GPIO A-H which are connected to AHB1 BUS.
	GPIOA->MODER |= 1<<10; // Set GPIOA as output.
	while(1){
		GPIOA->BSRR |= 1<<5; //Enable GPIOA pin 5
		for(volatile int i=0;i<200000;i++); //Some king of delay
		GPIOA->BSRR |= 1<<21; //Disable GPIOA pin 5
		for(volatile int i=0;i<200000;i++);
	}
}

