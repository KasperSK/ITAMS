/*
 * Point.h
 *
 * Created: 3/8/2017 8:53:25 PM
 *  Author: live
 */ 


#ifndef SCREEN_POINT_H_
#define SCREEN_POINT_H_

namespace Screen {
	struct Point {
		int16_t x;
		int16_t y;
	};
	
	struct ArrayPoint {
		uint8_t column;
		uint8_t row;
		
	};
}



#endif /* SCREEN_POINT_H_ */