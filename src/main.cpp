//
// main.cpp
//
//


#include "engine.h"


int main(int argc, char **argv)
{
    Engine::instance().init();
    Engine::instance().loop();
    Engine::instance().close();

    return 0;
}



