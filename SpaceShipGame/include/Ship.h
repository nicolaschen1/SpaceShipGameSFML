#ifndef VAISSEAU_H_INCLUDED
#define VAISSEAU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Coordinates.h"
#include "SpaceElement.h"
#include "Explosion.h"
#include "Space.h"
#include "Game.h"

class Ship : public SpaceElement {
    public:
        explicit Ship(Game& p_game, Space& p_space, sf::Color const& couleur);
        virtual void reactCollision(TypeElement otherType) override;


    protected:
        virtual void update(float time) override;

    private:
        void updateState();

        bool accelerationInProgress{false};
        bool turnLeft{false};
        bool turnRight{false};

        Game& game;
        Space& space;
        sf::Clock lastShot{};

        static constexpr float ACCELERATION{7000.f};
        static constexpr float COEFF_FRICTIONS{2.f};
        static constexpr float ANGULAR_SPEED{100.f};
};

#endif // VAISSEAU_H_INCLUDED
