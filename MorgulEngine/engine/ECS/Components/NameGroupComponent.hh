#ifndef NAMEGROUPCOMPONENT_H
#define NAMEGROUPCOMPONENT_H

#include <iostream>

struct NameGroupComponent {
    std::string name;
    std::string group;

    NameGroupComponent(std::string name, std::string group) {
        this->name = name;
        this->group = group;
    }
};

#endif