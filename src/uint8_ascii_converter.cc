/*
 * uint8_ascii_converter.cc
 *
 *  Created on: 2017/01/19
 *      Author: osmium
 */
#include "../inc/uint8_ascii_converter.hpp"
namespace RCsemi
{
	/*
	 * アスキーから4bit整数へ変換,'0'だけシフトする
	 */
	const uint8_t Uint8AsciiConverter::ascii_2_four_bit_table_[] = {0,1,2,3,4,5,6,7,8,9,0,0,0,0,0,0,0,10,11,12,13,14,15};

	/*
	 * 4bit整数からアスキーへ変換
	 */
	const char Uint8AsciiConverter::four_bit_2_ascii_table_[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	Uint8AsciiConverter* Uint8AsciiConverter::instance_ = 0;

Uint8AsciiConverter::Uint8AsciiConverter()
{
}
}
