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
    
    private:
    
    irr::IrrlichtDevice* _device;

    
};


#endif /* _GRAPHICS_H_ */

