#include "configuration.h"

#include "evt_reciever.h"


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
        // TODO Log() errors
        return false;
    }

    return true;
}


void Config::close() {
	_irrDevice->drop();
    return;
}

