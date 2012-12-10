#include "configuration.h"
#include "evt_reciever.h"
#include "logger.h"


bool Config::init() {
    _irrDevice = NULL;

    reset();
    return true;
}


bool Config::reset() {
    // init Irrlicht Engine

    irr::SIrrlichtCreationParameters params;

    params.DriverType = irr::video::EDT_OPENGL;
    //params.DriverType = irr::video::EDT_NULL;
    params.EventReceiver = new EngineEventReceiver();
    _irrDevice = irr::createDeviceEx(params);
    if (_irrDevice == NULL) {
    	Logger::error("Creation graphics device failed");
        return false;
    }

    return true;
}


void Config::close() {
	_irrDevice->closeDevice();
	//_irrDevice->drop();
    return;
}

