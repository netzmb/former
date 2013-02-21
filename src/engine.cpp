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
#include "physics.h"
#include "scripting.h"
#include "interface.h"



bool Engine::init(int argc, char **argv) {

    _isDone = false;

    //
    // init subsystems
    //
    
    initSubSystem(Input::instance().init());
    initSubSystem(Config::instance().init(argc, argv));
    initSubSystem(Logger::instance().init());
    initSubSystem(Graphics::instance().init());
    initSubSystem(Physics::instance().init());
    initSubSystem(Scripting::instance().init());
    initSubSystem(Interface::instance().init());
    initSubSystem(StateManager::instance().init());



    // TODO wrap signal to ifdef
    signal(SIGINT, Engine::sysSignalHandler);

    return true;
}


void Engine::loop() {

    while (!isDone()) {
    	Graphics::instance().frameBegin();
    	Physics::instance().frameBegin();

    	StateManager::instance().update();
    	Interface::instance().update();
    	Physics::instance().frameEnd();
    	//Interface::instance().update();
        Graphics::instance().frameEnd();
        Scripting::instance().update();
        // FIXME
        _isDone = Graphics::instance().isDone();
    }

    return;
}


void Engine::close() {
    StateManager::instance().close();
	Interface::instance().close();
    Scripting::instance().close();
    Physics::instance().close();
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



void Engine::initSubSystem(bool initSuccess) {
	if (initSuccess)
		return;

	Logger::error("Subsystem loading failed, exiting");
	Engine::instance().close();
	exit(EXIT_FAILURE);
	return;
}
