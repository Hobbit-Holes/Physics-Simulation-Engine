#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H

#include "entt/entt.hpp"
#include "../Components/IncludeComponents.hh"

class SoundSystem {
    public:
        void Render(entt::registry& world) {
            auto view = world.view<SoundComponent>();

            for (auto entity: view) {
                auto& s = view.get<SoundComponent>(entity);

                // Depending the type of sound, the way it works is different
                if (s.sound == "Music") {
                    if (s.play) {
                        if (Mix_PlayingMusic() == 0) {
                            Mix_PlayMusic(Sounds::GetMusic(s.assetId), -1);
                        } else {
                            if(Mix_PausedMusic() == 1) {
                                Mix_ResumeMusic();
                            } else {
                                Mix_PauseMusic();
                            }
                        }
                        s.play = false;
                    }
                } else if (s.sound == "Effect") {
                    if (s.play) {
                        Mix_PlayChannel(-1, Sounds::GetEffect(s.assetId), 0);
                        s.play = false;
                    }
                }
            }
        }
};

#endif