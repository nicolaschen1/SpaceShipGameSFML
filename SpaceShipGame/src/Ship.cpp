#include <iostream>
#include "../include/Ship.h"
#include "SpaceElement.h"
#include "Missile.h"

Ship::Ship(Game& p_game, Space& p_space, sf::Color const& couleur) : SpaceElement{"resources/spaceship.png"}, game{p_game}, space{p_space} {
    type = TypeElement::VAISSEAU;
    sprite.setColor(couleur);
}

void Ship::updateState() {
    accelerationInProgress = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    turnLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    turnRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastShot.getElapsedTime().asSeconds() > 0.1) {
        space.add(std::make_unique<Missile>(position, sprite.getRotation()));
        lastShot.restart();
    }
}

void Ship::update(float time) {
    updateState();

    if (!destroyed) {
        if (accelerationInProgress) {
        speed += Vector::createFromAngle(ACCELERATION * time, sprite.getRotation());
        }
        speed -= speed * COEFF_FRICTIONS * time;

        if (turnLeft) {
            AngularSpeed = - ANGULAR_SPEED;
        } else if (turnRight) {
            AngularSpeed = ANGULAR_SPEED;
        } else {
            AngularSpeed = 0;
        }
    }
}

void Ship::reactCollision(TypeElement otherType) {
    if (otherType == TypeElement::ASTEROID) {
        destroyed = true;
        game.finish();
        space.add(std::make_unique<Explosion>(position));
    }
}
