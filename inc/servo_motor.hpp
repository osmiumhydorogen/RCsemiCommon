/*
 * servo_motor.hpp
 *
 *  Created on: 2017/06/18
 *      Author: osmium
 */

#ifndef SERVO_MOTOR_HPP_
#define SERVO_MOTOR_HPP_
#include "angle_deg.hpp"

namespace RCsemi
{
class ServoMotor
{
public:
	virtual int       drive(int target_percent)   = 0;
	virtual Angle_deg drive(Angle_deg target_deg) = 0;

	virtual int getDuty() = 0;
	virtual Angle_deg getAngle() = 0;

	virtual Angle_deg getAngleRange() = 0;
	virtual ~ServoMotor(){};
};
}
#endif /* SERVO_MOTOR_HPP_ */
