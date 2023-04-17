#include "MorgulEngine.hh"
#include <sol/sol.hpp>
#include <iostream>

int nativeCppCubeFunction(int n) {
    return(n * n * n);
}

void TestLua() {
    sol::state lua;
    lua.open_libraries(sol::lib::base);

    //This is how we expose and bind a native C++ function to be used by the Lua script
    lua["cube"] = nativeCppCubeFunction;

    lua.script_file("./myfirstscriptlua.lua");

    //This is how we get the value of a global variable form our Lua script
    int someVariableInsideCpp = lua["some_variable"];
    std::cout << "The value of some_varibale in C++ is "
              << someVariableInsideCpp << std::endl;

    //This is how we invoke a Lua function from inside C++
    sol::function functioFactorial = lua["factorial"];
    int functionResult = functioFactorial(5);
    std::cout << "The lua script calculated 5! as " << functionResult << std::endl;
}

int main(int argc, char* argv[]) {
    TestLua();
    return 0;
}