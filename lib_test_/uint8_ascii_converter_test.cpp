#include <iostream>
#include "../inc/uint8_ascii_converter.hpp"

int main()
{
	using namespace std;
	using namespace RCsemi;
	Uint8AsciiConverter& ua_conv = *Uint8AsciiConverter::getInstance();  
	char dummy1[3];
	uint8_t dummy2;
	dummy1[0] = 'A';
	dummy1[1] = 'A';
	dummy1[2] = '\0';
	cout << dummy1 << "\n";
	for(uint8_t i=0;i<24;i++)
	{
		cout << (int)i  << "," << ua_conv(i & 0xff,dummy1) << "\n";
	}
	cout << "\n";
	cout << "0x0A = " << (int)ua_conv("0A",&dummy2);
	cout << "\n";
	cout << "0xA0 = " <<(int)ua_conv("A0",&dummy2);
	cout << "\n";
	cout << "0xAF = " <<(int)ua_conv("AF",&dummy2);
	cout << "\n";
	return 0;
}
