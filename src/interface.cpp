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
	_stubPath = "textures/system/stub.png";
	_stubTex = NULL;
	_device = NULL;
	_driver = NULL;
	_irrGUI = NULL;
	_showMouse = true;
	_consoleWindow = NULL;
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



    Console::instance().init(_irrGUI);
    // FIXME
    Console::instance().toggle();

    setInitialized(true);

    return true;
}


void Interface::update() {



    _irrGUI->drawAll();

    updateMouse();

	return;
}


void Interface::clear() {
	_irrGUI->clear();
    return;
}


void Interface::close() {
    if (!isInitialized())
        return;

    Console::instance().close();

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


//irr::video::ITexture* Interface::loadTex(const irr::core::stringc& texPath) {
irr::video::ITexture* Interface::loadTex(const irr::io::path& texPath) {
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


ITexture* Interface::draw2dImage(ITexture* imageTex, const vector2di& position) {

	_driver->draw2DImage(imageTex,
			position,
			getTexRect(imageTex),	// texture size rectangle
			0,		// clip rectangle
			irr::video::SColor(255,255,255,255),		// color
			true);	//use alpha-channel

	return imageTex;
}


ITexture* Interface::draw2dImage(const stringc& texPath, const vector2di& position) {
	irr::video::ITexture* imageTex = loadTex(texPath);
	draw2dImage(imageTex, position);
	return imageTex;
}


ITexture* Interface::draw2dImage(const stringc& texPath, texScreenAlign align) {
	irr::video::ITexture* imageTex = loadTex(texPath);



	irr::core::dimension2du screenSizeDim = Config::instance().getResolution();
	vector2di screenSize(screenSizeDim.Width, screenSizeDim.Height);

	vector2di texSize(imageTex->getSize().Width, imageTex->getSize().Height);

	// get center of screen
	vector2di screenCenter(screenSize.X/2,screenSize.Y/2);
	// get center of texture
	vector2di texCenter(texSize.X/2, texSize.Y/2);

	vector2di position;

	switch (align) {
	case ALIGN_CENTER:
		position.set(screenCenter.X - texCenter.X, screenCenter.Y - texCenter.Y);
		break;
	default:
		break;
	}

	draw2dImage(imageTex, position);

	return imageTex;
}



recti Interface::getTexRect(const ITexture* texture) {
	irr::core::dimension2du texSize = texture->getOriginalSize();
	return irr::core::recti(0, 0, texSize.Width, texSize.Height);
}

