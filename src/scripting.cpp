//
// scripting.cpp
//

#include "scripting.h"
#include "logger.h"

bool Scripting::init() {

    _lua = NULL;
    
    reset();

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

    return;
}


void Scripting::close() {
    if (_lua != NULL)
        lua_close(_lua);
    return;
}



bool Scripting::loadFile(const char* fileName) {
    
    // TODO add formatted output to logger
	//irr::core::stringc message();
	//Logger::warning("Scripting::loadFile(" << fileName << ")" << std::endl;
	Logger::info("Scripting::loadFile(%s)", fileName);

    // TODO to wrapper "Files" (archive access)
    //const std::string fullName = "/scripts/" + fileName;

    //std::cout << "Scripting::loadFile(" << fullName << ")" << std::endl;

    if (luaL_dofile(_lua, fileName) != 0) {
        // FIXME
        //std::cout << "Scripting::loadFile failed :" << fileName
        //    << " : " << lua_tostring(_lua, -1) << std::endl;
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


