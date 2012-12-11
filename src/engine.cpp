//
// engine.cpp
//

#include "engine.h"

#include <signal.h> // signal processing
#include <stdlib.h> // exit() function


#include "input.h"
#include "configuration.h"
#include "logger.h"
#include "statemgr.h"
#include "graphics.h"
#include "scripting.h"
#include "interface.h"



bool Engine::init() {

    _isDone = false;

    //
    // init subsystems
    //
    
    initService(Input::instance().init());
    initService(Config::instance().init());
    initService(Logger::instance().init());
    initService(Graphics::instance().init());
    initService(StateManager::instance().init());
    initService(Scripting::instance().init());
    initService(Interface::instance().init());



    // TODO wrap signal to ifdef
    signal(SIGINT, Engine::sysSignalHandler);

    return true;
}


void Engine::loop() {

    while (!isDone()) {
        StateManager::instance().update();
        Graphics::instance().frameBegin();
        Interface::instance().update();
        Graphics::instance().frameEnd();
        Scripting::instance().update();
        // FIXME
        _isDone = Graphics::instance().isDone();
    }

    return;
}


void Engine::close() {
	Interface::instance().close();
    Scripting::instance().close();
    StateManager::instance().close();
    Graphics::instance().close();
    Logger::instance().close();
    Config::instance().close();
    Input::instance().close();
    
    return;
}


// TODO wrap signal to ifdef
void Engine::sysSignalHandler(int sigNum) {
    Logger::error("system signal recieved (SIGINT), exiting");
    Engine::instance().close();

    exit(sigNum);
    return;
}



void Engine::initService(bool initSuccess) {
	if (initSuccess)
		return;

	Logger::error("Singleton loading failed, exiting");
	Engine::instance().close();
	exit(EXIT_FAILURE);
	return;
}
