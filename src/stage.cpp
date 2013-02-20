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

#include "physics.h"


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



	//ISceneNode* terrain = _sceneMgr->addAnimatedMeshSceneNode(_sceneMgr->getMesh("test.3ds"),0,NULL);
	//terrain->setScale(irr::core::vector3df(10,10,10));
	//ITerrainSceneNode* terrain = _sceneMgr->addTerrainSceneNode(_stagePath + "terrain-hmap.png");
	ISceneNode* terrain = _sceneMgr->addCubeSceneNode(1);

	terrain->setScale(irr::core::vector3df(10,1,10));
	terrain->setMaterialFlag(irr::video::EMF_COLOR_MASK, true);


	//terrain->setMaterialTexture(0, Interface::instance().loadTex("textures/grass.jpg"));


	//terrain->setPosition(terrain->getPosition() - terrain->getBoundingBox().getCenter());



	//terrain->setScale(irr::core::vector3df(5,5,5));

	_sceneMgr->setAmbientLight(irr::video::SColorf(0.9,0.9,0.2));


	//camera->setPosition(terrain->getBoundingBox().getCenter() + irr::core::vector3df(0,0,10.0f));
	//camera->setPosition(terrain->getBoundingBox().getCenter() + irr::core::vector3df(0,0,10.0f));
	camera->setTarget(terrain->getPosition());


	// TODO using btHeightfield for terrain collision
	// add terrain collision
	//IMesh* terrainMesh = _sceneMgr->getMesh("test.3ds");
	//ICollisionShape* terrainShape = new IBvhTriangleMeshShape(terrain, _sceneMgr->getMesh("test.3ds"), 0.0f);
	ICollisionShape* terrainShape = new IBoxShape(terrain,0);
	//ICollisionShape* terrainShape = new IBvhTriangleMeshShape(terrain, _sceneMgr->getMesh("test.3ds"), 0.0f);
	terrainShape->setMargin(0.01f);

	IRigidBody* terrainBody = Physics::instance().getWorld()->addRigidBody(terrainShape);



	/*
	 * dirty hack from http://irrlicht.sourceforge.net/forum/viewtopic.php?f=6&t=43441&sid=a7be44f118918752aa6ef016bf8cf4e1&start=15
	 *
	scene::CDynamicMeshBuffer meshBuffer(video::EVT_2TCOORDS, video::EIT_16BIT);
        terrain->getMeshBufferForLOD(meshBuffer, 0);
        scene::SMesh mesh;
        mesh.addMeshBuffer(&meshBuffer);
        ICollisionShape* shape = new IBvhTriangleMeshShape(terrain, &mesh, 0);
        mPhysicsWorld->addRigidBody(shape);
	 *
	 */


	ISceneNode* fall = _sceneMgr->addSphereSceneNode(1);
	fall->setPosition(terrain->getPosition() + irr::core::vector3df(0.0f, 20.0f, 0.0f));
	ICollisionShape* fallShape = new ISphereShape(fall, 10.0f);
	fallShape->setMargin(0.01f);

	IRigidBody* fallBody = Physics::instance().getWorld()->addRigidBody(fallShape);


	// constraint test
	static btVector3 pivotA(irrlichtToBulletVector(irr::core::vector3df(1,3,0)));
	btTypedConstraint* p2p = new btPoint2PointConstraint(*fallBody->getPointer(), pivotA);
	Physics::instance().getWorld()->getPointer()->addConstraint(p2p);






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
