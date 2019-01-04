#include "Missile.h"
#include "ResourcesManager.h"

Missile::Missile(Coordinates const& p_position, float rotation) : SpaceElement{"resources/missile.png"}
{
    type = TypeElement::MISSILE;
    position = p_position;
    sprite.setRotation(rotation);
    speed = Vector::createFromAngle(SPEED, rotation);
    sound.setBuffer(ResourcesManager<sf::SoundBuffer>::getRessource("resources/laser.wav"));
    sound.play();
}

void Missile::reactCollision(TypeElement otherType) {
    if (otherType != TypeElement::VAISSEAU) {
        destroyed = true;
    }
}
