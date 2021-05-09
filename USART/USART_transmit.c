//Configure USART2 for transmitting data
#include<stm32f446xx.h>

void USART2_init (void){
	//Enable the clock to GPIOA
	RCC->AHB1ENR |=0x1;
	//Enable clock to USART2
	RCC->APB1ENR |=(1<<17);
	//Set PA2(USART TXD) & PA3(USART RXD) alternate function mode(I'm lazy enough to configure only TXD :3)
	GPIOA->MODER |= 0xA0;
	//Choose USART2 as alternate function AF7 for pin PA2 & PA3()
	GPIOA->AFR[0]|=0x700;
	GPIOA->AFR[0]|=0x7000;
	//Set the baud rate for USART2
	USART2->BRR = 0x0683; //9600 @ 16MHz
	//Configure the CR1 register for enabling transmit (TE), character size (8-bit or 9-bit) and oversampling rate, 
	USART2->CR1 |= 0x8;// Enable Tx,8 bit data, oversampling by 16
	//Configure the CR2 (Control 2) register for number of stop bit(s)
	USART2->CR2 = 0x0000;//1 stop bit
	//Configure the CR3 (Control 3) register for no hardware flow control
	USART2->CR3 = 0x0000;
	//Enable USART2 after configuration complete
	USART2->CR1|=0x2000;
}

void USART2_write (int ch) {
	while (!(USART2->SR & 0x0080)) {} // wait until Tx buffer empty
	USART2->DR = (ch & 0xFF);
}

void delayMs(int n) {
	volatile int i;
	for (; n > 0; n--)
		for (i = 0; i < 2000; i++) ; }

int main(void) {
	USART2_init();
	while(1) {
		USART2_write('h');
		USART2_write('e');
		USART2_write('l');
		USART2_write('l');
		USART2_write('o');
		USART2_write('\n');
		
		delayMs(10);
	}
	
	
}
