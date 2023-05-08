#ifndef FONTSYSTEM_H
#define FONTSYSTEM_H

#include "entt/entt.hpp"
#include "../Components/IncludeComponents.hh"

class FontSystem {
    public:
        void Render(entt::registry& world) {
            auto view = world.view<TransformComponent, FontComponent>();

            for (auto entity: view) {
                const auto t = view.get<TransformComponent>(entity);
                const auto f = view.get<FontComponent>(entity);

                TTF_Font* font = TTF_OpenFont(f.filePath.c_str(), f.size);

                Graphics::RenderText(font, f.text, t.position, t.scale, t.rotation, f.color);
                TTF_CloseFont(font);
            }
        }
};

#endif