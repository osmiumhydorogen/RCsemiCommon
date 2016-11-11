/*
 * rotary_encoder.hpp
 *
 *  Created on: 2016/11/02
 *      Author: osmium
 */

#ifndef INCLUDE_ROTARY_ENCODER_HPP_
#define INCLUDE_ROTARY_ENCODER_HPP_

namespace RCsemi
{

/*ロータリーエンコーダインターフェース*/
class RotaryEncoder
{
protected:
	signed int count_;
public:
	/*カウントをクリアする*/
	virtual void clearCount() = 0;

	/*現在のカウント(count_)を返す*/
	inline signed int get_count()
	{
		return count_;
	}

	virtual ~RotaryEncoder() = 0;
};

}

#endif /* INCLUDE_ROTARY_ENCODER_HPP_ */
