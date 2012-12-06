/*
 * evt_reciever.h
 *
 *  Created on: 6 груд. 2012
 *      Author: moss
 */

#ifndef EVT_RECIEVER_H_
#define EVT_RECIEVER_H_

#include <irrlicht.h>
#include "logger.h"

class EngineEventReceiver : public irr::IEventReceiver {
public:
	bool OnEvent(const irr::SEvent& event) {
		if (event.EventType == irr::EET_LOG_TEXT_EVENT) {
			Logger::storeLine(event.LogEvent.Text);
		}

		// TODO log event receiver: implement suppress stdout flag
		return false; // return <bool> suppress output to stdout
	}
};


#endif /* EVT_RECIEVER_H_ */
