#include "Asteroid.h"
#include <iostream>
#include <random>
#include <chrono>
#include <ctime>
#include "Explosion.h"

Asteroid::Asteroid(Game& p_game, Space& p_space, Asteroid* parent) : SpaceElement{"resources/asteroid.png"}, game{p_game}, space{p_space}
{
    type = TypeElement::ASTEROID;
    auto timestamp = static_cast<int>(std::chrono::system_clock::now().time_since_epoch().count());
    auto generator = std::mt19937{timestamp};
    auto distributionPosition = std::uniform_real_distribution<float>{-150, 150};
    auto distributionSpeed = std::uniform_real_distribution<float>{80, 120};
    auto distributionAngle = std::uniform_real_distribution<float>{0, 360};
    auto distributionAngularSpeed = std::uniform_real_distribution<float>{10, 30};

    speed = Vector::createFromAngle(distributionSpeed(generator), distributionAngle(generator));
    AngularSpeed = distributionAngularSpeed(generator);
    if (parent) {
        sprite.setScale(parent->sprite.getScale().x/1.4, parent->sprite.getScale().y/1.4);
        position = parent->position;
    } else {
        position = {distributionPosition(generator), distributionPosition(generator)};
    }
}

void Asteroid::reactCollision(TypeElement otherType) {
    if (otherType == TypeElement::MISSILE) {
        destroyed = true;
        game.addPoints(sprite.getScale().x * 100);
        if (sprite.getScale().x > 0.1) {
            space.add(std::make_unique<Asteroid>(game, space, this));
            space.add(std::make_unique<Asteroid>(game, space, this));
        }
        space.add(std::make_unique<Explosion>(position));
    }
}
