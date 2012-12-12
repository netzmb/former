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

    // hide default mouse cursor
    _device->getCursorControl()->setVisible(false);


    return true;
}


void Interface::update() {

    updateMouse();

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
			Input::instance().getMousePos(),
			getTexRect(_guiTex[GUITEX_MOUSE_CURSOR]),	// texture size rectangle
			0,		// clip rectangle
			irr::video::SColor(255,255,255,255),		// color
			true);	//use alpha-channel

	return;
}


irr::video::ITexture* Interface::loadTex(const irr::core::stringc& texPath) {
	irr::video::ITexture* texture = _driver->getTexture(texPath);
	if (texture == NULL) {
		Logger::warning("texture load failed: %s", texPath.c_str());
		texture = _stubTex;
	}

	return texture;
}


void Interface::fadeOutScreen(irr::u32 timeout) {
	//_driver->draw2DImage()
	return;
}


ITexture* Interface::draw2dImage(const stringc& texPath, const vector2di& position) {
	irr::video::ITexture* imageTex = loadTex(texPath);

	_driver->draw2DImage(imageTex,
			position,
			getTexRect(imageTex),	// texture size rectangle
			0,		// clip rectangle
			irr::video::SColor(255,255,255,255),		// color
			true);	//use alpha-channel

	return imageTex;
}


recti Interface::getTexRect(const ITexture* texture) {
	irr::core::dimension2du texSize = texture->getOriginalSize();
	return irr::core::recti(0, 0, texSize.Width, texSize.Height);
}



