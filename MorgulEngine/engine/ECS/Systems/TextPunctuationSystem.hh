#ifndef TEXTPUNCTUATIONSYSTEM_H
#define TEXTPUNCTUATIONSYSTEM_H

#include "entt/entt.hpp"
#include "../../Events/CollisionEvent.hh"
#include "../Components/IncludeComponents.hh"

class TextPunctuationSystem {
    public:
        void OnCollison(CollisionEvent& collision) {
            auto& entityA = collision.a;
            auto& entityB = collision.b;

            std::string groupA = collision.world->get<NameGroupComponent>(entityA).group;
            std::string groupB = collision.world->get<NameGroupComponent>(entityB).group;

            auto view = collision.world->view<NameGroupComponent, FontComponent, TextPunctuationComponent>();

            // Change the scores data if there is a score
            if (groupA == "Goals" && groupB == "Balls") {
                if (collision.world->get<NameGroupComponent>(entityA).name == "Goal Player 1") {
                    for (auto entity: view) {
                        collision.world->get<TextPunctuationComponent>(entity).scorePlayer1 += 1;
                    }
                } else {
                    for (auto entity: view) {
                        collision.world->get<TextPunctuationComponent>(entity).scorePlayer2 += 1;
                    }
                }
            }
        }

        void Update(entt::registry& world) {
            auto view = world.view<NameGroupComponent, FontComponent, TextPunctuationComponent>();
            
            for (auto entity: view) {
                auto& text = world.get<FontComponent>(entity);
                const auto score = world.get<TextPunctuationComponent>(entity);

                // Show the result of the game
                text.text = std::to_string(score.scorePlayer1) + " - " + std::to_string(score.scorePlayer2);
            }
        }
};

#endif