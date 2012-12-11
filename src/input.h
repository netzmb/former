/*
 * input.h
 *
 *  Created on: 11 груд. 2012
 *      Author: moss
 */

#ifndef INPUT_H_
#define INPUT_H_

#include "singleton.h"
#include <irrlicht.h>


using irr::core::vector2di;


class EngineEventReceiver : public irr::IEventReceiver {
public:
	bool OnEvent(const irr::SEvent& event);
};


class Input : public Singleton<Input> {
public:
	bool init();
	void close();

	bool OnEvent(const irr::SEvent& event);

	const vector2di& getMousePos() {return _mousePos;}
	void setMouse(irr::s32 x, irr::s32 y) { _mousePos.set(x, y); }

	irr::IEventReceiver* getEventReciever() { return _eventReciever; }

private:
	vector2di _mousePos;
	EngineEventReceiver* _eventReciever;


};




#endif /* INPUT_H_ */
