//
// graphics.h
//
// graphics subsystem singleton
//

//#include "singleton2.h"

class Graphics {
    public:
    static Graphics* instance();
    
    protected:
    Graphics();
};
