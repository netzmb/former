//
// main.cpp
//
//

#include "part.h"
#include "unit.h"
#include "statemgr.h"


//#include "video.h"
#include "graphics.h"

int main(int argc, char **argv)
{
    //
    // init subsystems
    //
    
    //Graphics::instance()->init();
    Graphics::instance().init();
    
    
    StateMgr::instance().init();
    while (!StateMgr::instance().isDone()) {
        StateMgr::instance().update();
    }
    StateMgr::instance().close();

    return 0;
}



