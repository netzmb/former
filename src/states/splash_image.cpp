//
//
//


#include "splash_image.h"
#include "../interface.h"
#include "../configuration.h"
#include "../logger.h"
#include "../graphics.h"


SplashImageState::SplashImageState() :
	_timeout(300),
	_startTime(0) {

	_backColor = Graphics::instance().getFrameColor();
	_oldFrameColor = _backColor;

	return;
}


bool SplashImageState::init() {
	Logger::info("splash init()");;
	_startTime = Config::instance().getTime();


	//Interface::instance().clear();
	// if background color is set
	if (_backColor != Graphics::instance().getFrameColor()) {
		_oldFrameColor = Graphics::instance().getFrameColor();
		Graphics::instance().setFrameColor(_backColor);
	}


	changeStatus(SSTATUS_EXECUTING);
    return true;
}

void SplashImageState::update() {
	if (Config::instance().getTime() - _startTime > _timeout) {
		close();
		return;
	}

	//Logger::info("splash time: %d", Config::instance().getTime() - _startTime);
	Interface::instance().draw2dImage(_imagePath, Interface::ALIGN_CENTER);


    return;
}


void SplashImageState::close() {
	// restore background color
	if (_oldFrameColor != _backColor) {
		Graphics::instance().setFrameColor(_oldFrameColor);
	}


	changeStatus(SSTATUS_DONE);
	Logger::info("splash close()");
    return;
}


