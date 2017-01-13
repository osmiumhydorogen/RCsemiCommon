/*
 * ps2_controler.hpp
 *
 *  Created on: 2017/01/12
 *      Author: osmium
 */

#ifndef INC_PS2_CONTROLER_HPP_
#define INC_PS2_CONTROLER_HPP_

struct AnalogStickVal
{
public:
	signed int x;
	signed int y;
	unsigned int GetMaxValue()
	{
		return _max_value;
	}

	AnalogStickVal()
	{
		_max_value = 4;
		x=0;
		y=0;
	}

	AnalogStickVal(unsigned int max_value)
	{
		_max_value = max_value;
		x=0;
		y=0;
	}

private:
	unsigned int _max_value;
};

class PS2Controler
{
public:
	virtual bool UpButton();
	virtual bool DownButton();
	virtual bool RightButton();
	virtual bool LeftButton();
	virtual bool CircleButton();
	virtual bool RectangleButton();
	virtual bool TriangleButton();
	virtual bool StartButton();
	virtual bool SelectButton();
	virtual AnalogStickVal LeftStick();
	virtual AnalogStickVal RightStick();

	virtual ~PS2Controler();
};

#endif /* INC_PS2_CONTROLER_HPP_ */
