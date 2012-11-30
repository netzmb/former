//
// graphics.h
//

#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_


#include "singleton.h"
#include "config.h"



class Graphics : public Singleton<Graphics> {
    public:
    

    
    bool init() { return true; };
    void update() {};
    void close() {};
    
    private:

    
};


#endif /* _GRAPHICS_H_ */

