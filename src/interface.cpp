/*
 * interface.cpp
 *
 *  Created on: 11 груд. 2012
 *      Author: moss
 */

#include "interface.h"
#include "logger.h"
#include "configuration.h"
#include "input.h"


using irr::core::position2di;
using irr::core::recti;

Interface::Interface() {
	_stubPath = "textures/stub.png";
	_stubTex = NULL;
	_device = NULL;
	_driver = NULL;
	_irrGUI = NULL;
	_showMouse = true;
	return;
}

bool Interface::init() {

	_device = Config::instance().getIrrDevice();
    _driver = _device->getVideoDriver();
    _irrGUI = _device->getGUIEnvironment();

    // init generic texture bank
    _stubTex = _driver->getTexture(_stubPath);
    // TODO clear this code
    _guiTex[GUITEX_STUB] = _stubTex;

    if (_stubTex == NULL) {
    	Logger::error("Interface::init() load stub texture failed");
    	return false;
    }

    //
    // reset GUI generic textures
    //
    for (int i=0; i < GUITEX_COUNT; ++i)
    	_guiTex[i] = _stubTex;


    _guiTex[GUITEX_MOUSE_CURSOR] = loadTex("textures/gui/mouse_cursor.png");
    _guiTex[GUITEX_MINI_LOGO] = loadTex("textures/gui/logo_mini.png");

    return true;
}


void Interface::update() {
    return;
}


void Interface::clear() {
	_irrGUI->clear();
    return;
}


void Interface::close() {
    return;
}

void Interface::updateMouse() {
	if (!_showMouse)
		return;

	_driver->draw2DImage(_guiTex[GUITEX_MOUSE_CURSOR],
			Input::instance().getMousePos());

	return;
}


irr::video::ITexture* Interface::loadTex(const irr::core::stringc& texPath) {
	irr::video::ITexture* texture = _driver->getTexture(texPath);
	if (texture == NULL) {
		Logger::warning("texture load failed: %s", texPath.c_str());
		//texture = _driver->getTexture("textures/stub.png");
		texture = _stubTex;
	}

	return texture;
}




