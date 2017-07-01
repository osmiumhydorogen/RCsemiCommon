/*
 * air_cylinder.hpp
 *
 *  Created on: 2017/05/04
 *      Author: osmium
 */

#ifndef INC_AIR_CYLINDER_HPP_
#define INC_AIR_CYLINDER_HPP_

namespace RCsemi
{
class AirCylinder
{
public:
	virtual bool drive(bool status)	= 0;
	virtual bool toggle()			= 0;
	virtual bool getStatus() 		= 0;
	virtual ~AirCylinder(){};
};
}

#endif /* INC_AIR_CYLINDER_HPP_ */
