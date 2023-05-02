#include "Fonts.hh"

// Variables
std::map<std::string, TTF_Font*> Fonts::fonts;

// Functions
void Fonts::CloseFonts() {
    ClearFonts();
    TTF_Quit();

    Logger::Info("Fonts terminated.");
}

// Sounds
void Fonts::ClearFonts() {
    fonts.clear();
}

void Fonts::AddFont(const std::string& assetId, const std::string& filePath, int size) {
    TTF_Font* font = TTF_OpenFont(filePath.c_str(), size);
    fonts.emplace(assetId, font);
}

TTF_Font* Fonts::GetFont(const std::string& assetId) {
    return fonts[assetId];
}
