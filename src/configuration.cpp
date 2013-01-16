#include "configuration.h"
//#include "evt_reciever.h"
// TODO independent logger
//#include "logger.h"
#include "input.h"


#include <iostream>
#include <getopt.h>

bool Config::init(int argc, char **argv) {
    _irrDevice = NULL;
    _irrTimer = NULL;

    _resolution.set(800, 600);
    _irrDevParams.DriverType = irr::video::EDT_OPENGL;

    // options parsing
    char opt;

    while ((opt = getopt(argc, argv, "-n")) != -1) {
        switch (opt) {
            case 'n':
                _irrDevParams.DriverType = irr::video::EDT_NULL;
                break;
            default:
                std::cerr << "unrecognized option: " << opt << std::endl;
        }
    }

    bool resetResult = reset();
    return resetResult;
}


bool Config::reset() {
    // init Irrlicht Engine

//    irr::SIrrlichtCreationParameters params;

    //params.DriverType = irr::video::EDT_NULL;
    //params.EventReceiver = new EngineEventReceiver();
    _irrDevParams.EventReceiver = Input::instance().getEventReciever();
    _irrDevParams.WindowSize = _resolution;

    _irrDevice = irr::createDeviceEx(_irrDevParams);
    if (_irrDevice == NULL) {
    	// FIXME
    	std::cerr << "Creation graphics device failed" << std::endl;
    	//Logger::error("Creation graphics device failed");
        return false;
    }

    // add game resources
    // not ignore case, not ignore paths
    if (!getFS()->addFileArchive("data/", false, false, irr::io::EFAT_FOLDER)){
    	// FIXME
    	std::cerr << "adding resources pack failed" << std::endl;
    	//Logger::error("adding resources pack failed");
    	return false;
    }

    // initialize engine internal timer
    _irrTimer = _irrDevice->getTimer();


    return true;
}


void Config::close() {
	_irrDevice->closeDevice();
	//_irrDevice->drop();
    return;
}

