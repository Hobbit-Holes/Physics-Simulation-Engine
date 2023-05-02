#ifndef FONTS_H
#define FONTS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <cstring>
#include <stdint.h>
#include <map>

#include "Logger.hh"

class Fonts {
    private:
        static std::map<std::string, TTF_Font*> fonts;
    
    public:
        static void CloseFonts();

        // Sounds
        static void ClearFonts();
        static void AddFont(const std::string& assetId, const std::string& filePath, int size);
        static TTF_Font* GetFont(const std::string& assetId);
};

#endif