#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include "SpaceElement.h"
#include "Game.h"
#include "Space.h"

class Asteroid : public SpaceElement
{
    public:
        explicit Asteroid(Game& p_game, Space& p_space, Asteroid* parent = nullptr);
        virtual void reactCollision(TypeElement otherType) override;

    private:
        Game& game;
        Space& space;


};

#endif // ASTEROIDE_H
