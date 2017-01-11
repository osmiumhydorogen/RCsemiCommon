/*
 * im315xx.hpp
 *
 *  Created on: 2017/01/11
 *      Author: osmium
 */

#ifndef INC_IM315XX_HPP_
#define INC_IM315XX_HPP_

namespace RCsemi
{
class IM315xx
{
public:
	/*
	 * bytesの中身をIM315TX,TRXで送る.bytesの中身はバイナリでおｋ
	 * 返り値:
	 * 	エラーステータス
	 * 	0:成功 1:IM315RXだった 負の値はその他
	 */
	virtual int SendPacket(const uint8_t bytes[8]) = 0;

	/*
	 * IM315RX,TRXに送られてきたデータをバイナリに戻してbytesに格納する
	 * 返り値：
	 * 	エラーステータス
	 * 	0:成功 1:IM315TXだった 負の値はその他
	 */
	virtual int RecievePacket(uint8_t bytes[8]) = 0;

	virtual ~IM315xx(){};

};

/*
 * これをソースファイルで定義して実体を得られるようにする
 */
IM315xx* GetIM315xx(int port_num);
}

#endif /* INC_IM315XX_HPP_ */
