/*
 * terunet.hpp
 *
 *  Created on: 2017/01/10
 *      Author: osmium
 */

#ifndef INC_TERUNET_HPP_
#define INC_TERUNET_HPP_
namespace RCsemi
{
typedef struct _TerunetFrame_t
{
	uint8_t origin_id;

	uint8_t destination_id;

	uint8_t command;

	uint8_t* data;

	uint8_t length;

	uint8_t chk_sum;

	bool need_reply;
}TerunetFrame_t;

/*
 * terunetを扱うクラス
 */
class Terunet
{
public:
	/*
	 * terunetにframeを送る
	 */
	virtual int send(TerunetFrame_t& frame) = 0;

	/*
	 * trunetから自分宛てのreplyを受け取る
	 * 返り値は成功したら0,タイムアウトしたら1,その他失敗したら2
	 */
	virtual int recieve(TerunetFrame_t* reply,int timeout_ms) = 0;

	/*
	 * terunetにframeを流す.
	 * もしframe.need_reply == true かつ replyがnullでないならreplyを受け取る
	 */
	virtual int operator()(TerunetFrame_t&,TerunetFrame_t* reply = 0) = 0;
	virtual ~Terunet(){};
};
}

#endif /* INC_TERUNET_HPP_ */
