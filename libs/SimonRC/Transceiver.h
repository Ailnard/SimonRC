/*
 * Transceiver.h
 *
 *  Created on: 31.08.2017
 *      Author: maro
 */

#ifndef TRANSCEIVER_H_
#define TRANSCEIVER_H_
#include <vector>
#include "ChannelGroup.h"
#include "cc1101.h"
#include "JL.h"
class Transceiver {
	public:
    	enum transceiver_t:uint8_t {
    		C1101,
			RFM69CW,
			RFM12B
    	};

	public:
		Transceiver();
		virtual ~Transceiver();
		void begin();
		void handle();
		//void addChannel(Channel* chPtr);
		void registerChannelGroups(ChannelGroup::channelGroupVector_t );
		void transmit();
	private:
		void beginCC1101();

	private:
		CC1101 * _cc1101;
		ChannelGroup::channelGroupVector_t _channelGroupVector;
		JL * _jl;

};

#endif /* TRANSCEIVER_H_ */
