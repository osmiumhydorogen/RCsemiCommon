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
public:
	//値を返す
	virtual int value() = 0;

	virtual ~AnalogSensor(){}
};
}






#endif /* INC_ANALOG_SENSOR_HPP_ */
