#include <sol/sol.hpp>

int main(int argc, char* argv[]) {
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.script("print('Testing Lua!')");

    return 0;
}