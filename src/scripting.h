//
// scripting.h
//

#ifndef _SCRIPTING_H_
#define _SCRIPTING_H_


#include "singleton.h"

#include <lua.hpp>
#include <string>

class Scripting : public Singleton<Scripting> {
    public:

    bool init();
    void update();
    void reset();
    void close();

    bool loadFile(const std::string fileName);

    static int SceneLoad(lua_State* lua);

    private:

    lua_State* _lua;
    //static luaL_Reg _sceneFunctions[];
    //luaL_reg _sceneFunctions[];
};


#endif // _SCRIPTING_H_

