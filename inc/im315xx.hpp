/*
 * im315xx.hpp
 *
 *  Created on: 2017/01/11
 *      Author: osmium
 */

#ifndef INC_IM315XX_HPP_
#define INC_IM315XX_HPP_
#include <stdint.h>
namespace RCsemi
{
typedef union IM315xxPacket_t_
{
	uint8_t byte[12];
	struct
	{
	uint8_t node;
	uint16_t id ;
	uint8_t rssi;
	uint8_t data[8];
	} __attribute__ ((packed)) by_name;
}IM315xxPacket_t;

class IM315xx_device
{
public:
	/*
	 * packetの中身をIM315TX,TRXで送る.
	 * 返り値:
	 * 	エラーステータス
	 * 	0:成功 1:IM315RXだった 負の値はその他
	 */
	virtual int sendPacket(const IM315xxPacket_t& packet) = 0;

	/*
	 * IM315RX,TRXに送られてきたデータをバイナリに戻してbytesに格納する
	 * 返り値：
	 * 	エラーステータス
	 * 	0:成功 1:IM315TXだった 2:タイムアウト 3:データがおかしい 負の値はその他
	 */
	virtual int recievePacket(IM315xxPacket_t* packet) = 0;

	virtual ~IM315xx_device(){};

};

/*
 * これをソースファイルで定義して実体を得られるようにする
 */
IM315xx_device* GetIM315xx(int port_num);
}

#endif /* INC_IM315XX_HPP_ */
