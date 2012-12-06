//
// graphics.h
//

#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_


#include "singleton.h"
#include "config.h"

#include <irrlicht.h>


class Graphics : public Singleton<Graphics> {
    public:
    
    bool init();
    void update();
    void close();

    void frameBegin();
    void frameEnd();

    bool isDone() const {return _isDone;};

    irr::IrrlichtDevice* getDevice() const { return _device; };
    
    private:
    
    irr::IrrlichtDevice* _device;
    irr::video::IVideoDriver* _driver;
    irr::scene::ISceneManager* _scenemgr;
    irr::video::SColor _frameColor;        // 

    bool _isDone;

    
};


#endif /* _GRAPHICS_H_ */

