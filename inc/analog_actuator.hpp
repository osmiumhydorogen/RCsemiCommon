/*
 * analog_actuator.hpp
 *
 *  Created on: 2017/07/17
 *      Author: osmium
 */

#ifndef INC_ANALOG_ACTUATOR_HPP_
#define INC_ANALOG_ACTUATOR_HPP_

namespace RCsemi
{
/*
 * Motorとかアナログ値を受け取るアクチュエータのスーパークラス
 */
class AnalogActuator
{
public:
	//valueで駆動する.返り値は実際に駆動された値.
	virtual int drive(int value) = 0;

	//現在の値を返す
	virtual int getCurrentValue() = 0;

	virtual ~AnalogActuator() {}
};
}







#endif /* INC_ANALOG_ACTUATOR_HPP_ */
