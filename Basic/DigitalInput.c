//Onboard push button(PC13) to control onboard led(PA5)
#include<stm32f446xx.h>

int main(void) {
	RCC->AHB1ENR |= 5; // enable GPIOA & GPIOC clock
	GPIOA->MODER |= (1<<10); // set pin 5 to output mode
	//GPIOX is in input mode by default
	while(1) {
		//The user button is connected to PC13. It has a pull-up resitor
        //so PC13 stays high when the button is not pressed.
		if (GPIOC->IDR & 0x2000) /* if PC13 is high */
			GPIOA->BSRR = (1<<21); /* turn off green LED */ 
		else
			GPIOA->BSRR = (1<<5); /* turn on green LED */ }
}


