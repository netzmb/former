//
//
//


#include "splash_image.h"
#include "../interface.h"
#include "../configuration.h"
#include "../logger.h"

bool SplashImageState::init() {
	Logger::info("splash init()");;
	_startTime = Config::instance().getTime();

	//Interface::instance().clear();
	changeStatus(SSTATUS_EXECUTING);
    return true;
}

void SplashImageState::update() {
	if (Config::instance().getTime() - _startTime > _timeout) {
		close();
		return;
	}

	//Logger::info("splash time: %d", Config::instance().getTime() - _startTime);

	Interface::instance().draw2dImage(_imagePath);
    return;
}


void SplashImageState::close() {
	Logger::info("splash close()");
	changeStatus(SSTATUS_DONE);
    return;
}


