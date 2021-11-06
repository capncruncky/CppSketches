//This is a C++ --> Lua scratch pad

#include <iostream>
#include "./install/include/lua.h"
#include "./install/include/lauxlib.h"
#include "./install/include/lualib.h"

struct Player 
{
    std::string name;
    int age;

};

int main(void)
{
    //Initialize Lua state machine
    lua_State *L = luaL_newstate();

    //Initialize Lua standard libraries
    luaL_openlibs(L);

/*     Player p1;
    p1.name = "Nikki";
    p1.age = 42;

    Player p2;
    p2.name = "Brian";
    p2.age = 37;   

    std::cout << p1.name << " " << p1.age << std::endl;
    std::cout << p2.name << " " << p2.age << std::endl; */

    lua_close(L);
    return 0; 
}