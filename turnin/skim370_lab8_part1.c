 
/*
 * lab8.c
 *
 * Created: 11/4/2019 10:58:35 AM
 * Author : skylar kim
 */ 

#include <avr/io.h>

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}
int main(void)
{
   	DDRA = 0x00; PORTA = 0xFF; 
    DDRB = 0xFF; PORTB = 0x00; 
    DDRD = 0xFF; PORTD = 0x00;
	
	ADC_init();
    while (1) 
    {
		unsigned short temp = ADC;
		unsigned char top8 = (char)temp;
		unsigned char bottom2 = (char)(temp >> 8);
		PORTB = top8;
		PORTD = bottom2;
    }
}
