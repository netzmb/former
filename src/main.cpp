//
// main.cpp
//
//


#include "engine.h"

#include "scripting.h"

int main(int argc, char **argv)
{
    Engine::instance().init();
    
    Scripting::instance().loadFile("data/scenes/generic/scene.lua");

    Engine::instance().loop();
    Engine::instance().close();

    return 0;
}



