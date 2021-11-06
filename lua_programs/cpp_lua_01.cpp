//This is a C++ --> Lua scratch pad

#include <iostream>
#include <string>

extern "C"
{
    #include "./install/include/lua.h"
    #include "./install/include/lauxlib.h"
    #include "./install/include/lualib.h"
}

// #ifdef _WIN64
#pragma comment (lib, "install/lib/liblua.a")
// #endif 

int main(void)
{
    std::string cmd = "a = 7 + 11";

    //Initialize Lua state machine
    lua_State *L = luaL_newstate();

    int r = luaL_dostring(L, cmd);

    //Initialize Lua standard libraries
    luaL_openlibs(L);

    lua_close(L);
    return 0; 
}