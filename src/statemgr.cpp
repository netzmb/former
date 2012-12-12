//
// statemgr.cpp
//

#include "statemgr.h"
#include "parser.h"
#include "logger.h"


// default states
//#include "states/video.h"
#include "states/splash_image.h"
#include "states/splash_video.h"
//#include "states/gameflow.h"

using namespace irr;


bool StateManager::init() {
    
    _isDone = false;
    
    //
    // load existing states list
    //

    Parser::parseStates(this);

    _currentState = _states.front();

    return true;
}


void StateManager::update() {

	switch (_currentState->getStatus()) {
	case State::SSTATUS_EXECUTING:
		_currentState->update();
		break;
	case State::SSTATUS_DONE:
		delete _currentState;
		_states.pop();
		_currentState = _states.front();
		break;
	default:
		break;
	}




	/*
	for (core::list<State*>::Iterator i = _states.begin(); i != _states.end(); ++i) {

    	switch ((*i)->getStatus()) {
    	case State::SSTATUS_EXECUTING:
    		(*i)->update();
    		break;
    	case State::SSTATUS_DONE:
    		//delete *i;
    		//i = _states.erase(i);
    		break;
    	default:
    		break;
    	}
    }*/

    return;
}


void StateManager::close() {
	while (_states.size() > 0) {
		_states.front()->close();
		delete _states.front();
		_states.pop();
	}
    /*for (core::list<State*>::Iterator i = _states.begin();
         i != _states.end(); i++) {
        (*i)->close();
        delete (*i);
    }*/
    return;
}


State* StateManager::addState(StateType stateType) {
	State* newState;
	switch (stateType) {
	case STATE_TYPE_SPLASH_IMAGE:
		newState = new SplashImageState;
		break;
	default:
		Logger::warning("StateManager: unsupported state %d", stateType);
		break;
	}
    //_states.push_back(newState);
	_states.push(newState);
    return newState;
}

