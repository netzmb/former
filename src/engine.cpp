//
// engine.cpp
//

#include "engine.h"

#include "config.h"
#include "logger.h"
#include "statemgr.h"
#include "graphics.h"
#include "scripting.h"


bool Engine::init() {

    _isDone = false;

    //
    // init subsystems
    //
    
    Config::instance().init();
    Logger::instance().init();
    Graphics::instance().init();
    StateManager::instance().init();
    Scripting::instance().init();

    return true;
}


void Engine::loop() {

    //while (!StateManager::instance().isDone()) {
    while (!isDone()) {
        StateManager::instance().update();
        //Graphics::instance().update();
        Graphics::instance().frameBegin();
        Graphics::instance().frameEnd();
        Scripting::instance().update();
        _isDone = Graphics::instance().isDone();
    }

    return;
}


void Engine::close() {
    Scripting::instance().close();
    StateManager::instance().close();
    Graphics::instance().close();
    Logger::instance().close();
    Config::instance().close();
    
    return;
}


