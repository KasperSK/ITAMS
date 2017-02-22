/*
 * EmbeddedSnake.cpp
 *
 * Created: 16/02/2017 08:55:11
 * Author : KasperSK
 */ 

#include <avr/io.h>
#define F_CPU 3686400
#include <util/delay.h>
#include <avr/cpufunc.h>

int main(void)
{
    /* Replace with your application code */
	DDRB = 0xFF;
	PORTB = 0b00001000;
	
	_delay_ms(10);
	PORTB = 0b00000000; //Pull Reset Low
	
	SPCR = 0b01010000; // 0b010111xx could maybe work
	SPSR = 0;
	DDRC = 0xFF;
	
	_delay_ms(10);
	
	PORTB = 0b00011000; // Reset and SCE high
	
	//Function Set ext
	_delay_ms(100);	
	PORTB = 0b00001000; // SCE LOW
	SPDR = 0b00100001; // Write data
		
	while(!(SPSR & (1 << SPIF))){
		PORTC = ~PINC ^ 0x20;
	}
		
	PORTB = 0b00011000;
	
	////Set bias
	//_delay_ms(100);
	//PORTB = 0b00001000;
	//SPDR = 0b00010011;
	//
	//while(!(SPSR & (1 << SPIF))){
		//PORTC = ~PINC ^ 0x20;
	//}
	//
	//PORTB = 0b00011000;
	
	//Set Vop
	_delay_ms(100);
	PORTB = 0b00001000;
	SPDR = 0b11010000;
	
	while(!(SPSR & (1 << SPIF))){
		PORTC = ~PINC ^ 0x20;
	}
		
	PORTB = 0b00011000;
	
	//Function Set basic
	_delay_ms(100);
	PORTB = 0b00001000;
	SPDR = 0b00100000;
	
	while(!(SPSR & (1 << SPIF))){
		PORTC = ~PINC ^ 0x20;
	}
	
	PORTB = 0b00011000;
	//Normal display mode
	_delay_ms(100);
	PORTB = 0b00001000;
	SPDR = 0b00001100;
	
	while(!(SPSR & (1 << SPIF))){
		PORTC = ~PINC ^ 0x30;
	}
	

	PORTB = 0b00011000;
	

	//Display write
	_delay_ms(100);	
	
	
	for(unsigned char y = 0; y < 6; ++y){
		PORTB = 0b00001000;
		SPDR = 0b01000111 | (0b00000111 & y);
		while(!(SPSR & (1 << SPIF)));
	for(unsigned char i = 0; i < 84; ++i){
		PORTB = 0b00001100;
		SPDR = 0b00000000;	
		while(!(SPSR & (1 << SPIF)));
		}	
	}
	PORTB = 0b00011000;

	//Display write
	_delay_ms(100);
	PORTB = 0b00001100;
	SPDR = 0b00000101;
		
	while(!(SPSR & (1 << SPIF))){
	}
		
	PORTB = 0b00011000;
	
	//Display write
	_delay_ms(100);
	PORTB = 0b00001100;
	SPDR = 0b11111111;
	
	while(!(SPSR & (1 << SPIF))){
	}
		
	PORTB = 0b00011000;
	
    while (1) 
    {
		_delay_ms(10000);
		PORTC = ~PINC;
    }
}

