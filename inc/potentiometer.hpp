/*
 * potentiometer.hpp
 *
 *  Created on: 2017/06/26
 *      Author: osmium
 */

#ifndef INC_POTENTIOMETER_HPP_
#define INC_POTENTIOMETER_HPP_

namespace RCsemi
{
class Potentiometer
{
public:
	virtual unsigned int getVal() = 0;
	virtual ~Potentiometer(){}
};
}







#endif /* INC_POTENTIOMETER_HPP_ */
