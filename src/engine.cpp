//
// engine.cpp
//

#include "engine.h"

#include <signal.h> // signal processing
#include <stdlib.h> // exit() function


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

    // TODO wrap signal to ifdef
    signal(SIGINT, Engine::sysSignalHandler);

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


// TODO wrap signal to ifdef
void Engine::sysSignalHandler(int sigNum) {
    Logger::error("system signal recieved (SIGINT), exiting");
    Engine::instance().close();

    exit(sigNum);
    return;
}

