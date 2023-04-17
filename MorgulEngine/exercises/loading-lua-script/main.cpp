#include "MorgulEngine.hh"
#include <sol/sol.hpp>
#include <iostream>

void TestLua() {
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.script_file("./myfirstscriptlua.lua");

    //This is how we get the value of a global variable form our Lua script
    int someVariableInsideCpp = lua["some_variable"];
    std::cout << "The value of some_varibale in C++ is "
              << someVariableInsideCpp << std::endl;

    //This is how easy we can get the values from inside a Lua table
    bool isFullScreen = lua["config"]["fullscreen"];
    sol::table config = lua["config"];
    int width = config["resolution"]["width"];
    int height = config["resolution"]["height"];
    std::cout << "We read the value fullscreen: " << isFullScreen
              << ", width: " << width << ", height: " << height << std::endl; 
}

int main(int argc, char* argv[]) {
    TestLua();
    return 0;
}