/*
 * servo_motor.hpp
 *
 *  Created on: 2017/06/18
 *      Author: osmium
 */

#ifndef SERVO_MOTOR_HPP_
#define SERVO_MOTOR_HPP_
namespace RCsemi
{
class ServoMotor
{
public:
	virtual int drive(int target_percent) = 0;
	virtual int getVal() = 0;
	virtual ~ServoMotor(){};
};
}
#endif /* SERVO_MOTOR_HPP_ */
