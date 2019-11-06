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
		unsigned long max = 780;
		unsigned short temp = ADC;
		unsigned short x = max;
		if(temp < (max/8)){
			PORTB = 0x00;
		}
		max = x;
		if(temp >= (max/8)){
			PORTB = 0x01;
		}
		max = x;
		if(temp >= (max/7)){
			PORTB = 0x03;
		}
		max = x;
		if(temp >= (max/6)){
			PORTB = 0x07;
		}
		max = x;
		if(temp >= (max/5)){
			PORTB = 0x0F;
		}
		max = x;
		if(temp >= (max/4)){
			PORTB = 0x1F;
		}
		max = x;
		if(temp >= (max/3)){
			PORTB = 0x3F;
		}
		max = x;
		if(temp >= (max/2)){
			PORTB = 0x7F;
		}
		max = x;
		if(temp >= max){
			PORTB = 0xFF;
		}
		//unsigned char top8 = (char)temp;
		//unsigned char bottom2 = (char)(temp >> 8);
		//PORTB = top8;
		//PORTD = bottom2;
    }
}
