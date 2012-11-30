//
// engine.cpp
//

#include "engine.h"

#include "statemgr.h"
#include "graphics.h"


bool Engine::init() {

    //
    // init subsystems
    //
    
    Graphics::instance().init();
    StateManager::instance().init();

    return true;
}


void Engine::loop() {

    while (!StateManager::instance().isDone()) {
        StateManager::instance().update();
        Graphics::instance().update();
    }

    return;
}


void Engine::close() {
    StateManager::instance().close();
    Graphics::instance().close();
    return;
}


