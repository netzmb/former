//
// statemgr.cpp
//

#include "statemgr.h"

// default states
#include "states/video.h"


bool StateManager::init() {
    //
    // load default states
    //
    //_states.push_back(Video());

    State * pVideo = static_cast<State*>(new Video);
    add(pVideo);

    return false;
}


void StateManager::update() {
    for (std::list<State*>::iterator i = _states.begin();
         i != _states.end(); i++) {
        (*i)->close();
    }

    return;
}


void StateManager::close() {
    for (std::list<State*>::iterator i = _states.begin();
         i != _states.end(); i++) {
        (*i)->close();
    }
    return;
}


void StateManager::add(State *pState) {
    _states.push_back(pState);
    return;
}

