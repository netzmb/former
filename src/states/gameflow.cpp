/*
 * state_gameflow.cpp
 *
 *  Created on: 12 груд. 2012
 *      Author: moss
 */

#include "gameflow.h"

#include "stagemgr.h"
#include "stuffmgr.h"

bool GameflowState::init() {
	StageManager::instance().init();

	// FIXME code for test stage
	Stage* stage = StageManager::instance().createStage("teststage");

	// load units list and other
	StuffManager::instance().init();

	// load stage geometry
	StageManager::instance().setMainStage(stage);





	changeStatus(SSTATUS_EXECUTING);
	return true;
}


void GameflowState::update() {
	StageManager::instance().update();
	return;
}


void GameflowState::close() {
	StageManager::instance().close();
	StuffManager::instance().close();
	changeStatus(SSTATUS_DONE);
	return;
}

