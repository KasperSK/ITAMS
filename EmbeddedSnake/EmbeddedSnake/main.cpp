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
#include "Game.h"

static PD8544 display;
static auto screen = ScreenBuffer<84, 48, PD8544>(&display);
static auto mouse = Point{3,3};
static SnakeController controller;


void move_it( int8_t horizontal, int8_t vertical) {
	if (mouse.y + vertical < 3) {
		return;
	}
	if (mouse.x + horizontal < 3) {
		return;
	}
	if (mouse.y + vertical > 42) {
		return;
	}
	if (mouse.x + horizontal > 80) {
		return;
	}
	
	Point old = mouse;
	
	mouse.y += vertical;
	mouse.x += horizontal;
	
	screen.draw_square(mouse,3,3);
	screen.update(mouse,3,3);
	
	_delay_ms(1);
	
	screen.clear_square(old, 3, 3);
	screen.update(old,3,3);
}

void move() {
	if (controller.Direction == Up) {
		move_it(0, -3);
	}
		if (controller.Direction == Down) {
			move_it(0,3);
		}
		if (controller.Direction == Left) {
			move_it(-3,0);
		}
		if (controller.Direction == Right) {
			move_it(3,0);
		}
}


	//screen.update();
	


int main(void)
{
  
	Leds::set_output();
	
	
	screen.clear();
	screen.update();	
	
	Area<28, 16> area;
	
	Game<ScreenBuffer<84, 48, PD8544>, Area<28, 16>> game(&screen, &area, &controller);

	
    while (1) 
    {
		_delay_ms(100);
		controller.update();
		*Leds::out = ~(controller.A ? 0xFF : 0x00);
		//game.GameTick(&controller);
		game.tick();
		
    }
}

