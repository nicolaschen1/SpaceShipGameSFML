#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <SpaceElement.h>
#include <SFML/Audio.hpp>


class Explosion : public SpaceElement
{
    public:
        Explosion(Coordinates const& p_position);
        virtual void reactCollision(TypeElement otherType) override;

    protected:
        virtual void update(float time) override;

    private:
        float age{0};
        sf::Sound sound{};
        static constexpr float LIFE_TIME{0.1f};
};

#endif // EXPLOSION_H
