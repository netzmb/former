//
// physics.h
//

#ifndef _PHYSICS_H_
#define _PHYSICS_H_


#include "singleton.h"
#include "subsystem.h"
//#include "configuration.h"

//#include <irrlicht.h>
#include <btBulletDynamicsCommon.h>
#include <irrbullet.h>



class Physics : public Singleton<Physics>, public Subsystem {
    public:
    
    bool init();
    void update();
    void close();

    void frameBegin();
    void frameEnd();

    irrBulletWorld* getWorld() {return _world;}


    private:
    
    btDefaultCollisionConfiguration* _collConfig;
    btCollisionDispatcher* _collDispatcher;
    btBroadphaseInterface* _overlappingPairCache;
    btSequentialImpulseConstraintSolver* _constSolver;
    btDiscreteDynamicsWorld* _ddWorld;

    //
    // irrBullet data
    //
    irrBulletWorld *_world;

    bool _enabled;

    
};


#endif /* _PHYSICS_H_ */

