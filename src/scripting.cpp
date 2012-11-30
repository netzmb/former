//
// scripting.cpp
//

#include "scripting.h"

// FIXME replace to Log << blah;
#include <iostream>




bool Scripting::init() {

    _lua = NULL;
    
    reset();


    return true;
}


void Scripting::reset() {

    if (_lua != NULL)
        lua_close(_lua);

    _lua = lua_open();

    luaL_openlibs(_lua);

    /*_sceneFunctions = {
        {"load", &Scripting::SceneLoad},
        {NULL, NULL}
        };*/

    //luaL_register(_lua, "Scene", _sceneFunctions);

    return;
}


void Scripting::close() {
    lua_close(_lua);
    return;
}



bool Scripting::loadFile(const std::string fileName) {
    
    std::cout << "Scripting::loadFile(" << fileName << ")" << std::endl;

    // TODO to wrapper "Files" (archive access)
    //const std::string fullName = "/scripts/" + fileName;

    //std::cout << "Scripting::loadFile(" << fullName << ")" << std::endl;

    if (luaL_dofile(_lua, fileName.c_str()) != 0) {
        // FIXME
        std::cout << "Scripting::loadFile failed :" << fileName
            << " : " << lua_tostring(_lua, -1) << std::endl;
        return false;
    }

    return true;
}



//
// script actions
//

int SceneLoad(lua_State* lua) {
    // get scene name
    std::string sceneName = lua_tostring(lua, 1);

    std::cout << sceneName.c_str() << std::endl;

    // return 1 argument
    lua_pushnumber(lua, 0);
    return 1;
}


