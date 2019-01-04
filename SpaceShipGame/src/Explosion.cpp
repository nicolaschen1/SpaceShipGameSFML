#include "Explosion.h"
#include <iostream>
#include "ResourcesManager.h"

Explosion::Explosion(Coordinates const& p_position) : SpaceElement{"resources/explosion.png"}
{
    position = p_position;
    sound.setBuffer(ResourcesManager<sf::SoundBuffer>::getRessource("resources/explosion.wav"));
    sound.play();
}

void Explosion::update(float time) {
    age += time;

    if (age < LIFE_TIME) {
        sprite.setScale(age/LIFE_TIME, age/LIFE_TIME); //explosion grandit au fur et a mesure du time
    } else {
        sprite.setScale(0, 0);
        if (sound.getStatus() == sf::SoundSource::Stopped) {
            destroyed = true;
        }
    }
}

void Explosion::reactCollision(TypeElement otherType) {}
