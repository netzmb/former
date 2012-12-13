/*
 * splash_video.cpp
 *
 *  Created on: 13 груд. 2012
 *      Author: moss
 */


#include "splash_video.h"


bool SplashVideoState::init() {
	changeStatus(SSTATUS_EXECUTING);
	return true;
}

void SplashVideoState::update() {
	// TODO stub only for testing
	close();
	return;
}


void SplashVideoState::close() {
	changeStatus(SSTATUS_DONE);
	return;
}
