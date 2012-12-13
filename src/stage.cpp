/*
 * stage.cpp
 *
 *  Created on: 13 груд. 2012
 *      Author: moss
 */

#include "stage.h"
#include "stagemgr.h"
#include "logger.h"
#include "configuration.h"
#include "interface.h"


Stage::Stage(const irr::core::stringc& stageName)
	: _sceneMgr(NULL) {

	_stageName = stageName;
	_sceneMgr = StageManager::instance().getSceneManager()->createNewSceneManager();

	Logger::info("Stage begin: %s", _stageName.c_str());

	Config::instance().getIrrDevice()->setInputReceivingSceneManager(_sceneMgr);


	// FIXME testing stage

	irr::scene::ICameraSceneNode* camera = _sceneMgr->addCameraSceneNodeMaya();

	_sceneMgr->setActiveCamera(camera);

	camera->setPosition(irr::core::vector3df(10,0,10));
	camera->setTarget(_sceneMgr->addCubeSceneNode(200)->getPosition());

	irr::video::ITexture* skyDomeTex = Interface::instance().loadTex("textures/test_skydome.png");
	_sceneMgr->addSkyDomeSceneNode(skyDomeTex);
	irr::scene::ISceneNode* testNode = _sceneMgr->addCubeSceneNode(23);

	testNode->setPosition(irr::core::vector3df(0,0,0));
	testNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	testNode->setMaterialTexture(0, Interface::instance().loadTex("textures/system/cube01.png"));

	irr::scene::ISceneNodeAnimator* animator = _sceneMgr->createFlyCircleAnimator();

	testNode->addAnimator(animator);
	animator->drop();


	Logger::info("Stage initialized: %s", _stageName.c_str());
	return;
}




Stage::~Stage() {
	Config::instance().getIrrDevice()->setInputReceivingSceneManager(StageManager::instance().getSceneManager());
	_sceneMgr->drop();
	Logger::info("Stage free: %s", _stageName.c_str());
	return;
}
