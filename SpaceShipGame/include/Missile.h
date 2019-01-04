#ifndef MISSILE_H
#define MISSILE_H

#include <SpaceElement.h>
#include <SFML/Audio.hpp>


class Missile : public SpaceElement
{
    public:
        Missile(Coordinates const& p_position, float rotation);
        virtual void reactCollision(TypeElement otherType) override;

    protected:

    private:
        sf::Sound sound{};
        static constexpr float SPEED{2000.f};
};

#endif // MISSILE_H
