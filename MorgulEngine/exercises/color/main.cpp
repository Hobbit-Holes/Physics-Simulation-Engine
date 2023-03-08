#include "Color.hh"

int main(int argc, char *args[]) {
    Color red = Color::Red();
    Color blue = Color::Blue();
    Color green = Color(0, 255, 0);
    Color black = Color();

    std::cout << "Red: " << red << std::endl;
    std::cout << "Blue: " << blue << std::endl;
    std::cout << "Green: " << green << std::endl;
    std::cout << "Black: " << black << std::endl;

    return 0;
}