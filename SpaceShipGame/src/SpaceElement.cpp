#include "SpaceElement.h"
#include <iostream>
#include <experimental/string_view>
#include "ResourcesManager.h"
#include <SFML/Graphics.hpp>

SpaceElement::SpaceElement(std::experimental::string_view const& imagePath) {
    sprite.setTexture(ResourcesManager<sf::Texture>::getRessource(imagePath));
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(position.getX(), position.getY());
};

void SpaceElement::refresh(float time) {
    update(time);
    auto move = speed * time;
    position += move;
    sprite.setPosition(position.getX(), position.getY());
    sprite.rotate(AngularSpeed * time);
}

void SpaceElement::update(float time) {

}

void SpaceElement::show(sf::RenderWindow& frame) const {
    auto displays = std::array<Vector, 9>{Vector{-1, -1}, Vector{0, -1}, Vector{1, -1},
                                            Vector{-1, 0}, Vector{0, 0}, Vector{1, 0},
                                            Vector{-1, 1}, Vector{0, 1}, Vector{1, 1}};
    for (auto& display : displays) {
        auto transformation = sf::Transform{};
        transformation.translate(display.x*Coordinates::getSpaceLength(), display.y*Coordinates::getSpaceHeight());
        frame.draw(sprite, transformation);
    }
}

float SpaceElement::getRadius() const {
    return sprite.getGlobalBounds().height/2.4f;
}

void SpaceElement::testCollision(SpaceElement& other) {
    auto distance = position.computeDistance(other.position);
    if (distance < getRadius() + other.getRadius()) {
            reactCollision(other.type);
    }
}
