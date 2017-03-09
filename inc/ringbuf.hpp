/*
 * rcsemi_ringbuf.hpp
 *
 *  Created on: 2016/10/14
 *      Author: osmium
 */
 #include <stdint.h>

#ifndef INCLUDE_RCSEMI_RINGBUF_HPP_
#define INCLUDE_RCSEMI_RINGBUF_HPP_
namespace RCsemi
{
class RingBuf
{
private:
	uint8_t* buf_;
	int      last_;
	int      ptr_;
	int      size_;
	int      remain_;
	bool is_external_buf_;
	bool accept_overwrite_;
public:
	//sizeバイトのバッファを確保
	RingBuf(int size);
	RingBuf(uint8_t* buf,int size);

	//リングバッファにdataを追加.
	//返り値:
	//  0:バッファオーバーラン 1:成功
	int PushData(uint8_t data);
	int PushData(const uint8_t* data,int nbytes);

	//リングバッファからmax_nbytes個データを取り出そうとする
	//返り値:
	// 実際にデータを取り出せた数
	int GetData(uint8_t* data,int max_nbytes = 1);

	//何バイトの空きがあるか返す
	int emptyBytes() const;

	//バッファオーバーランした時にreturnせずに古いデータを上書きするかどうか
	inline void acceptOverwrite(bool accept_overwrite);

	~RingBuf();
};
}

#endif /* INCLUDE_RCSEMI_RINGBUF_HPP_ */
