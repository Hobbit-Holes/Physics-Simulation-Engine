#include "Sounds.hh"

// Variables
std::map<std::string, Mix_Music*> Sounds::sounds;
std::map<std::string, Mix_Chunk*> Sounds::effects;

// Functions
void Sounds::CloseSounds() {
    ClearMixer();
    Mix_Quit();

    Logger::Info("Sounds terminated.");
}

// Sounds
void Sounds::ClearMixer() {
    sounds.clear();
    effects.clear();
}

void Sounds::AddMusic(const std::string& assetId, const std::string& filePath, int volume) {
    Mix_Music* sound = Mix_LoadMUS(filePath.c_str());
    Mix_VolumeMusic(volume);
    sounds.emplace(assetId, sound);
}

Mix_Music* Sounds::GetMusic(const std::string& assetId) {
    return sounds[assetId];
}

void Sounds::AddEffect(const std::string& assetId, const std::string& filePath, int volume) {
    Mix_Chunk* sound = Mix_LoadWAV(filePath.c_str());
    Mix_VolumeChunk(sound, volume);
    effects.emplace(assetId, sound);
}

Mix_Chunk* Sounds::GetEffect(const std::string& assetId) {
    return effects[assetId];
}

