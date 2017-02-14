/*
 * can_bus.hpp
 *
 *  Created on: 2017/02/14
 *      Author: osmium
 */

#ifndef INCLUDE_CAN_BUS_HPP_
#define INCLUDE_CAN_BUS_HPP_
namespace RCsemi
{

typedef struct CAN_Frame_t
{
	uint16_t id;
	uint8_t  data[8];
};

class CAN_BUS
{
private:
	CAN_BUS();
public:
	int sendFrame(CAN_Frame_t frame);
	CAN_BUS* getObject(int port_number);
};

}

#endif /* INCLUDE_CAN_BUS_HPP_ */
