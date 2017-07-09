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
template <typename DataType = uint8_t>
class RingBuf
{
private:
	DataType* buf_;
	int       last_;
	int       ptr_;
	int       size_;
	int       remain_;
	bool is_external_buf_;
	bool accept_overwrite_;
public:
	//sizeバイトのバッファを確保
	RingBuf(int size);
	RingBuf(DataType* buf,int size);

	//リングバッファにdataを追加.
	//返り値:
	//  0:バッファオーバーラン 1:成功
	int PushData(const DataType& data);
	int PushData(const DataType* data,const int nbytes);

	//リングバッファからmax_nbytes個データを取り出そうとする
	//返り値:
	// 実際にデータを取り出せた数
	int GetData(DataType* data,int max_num_data = 1);

	//DataType何個分の空きがあるか返す
	int empty() const;

	//何バイトの空きがあるか返す
	int emptyBytes() const;

	//バッファオーバーランした時にreturnせずに古いデータを上書きするかどうか
	inline void acceptOverwrite(bool accept_overwrite);

	~RingBuf();
};

template <typename DataType>
RingBuf<DataType>::RingBuf(int size)
{
	size_ = size;
	buf_ = new DataType[size];
	ptr_ = 0;
	remain_ = 0;
	last_ = size-1;
	is_external_buf_ = false;
	accept_overwrite_ = false;
}

template <typename DataType>
RingBuf<DataType>::RingBuf(DataType* buf,int size)
{
	buf_    = buf;
	size_   = size;
	last_   = size-1;
	ptr_    = 0;
	remain_ = 0;
	is_external_buf_ = true;
	accept_overwrite_ = false;
}

template <typename DataType>
int RingBuf<DataType>::PushData(const DataType& data)
{
	int target_ptr = 0;
    static bool first_push = true;
	if((last_+1) < size_)
	{
		target_ptr = last_+1;
	}
	else
	{
		last_ = 0;
		target_ptr  = 0;
	}

	//オーバーラン検出
	//if(!first_push && target_ptr == ptr_)
	if(remain_ && target_ptr == ptr_)
	{
		if(!accept_overwrite_)
			return 0;
		else
			++ptr_;
	}
	else
	{
		++remain_;
		buf_[target_ptr] = data;
	}

    first_push = false;

    last_ = target_ptr;
	return 1;
}

template <typename DataType>
int RingBuf<DataType>::PushData(const DataType* data,int nbytes)
{
	for(int i=0;i<nbytes;i++)
	{
		if(!PushData(data[i]))return 0;
	}
	return 1;
}

template <typename DataType>
int RingBuf<DataType>::GetData(DataType* data,int max_nbytes)
{
	int ptr = ptr_,num_of_data = 0;
	for(num_of_data = 0;(num_of_data < max_nbytes) && remain_;remain_--)
	{
		data[num_of_data++] = buf_[ptr++];
		if(ptr >= size_)
			ptr = 0;
	}
	ptr_ = ptr;
	return num_of_data;
}

template <typename DataType>
int RingBuf<DataType>::empty() const
{
	return size_ - remain_;
}

template <typename DataType>
int RingBuf<DataType>::emptyBytes() const
{
	return empty() * sizeof(DataType);
}

template <typename DataType>
void RingBuf<DataType>::acceptOverwrite(bool accept_overwrite)
{
	accept_overwrite_ = accept_overwrite;
}

template <typename DataType>
RingBuf<DataType>::~RingBuf()
{
	if(!is_external_buf_)
		delete[] buf_;
}

}

#endif /* INCLUDE_RCSEMI_RINGBUF_HPP_ */
