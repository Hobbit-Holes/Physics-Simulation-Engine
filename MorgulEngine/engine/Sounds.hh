#ifndef SOUNDS_H
#define SOUNDS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <cstring>
#include <stdint.h>
#include <map>

#include "Logger.hh"

class Sounds {
    private:
        static std::map<std::string, Mix_Music*> sounds;
        static std::map<std::string, Mix_Chunk*> effects;
    
    public:
        static void CloseSounds();

        // Sounds
        static void ClearMixer();
        static void AddMusic(const std::string& assetId, const std::string& filePath, int volume);
        static Mix_Music* GetMusic(const std::string& assetId);
        static void AddEffect(const std::string& assetId, const std::string& filePath, int volume);
        static Mix_Chunk* GetEffect(const std::string& assetId);
};

#endif