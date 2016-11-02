/*
 * motor.hpp
 *
 *  Created on: 2016/09/27
 *      Author: osmium
 */

#ifndef INCLUDE_MOTOR_HPP_
#define INCLUDE_MOTOR_HPP_

namespace RCsemi
{
    /*$B%b!<%?!<$N%$%s%?!<%U%'!<%9(B*/
	class Motor
	{
	public:
        /*
            $B%G%e!<%F%#!<Hf(BDuty$B$G%b!<%?!<$r%I%i%$%V$9$k(B
            $BJV$jCM$O<B:]$K@_Dj$5$l$?CM(B
        */
		virtual int drive(int Duty)  = 0;

        /*
            $B%b!<%?!<$K%V%l!<%-$r$+$1$k(B.
            $BJV$jCM$,(Btrue$B$N;~$O@.8y(B.
        */
		virtual bool brake()          = 0;

        /*
            $B8=:_$N%G%e!<%F%#!<Hf$rJV$9(B
        */
		virtual int getCurrentDuty() = 0;


		virtual ~Motor()             {};
	};
}







#endif /* INCLUDE_MOTOR_HPP_ */
