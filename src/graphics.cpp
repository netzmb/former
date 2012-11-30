//
// graphics.cpp
//

#include "graphics.h"


bool Graphics::init() {
    irr::SIrrlichtCreationParameters params;
    //params.DriverType = irr::video::EDT_OPENGL;
    params.DriverType = irr::video::EDT_NULL;
    _device = irr::createDeviceEx(params);
    return true;
}


void Graphics::update() {
    return;
}


void Graphics::close() {
    return;
}

