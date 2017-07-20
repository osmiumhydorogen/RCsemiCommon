/*
 * angle_deg.hpp
 *
 *  Created on: 2017/07/07
 *      Author: osmium
 */

#ifndef INC_ANGLE_DEG_HPP_
#define INC_ANGLE_DEG_HPP_

namespace RCsemi
{
	//intの代用
	struct Angle_deg
	{
	private:
		int val_;
	public:
		Angle_deg(int val){val_ = val;}
		Angle_deg(){val_ = 0;}
		Angle_deg& operator=(int val){val_ = val;return *this;}
		operator int(){return val_;}
	};
}

#endif /* INC_ANGLE_DEG_HPP_ */
