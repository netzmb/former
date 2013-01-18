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
#include "serializer.h"


Stage::Stage(const irr::core::stringc& stageName)
	: _sceneMgr(NULL), _fileSystem(NULL) {

	_stageName = stageName;
	_sceneMgr = StageManager::instance().getSceneManager()->createNewSceneManager();
	_fileSystem = Config::instance().getFS();

	irr::io::path stageDir("stages/");
	_stagePath = path(stageDir + stageName + "/");

	Logger::info("Stage begin: %s", _stageName.c_str());


	irr::scene::ICameraSceneNode* camera = _sceneMgr->addCameraSceneNodeMaya();
	_sceneMgr->setActiveCamera(camera);
	camera->setPosition(irr::core::vector3df(10,10,10));

	irr::video::ITexture* skyDomeTex = Interface::instance().loadTex("textures/test_skydome.png");
	_sceneMgr->addSkyDomeSceneNode(skyDomeTex);
	//ISceneNode* testNode = _sceneMgr->addCubeSceneNode(2);


	ITerrainSceneNode* terrain = _sceneMgr->addTerrainSceneNode(_stagePath + "terrain-hmap.png");

	terrain->setMaterialTexture(0, Interface::instance().loadTex("textures/grass.jpg"));


	terrain->setPosition(irr::core::vector3df());
	terrain->setScale(irr::core::vector3df(5,5,5));

	_sceneMgr->setAmbientLight(irr::video::SColorf(0.9,0.9,0.2));


	camera->setTarget(terrain->getPosition());




	// FIXME dirty hack, fix paths to irrmesh in .irr scene by custom serializer
	//SceneSerializer _serializer(_sceneMgr, _stagePath);
	//_sceneMgr->loadScene(_stagePath + path("/Scene.irr"), &_serializer);


	// FIXME testing stage
	/*

	irr::scene::ICameraSceneNode* camera = _sceneMgr->addCameraSceneNodeMaya();
	_sceneMgr->setActiveCamera(camera);
	camera->setPosition(irr::core::vector3df(10,10,10));


	irr::video::ITexture* skyDomeTex = Interface::instance().loadTex("textures/test_skydome.png");
	_sceneMgr->addSkyDomeSceneNode(skyDomeTex);
	ISceneNode* testNode = _sceneMgr->addCubeSceneNode(23);

	testNode->setPosition(irr::core::vector3df(0,0,0));
	testNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	testNode->setMaterialTexture(0, Interface::instance().loadTex("textures/system/cube01.png"));

	camera->setTarget(testNode->getPosition());

	irr::scene::ISceneNodeAnimator* animator = _sceneMgr->createFlyCircleAnimator();

	testNode->addAnimator(animator);
	animator->drop();

	// mark center of level
	ISceneNode* centerNode = _sceneMgr->addSphereSceneNode(2);
	centerNode->setName("center-node-for-debug");
	centerNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);

	*/


	Logger::info("Stage initialized: %s", _stageName.c_str());
	return;
}




Stage::~Stage() {
	Config::instance().getIrrDevice()->setInputReceivingSceneManager(StageManager::instance().getSceneManager());
	dumpStage();
	_sceneMgr->drop();



	Logger::info("Stage free: %s", _stageName.c_str());
	return;
}



void Stage::setAsMainStage() {
	Config::instance().getIrrDevice()->setInputReceivingSceneManager(_sceneMgr);
	return;
}
