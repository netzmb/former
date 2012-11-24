//
// main.cpp
//
//

#include "part.h"
#include "unit.h"
#include "statemgr.h"

int main(int argc, char **argv)
{
    StateMgr::instance().init();
    StateMgr::instance().update();
    StateMgr::instance().close();

    return 0;
}



