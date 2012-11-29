

#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_


#include "singleton2.h"


class Graphics : public Singleton<Graphics> {
    public:
    

    
    bool init() { return true; };
    void close() {};
    
    private:
    
};


#endif /* _GRAPHICS_H_ */
