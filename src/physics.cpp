#include "physics.h"

#include <configuration.h>


bool Physics::init() {

	// TODO move debug physics option to Configuration
	_world = createIrrBulletWorld(Config::instance().getIrrDevice(),
			true, // use GImpact
			true); // use debugDrawer



	_world->setDebugMode(EPDM_DrawAabb|
						 EPDM_DrawContactPoints|
						 EPDM_DrawConstraints
						 //EPDM_DrawFeaturesText|
						 //EPDM_DrawWireframe|
						 );

	_world->setGravity(irr::core::vector3df(0.0f,-9.8f,0.0f));

	/*
    _collConfig = new btDefaultCollisionConfiguration();
    _collDispatcher = new btCollisionDispatcher(_collConfig);
    _overlappingPairCache = new btDbvtBroadphase();
    _constSolver = new btSequentialImpulseConstraintSolver();
    _ddWorld = new btDiscreteDynamicsWorld(_collDispatcher, _overlappingPairCache, _constSolver, _collConfig);

    _ddWorld->setGravity(btVector3(0.0f,-9.8f,0.0f));



    // TODO wrap to debug physics
    PhysicsDebugDrawer drawer;
    _ddWorld->setDebugDrawer(&drawer);
    */
    //_ddWorld->getDebugDrawer()->setDebugMode(btIDebugDraw::DBG_MAX_DEBUG_DRAW_MODE);
    //_ddWorld->getDebugDrawer()->setDebugMode(btIDebugDraw::DBG_DrawWireframe);
    /*|
    									   btIDebugDraw::DBG_DrawConstraintLimits |
    									   btIDebugDraw::DBG_DrawContactPoints |
    									   btIDebugDraw::DBG_DrawFeaturesText |
    									   btIDebugDraw::DBG_DrawNormals |
    									   btIDebugDraw::DBG_DrawText |
    									   btIDebugDraw::DBG_DrawWireframe);*/
    //_ddWorld->getDebugDrawer()->setDebugMode(btIDebugDraw::DBG_DrawConstraintLimits);
    //_ddWorld->getDebugDrawer()->setDebugMode(btIDebugDraw::DBG_DrawConstraints);
    //_ddWorld->getDebugDrawer()->setDebugMode(btIDebugDraw::DBG_Draw);


    // FIXME
    /*btBoxShape* testBodyShape = new btBoxShape(btVector3(1,3,1));
    btCollisionObject* testBodyCollision = new btCollisionObject();
    testBodyCollision->setCollisionShape(testBodyShape);

    _ddWorld->addCollisionObject(testBodyCollision);
	*/





    setInitialized(true);
    return true;
}


void Physics::close() {
    if (!isInitialized())
        return;

    delete _world;

    /*delete _ddWorld;
    delete _constSolver;
    delete _overlappingPairCache;
    delete _collDispatcher;
    delete _collConfig;
	*/

    return;
}



void Physics::update() {
	//_ddWorld->stepSimulation(1.0f/60.0f, 10);
	// TODO framerate - independent physics simulation

	//_world->stepSimulation(1.0f/60.0f);
	//_world->stepSimulation(1.0f/160.1f);
    return;
}


void Physics::frameBegin() {
	//_ddWorld->stepSimulation(1.0f/60.0f, 10);
	// TODO framerate - independent physics simulation

	_world->stepSimulation(1.0f/60.0f);
	//_world->stepSimulation(0.00001f);
    return;
}




void Physics::frameEnd() {
    // TODO wrap to debug physics
    //_ddWorld->debugDrawWorld();

	_world->debugDrawWorld(true);
	_world->debugDrawProperties(true, irr::video::SColor(30,40,50,255));


    return;
}

