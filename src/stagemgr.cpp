/*
 * stagemgr.cpp
 *
 *  Created on: 13 груд. 2012
 *      Author: moss
 */

#include "stagemgr.h"
#include "graphics.h"
#include "logger.h"


bool StageManager::init() {
	_irrSceneManager = NULL;
	_irrSceneManager = Graphics::instance().getSceneManager();

    setInitialized(true);

	return true;
}


void StageManager::update() {

	//_irrSceneManager->drawAll();

	if(_mainStage != NULL)
		_mainStage->getSceneManager()->drawAll();

	return;
}


void StageManager::close() {

    if (!isInitialized())
        return;

	list<Stage*>::Iterator i=_stages.begin();
	while (i != _stages.end())
	{
		delete (*i);
		i =_stages.erase(i);
	}
	Logger::info("StageManager::close()");

	return;
}


Stage* StageManager::createStage(const stringc& stageName) {
	Stage* stage = new Stage(stageName);

	_stages.push_back(stage);
	return stage;
}


Stage* StageManager::setMainStage(Stage* stage) {
	_mainStage = stage;
	_mainStage->setAsMainStage();
	return _mainStage;
}
