#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

struct SpriteComponent {
    std::string assetId;
    int width;
    int height;
    SDL_Rect srcRect;

    SpriteComponent(std::string assetId, int width, int height, int positionX = 0, int positionY = 0) {
        this->assetId = assetId;
        this->width = width;
        this->height = height;
        this->srcRect = {positionX, positionY, width, height};
    }
};

#endif