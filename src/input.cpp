/*
 * input.cpp
 *
 *  Created on: 11 груд. 2012
 *      Author: moss
 */

#include "input.h"
#include "logger.h"



bool Input::init() {
	_eventReciever = new EngineEventReceiver;

    setInitialized(true);
	return true;
}

void Input::close() {
    if (!isInitialized())
        return;

	delete _eventReciever;
	return;
}


bool EngineEventReceiver::OnEvent(const irr::SEvent& event) {

	//
	// Log store processing
	//
	if (event.EventType == irr::EET_LOG_TEXT_EVENT) {
		Logger::storeLine(event.LogEvent.Text);
		// TODO log event receiver: implement suppress stdout flag
		// return true suppress output to stdout
	}

	// mouse input processing
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
		switch(event.MouseInput.Event) {
		case irr::EMIE_MOUSE_MOVED:
			Input::instance().setMouse(event.MouseInput.X, event.MouseInput.Y);
			break;
		default:
			break;
		}
	}


	return false;
}

