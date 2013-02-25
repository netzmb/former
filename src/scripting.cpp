//
// scripting.cpp
//

#include "scripting.h"
#include "logger.h"
#include "console.h"

bool Scripting::init() {

    _lua = NULL;
    
    reset();

    setInitialized(true);
    return true;
}


void Scripting::update() {
    return;
}

void Scripting::reset() {

    if (_lua != NULL)
        lua_close(_lua);

    _lua = lua_open();

    luaL_openlibs(_lua);

    static const luaL_Reg _sceneFunctions[] = {
        {"load", &Scripting::SceneLoad},
        {NULL, NULL}
        };


    /*_sceneFunctions = {
        {"load", &Scripting::SceneLoad},
        {NULL, NULL}
        };*/

    luaL_register(_lua, "Scene", _sceneFunctions);


    //
    // GUI functions
    //

    static const luaL_Reg _guiFunctions[] = {
        {"toggleConsole", &Scripting::GUItoggleConsole},
        {NULL, NULL}
        };

    luaL_register(_lua, "EngineGui", _guiFunctions);


    return;
}


void Scripting::close() {
    if (!isInitialized())
        return;

    if (_lua != NULL)
        lua_close(_lua);
    return;
}



bool Scripting::runFile(const char* fileName) {
    
	Logger::info("Scripting::loadFile(%s)", fileName);

    // TODO to wrapper "Files" (archive access)

    if (luaL_dofile(_lua, fileName) != 0) {
    	Logger::warning("Scripting::loadFile(%s) failed: %s", fileName, lua_tostring(_lua, -1));
        return false;
    }

    return true;
}



//
// script actions
//

int Scripting::SceneLoad(lua_State* lua) {
    // get scene name

    //std::cout << "Scene.load()" << std::endl;
    //std::string sceneName = lua_tostring(lua, 1);

    //std::cout << sceneName.c_str() << std::endl;

    // return 1 argument
    lua_pushnumber(lua, 1);
    return 1;
}




int Scripting::GUItoggleConsole(lua_State* lua) {
	Logger::info("lua toggleConsole() called");

	Console::instance().toggle();

	return 0;
}

