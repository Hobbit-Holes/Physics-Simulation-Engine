#ifndef SOUNDCOMPONENT_H
#define SOUNDCOMPONENT_H

struct SoundComponent {
    std::string assetId;
    std::string sound;
    bool play;

    SoundComponent(std::string assetId, std::string sound, bool play = false) { 
        this->assetId = assetId;
        this->sound = sound;
        this->play = play;
    }
};

#endif