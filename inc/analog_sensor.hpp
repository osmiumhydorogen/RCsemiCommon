/*
 * analog_sensor.hpp
 *
 *  Created on: 2017/07/17
 *      Author: osmium
 */

#ifndef INC_ANALOG_SENSOR_HPP_
#define INC_ANALOG_SENSOR_HPP_


namespace RCsemi
{
class AnalogSensor
{
	//値を返す
	virtual int value() = 0;

	~AnalogSensor(){}
};
}






#endif /* INC_ANALOG_SENSOR_HPP_ */
