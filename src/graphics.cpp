//
// graphics.cpp
//

#include "graphics.h"


bool Graphics::init() {

    //_isDone = false;
    _frameColor.set(255,0,0,255); // blue


    // TODO move device params to Config
    _device = Config::instance().getIrrDevice();

    // TODO put CMake project name and version to header
    _device->setWindowCaption(L"former");

    _driver = _device->getVideoDriver();
    _scenemgr = _device->getSceneManager();

    return true;
}


void Graphics::frameBegin() {
    _driver->beginScene(
        true,   // BackBuffer
        true,   // ZBuffer
        _frameColor // scene background color 
        );

    // TODO drawScene check

    _scenemgr->drawAll();

    return;
}


void Graphics::frameEnd() {
    _driver->endScene();

    //_isDone = !(_device->run());

    return;
}

void Graphics::update() {

    return;
}


void Graphics::close() {
    _driver->drop();
    _scenemgr->drop();
    return;
}

