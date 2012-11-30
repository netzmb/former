//
// engine.cpp
//

#include "engine.h"

#include "statemgr.h"
#include "graphics.h"
#include "scripting.h"


bool Engine::init() {

    //
    // init subsystems
    //
    
    Graphics::instance().init();
    StateManager::instance().init();
    Scripting::instance().init();

    return true;
}


void Engine::loop() {

    while (!StateManager::instance().isDone()) {
        StateManager::instance().update();
        Graphics::instance().update();
        //Scripting::instance().update();
    }

    return;
}


void Engine::close() {
    Scripting::instance().close();
    StateManager::instance().close();
    Graphics::instance().close();
    return;
}


