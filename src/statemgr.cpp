//
// statemgr.cpp
//

#include "statemgr.h"

// default states
//#include "states/video.h"

using namespace irr;


bool StateManager::init() {
    
    _isDone = false;
    
    //
    // load default states
    //
    //_states.push_back(Video());

    //State * pVideo = static_cast<State*>(new Video);
    //add(pVideo);

    return true;
}


void StateManager::update() {
    for (core::list<State*>::Iterator i = _states.begin();
         i != _states.end(); i++) {
        (*i)->update();
    }

    return;
}


void StateManager::close() {
    for (core::list<State*>::Iterator i = _states.begin();
         i != _states.end(); i++) {
        (*i)->close();
    }
    return;
}


void StateManager::add(State *pState) {
    _states.push_back(pState);
    return;
}

