#include "config.h"



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
    _irrDevice = irr::createDeviceEx(params);
    if (_irrDevice == NULL) {
        // TODO Log() errors
        return false;
    }

    return true;
}


void Config::close() {
    return;
}

