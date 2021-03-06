/*
* DriverSoftware.h
*
* Created: 3/10/2017 2:55:27 PM
*  Author: live
*/


#ifndef SPI_DRIVERSOFTWARE_H_
#define SPI_DRIVERSOFTWARE_H_

#include "Enums.h"

namespace SPI {
	
	
	
	template <size_t REGISTER_SIZE>
	struct BufferValueType {
		using value_type = 	typename BufferValueType<REGISTER_SIZE + 1>::value_type;
	};
	
	template <>
	struct BufferValueType<8> {
		using value_type = uint8_t;
	};
	
	template <>
	struct BufferValueType<16> {
		using value_type = uint16_t;
	};
	
	template <>
	struct BufferValueType<32> {
		using value_type = uint32_t;
	};
	
	template <>
	struct BufferValueType<64> {
		using value_type = uint64_t;
	};
	
	template <size_t REGISTER_SIZE>
	struct Buffer {

		using value_type = typename BufferValueType<REGISTER_SIZE>::value_type;
		
		static const size_t size = REGISTER_SIZE;
		
		value_type data;
		
		Buffer() {
			data = 0u;
		}
		
		inline void add_bit(uint8_t bit) {
			data = data << 1 | !!bit;
		}
		
		operator value_type&() {
			return data;
		}
	};
	
	template <typename DATA, typename LATCH, typename CLOCK>
	struct Pins {
		using latch = LATCH;
		using data  = DATA;
		using clock = CLOCK;	
	};

	template <typename BUFFER, typename PINS, typename MODE, uint8_t T_REM, uint8_t T_WH, uint8_t T_H, uint8_t T_SU>
	class DriverSoftware {
		
		public:
		using buffer_type = BUFFER;
		using latch_pin   = typename PINS::latch;
		using data_pin    = typename PINS::data;
		using clock_pin   = typename PINS::clock;
		using bit_type    = typename data_pin::value_type;
		
		// Variables
		
		static const size_t number_of_bits = BUFFER::size;  // Number of bits to be banged
		
		static const uint8_t T_rem = T_REM; // Min. Removal Time - From LATCH is lowered until CLOCK may be risen
		static const uint8_t T_wh  = T_WH;  // Min. Pulse Width  - From LATCH is raised until LATCH may be lowered
		static const uint8_t T_h   = T_H;   // Min. Hold Time    - From CLOCK is raised until DATA can be read
		static const uint8_t T_su  = T_SU;  // Min. Set-up Time  - Setup time for next DATA
		protected:
		private:
		
		template<bool B, class T = void>
		struct enable_if {};

		template<class T>
		struct enable_if<true, T> { typedef T type; };
		
		// Methods
		public:
		DriverSoftware() {
			init();
		}

		inline buffer_type read() {
			
			buffer_type buffer;
			
			// Start the transmission
			start_transmission();
			
			// Read all bits
			for (auto i = 0u; i < number_of_bits; ++i)
			{	
				// Get the next bit
				pulse(buffer);
			}
			
			// End Transmission
			end_transmission();
			
			return buffer;
		}
		
		private:
		
		inline void init() {
			// Setting LATCH pin to OUTPUT and HIGH
			latch_pin::set_output();
			latch_pin::set();
			
			// Setting CLOCK pin to OUTPUT and LOW
			clock_pin::set_output();
			space();
			
			// Setting DATA pin to INPUT
			data_pin::set_input();
			
		}
		
		template<typename Q = MODE>
		inline typename enable_if<(Q::cpha == 0), void>::type
		pulse(buffer_type& buffer) {
			buffer.add_bit(read_bit());
			mark();
			space();
		}
		
		template<typename Q = MODE>
		inline typename enable_if<(Q::cpha == 1), void>::type
		pulse(buffer_type& buffer) {
			mark();
			buffer.add_bit(read_bit());
			space();
		}
		
		template<typename Q = MODE>
		inline typename enable_if<(Q::cpol == 0), void>::type
		mark() {
			clock_pin::set();
			_delay_us(T_H / 1000);
		}
		
		template<typename Q = MODE>
		inline typename enable_if<(Q::cpol == 0), void>::type
		space() {
			clock_pin::clear();
			_delay_us(T_SU / 1000);
		}
		
		template<typename Q = MODE>
		inline typename enable_if<(Q::cpol == 1), void>::type
		mark() {
			clock_pin::clear();
			_delay_us(T_H / 1000);
		}
		
		template<typename Q = MODE>
		inline typename enable_if<(Q::cpol == 1), void>::type
		space() {
			clock_pin::set();
			_delay_us(T_SU / 1000);
		}
		
		bit_type read_bit() {
			return data_pin::read();
		}
		
		inline void start_transmission() {
			latch_pin::clear();
			_delay_us(T_rem / 1000);
		}
		
		inline void end_transmission() {
			latch_pin::set();
			_delay_us(T_WH / 1000);
		}
		
		
		
	};

}
#endif /* SPI_DRIVERSOFTWARE_H_ */