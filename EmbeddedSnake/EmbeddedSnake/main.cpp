/*
 * EmbeddedSnake.cpp
 *
 * Created: 16/02/2017 08:55:11
 * Author : KasperSK
 */ 

#include <avr/io.h>
#include "timing.h"
#include "SPIDriver.h"
#include "PD8544.h"
#include "snakeio.h"
#include "screenbuffer.h"


int main(void)
{
    ///* Replace with your application code */
	//DDRB = 0xFF;
	//PORTB = 0b00001000;
	//
	//_delay_ms(10);
	//PORTB = 0b00000000; //Pull Reset Low
	//
	//SPCR = 0b01010000; // 0b010111xx could maybe work
	//SPSR = 0;
	SnakeController controller;
	Leds::set_output();
	//
	//_delay_ms(10);
	//
	//PORTB = 0b00011000; // Reset and SCE high
	//
	////Function Set ext
	//_delay_ms(100);
	//PORTB = 0b00001000; // SCE LOW
	//SPDR = 0b00100001; // Write data
	//
	//while(!(SPSR & (1 << SPIF))){
		//PORTC = ~PINC ^ 0x20;
	//}
		//
	//PORTB = 0b00011000;
	//
	//////Set bias
	////_delay_ms(100);
	////PORTB = 0b00001000;
	////SPDR = 0b00010011;
	////
	////while(!(SPSR & (1 << SPIF))){
		////PORTC = ~PINC ^ 0x20;
	////}
	////
	////PORTB = 0b00011000;
	//
	////Set Vop
	//_delay_ms(100);
	//PORTB = 0b00001000;
	//SPDR = 0b11010000;
	//
	//while(!(SPSR & (1 << SPIF))){
		//PORTC = ~PINC ^ 0x20;
	//}
		//
	//PORTB = 0b00011000;
	//
	////Function Set basic
	//_delay_ms(100);
	//PORTB = 0b00001000;
	//SPDR = 0b00100000;
	//
	//while(!(SPSR & (1 << SPIF))){
		//PORTC = ~PINC ^ 0x20;
	//}
	//
	//PORTB = 0b00011000;
	////Normal display mode
	//_delay_ms(100);
	//PORTB = 0b00001000;
	//SPDR = 0b00001100;
	//
	//while(!(SPSR & (1 << SPIF))){
		//PORTC = ~PINC ^ 0x30;
	//}
	//
//
	//PORTB = 0b00011000;
	//
//
	////Display write
	//_delay_ms(100);	
	//
	//
	//for(unsigned char y = 0; y < 6; ++y){
		//PORTB = 0b00001000;
		//SPDR = 0b01000111 | (0b00000111 & y);
		//while(!(SPSR & (1 << SPIF)));
	//for(unsigned char i = 0; i < 84; ++i){
		//PORTB = 0b00001100;
		//SPDR = 0b00000000;	
		//while(!(SPSR & (1 << SPIF)));
		//}	
	//}
	//PORTB = 0b00011000;
//
	////Display write
	//_delay_ms(100);
	//PORTB = 0b00001100;
	//SPDR = 0b00000101;
		//
	//while(!(SPSR & (1 << SPIF))){
	//}
		//
	//PORTB = 0b00011000;
	//
	////Display write
	//_delay_ms(100);
	//PORTB = 0b00001100;
	//SPDR = 0b11111111;
	//
	//while(!(SPSR & (1 << SPIF))){
	//}
		//
	//PORTB = 0b00011000;
	
    //SPIDriver<SPIDataOrder::LSB_FIRST, SPIMode::SETUP_FALLING_SAMPLE_RISING, SPIPrescale::SCK_FREQ_PRESCALE_4> spi;
	
	const uint8_t frame[498]  = {
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
		0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,				
	};
	
	
    PD8544 display;
	auto screen = ScreenBuffer<84, 48, PD8544>(&display);
	
	
	uint8_t* ptr = &screen.buffer[0];
	display.SetYAddress(0);
	display.SetXAddress(0);
	for(uint8_t t = 0; t < 6; ++t){
		for(uint8_t i = 0; i < 84; ++i)
		{
			*ptr = 0x00;
			display.Write(*ptr);
			++ptr;
		}
	}
	
	
	
	//for (auto i = 0; i < 498; ++i) {
	//	screen.buffer[i] = frame[i];
	//}

	
	
	//display.Write(0xFF);
	
	//screen.draw_square(Point{0,0}, 10, 10);
		
		
/*
	for (auto i = 0; i < 256; ++i) {
		screen.buffer[i] = i;
	}
	
	ptr = &screen.buffer[0];
	display.SetYAddress(0);
	display.SetXAddress(0);
	for(uint8_t t = 0; t < 6; ++t){
		for(uint8_t i = 0; i < 84; ++i)
		{
			display.Write(*ptr);
			++ptr;
		}
	}
	
	*/
	
/*	display.SetYAddress(0);
	display.SetXAddress(0);
	for(uint16_t t = 0; t < 84*6; ++t){
		display.Write(screen.buffer[t]);
	}	
*/
	
	screen.update();
	
	for (auto i = 0; i < 26; ++i) {
		screen.draw_square(Point{i,0}, 1, i);	
	}
	
	screen.draw_square(Point{74,0}, 10, 10);
	//screen.draw_square(Point{74,38}, 10, 10);
	//screen.draw_square(Point{0,38}, 10, 10);
	screen.update();
	
    while (1) 
    {
		//buttons = controller.read();
		controller.update();
		*Leds::out = ~(controller.A ? 0xFF : 0x00);
		//_delay_ms(0.1);
		//_delay_ms(1000);
		//PORTC = ~PINC;
        //_delay_ms(500);
		//spi.Write(0b10000001);
    }
}

