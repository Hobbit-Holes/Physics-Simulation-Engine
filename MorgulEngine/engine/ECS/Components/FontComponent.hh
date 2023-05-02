#ifndef FONTCOMPONENT_H
#define FONTCOMPONENT_H

struct FontComponent {
    std::string filePath;
    std::string text;
    int size;
    Color color;

    FontComponent(std::string filePath, std::string text, int size = 28, Color color = Color::White()) { 
        this->filePath = filePath;
        this->text = text;
        this->size = size;
        this->color = color;
    }
};

#endif