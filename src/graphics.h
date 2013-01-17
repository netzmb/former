//
// graphics.h
//

#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_


#include "singleton.h"
#include "subsystem.h"
#include "configuration.h"

#include <irrlicht.h>


class Graphics : public Singleton<Graphics>, public Subsystem {
    public:
    
    bool init();
    void update();
    void close();

    void frameBegin();
    void frameEnd();

    //bool isDone() const {return _isDone;}
    bool isDone() const {return !_device->run();}

    void setFrameColor(irr::video::SColor& color) { _frameColor = color; }
    irr::video::SColor& getFrameColor() { return _frameColor; } const



    irr::IrrlichtDevice* getDevice() const { return _device; }
    irr::scene::ISceneManager* getSceneManager() const { return _scenemgr; }
    
    private:
    
    irr::IrrlichtDevice* _device;
    irr::video::IVideoDriver* _driver;
    irr::scene::ISceneManager* _scenemgr;
    irr::video::SColor _frameColor;        // 

    //bool _isDone;

    
};


#endif /* _GRAPHICS_H_ */

