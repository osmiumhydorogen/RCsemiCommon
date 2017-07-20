/*
 * potentiometer.hpp
 *
 *  Created on: 2017/06/26
 *      Author: osmium
 */

#ifndef INC_POTENTIOMETER_HPP_
#define INC_POTENTIOMETER_HPP_
#include <analog_sensor.hpp>

namespace RCsemi
{
class Potentiometer : public AnalogSensor
{
public:
	virtual int nturn();
	virtual int max_val();
	virtual int min_val();
	virtual int value() = 0;
	virtual ~Potentiometer(){}
};
}







#endif /* INC_POTENTIOMETER_HPP_ */
