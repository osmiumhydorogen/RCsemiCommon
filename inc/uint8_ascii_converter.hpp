/*
 * uchar_ascii_converter.hpp
 *
 *  Created on: 2017/01/19
 *      Author: osmium
 */

#ifndef UINT8_ASCII_CONVERTER_HPP_
#define UINT8_ASCII_CONVERTER_HPP_
#include <stdint.h>

namespace RCsemi
{
class Uint8AsciiConverter
{
private:
	static const uint8_t ascii_2_four_bit_table_[];
	static const char    four_bit_2_ascii_table_[];
	Uint8AsciiConverter();
	static Uint8AsciiConverter* instance_;
public:
	inline char* operator()(const uint8_t byte,char output[2])
	{
		output[0] = four_bit_2_ascii_table_[(int)(byte >> 4)];
		output[1] = four_bit_2_ascii_table_[(int)(byte & 0xf)];
		return output;
	}

	inline uint8_t operator()(const char ascii[2], uint8_t* output)
	{
		*output  = ascii_2_four_bit_table_[(int)(ascii[0] - '0')] << 4;
		*output |= ascii_2_four_bit_table_[(int)(ascii[1] - '0')] & 0xf;
		return *output;
	}

	static Uint8AsciiConverter* getInstance()
	{
		if(!instance_) instance_ = new Uint8AsciiConverter;
		return instance_;
	}
};

}

#endif /* UINT8_ASCII_CONVERTER_HPP_ */
