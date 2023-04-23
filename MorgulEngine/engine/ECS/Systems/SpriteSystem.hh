#ifndef SPRITESYSTEM_H
#define SPRITESYSTEM_H

#include "entt/entt.hpp"
#include "../Components/IncludeComponents.hh"

class SpriteSystem {
    public:
        void Render(entt::registry& world) {
            auto view = world.view<TransformComponent, SpriteComponent>();

            for (auto entity: view) {
                const auto t = view.get<TransformComponent>(entity);
                const auto s = view.get<SpriteComponent>(entity);

                SDL_Texture* texture = Graphics::GetTexture(s.assetId);

                Graphics::DrawSprite(texture, t.position, t.scale, s.width, s.height, t.rotation, s.srcRect);
            }
        }
};

#endif