#include "Space.h"
#include <iostream>

Space::Space()
{
    //ctor
}

void Space::add(std::unique_ptr<SpaceElement> element) {
    toAdd.push_back(std::move(element));
}

void Space::refresh() {
    auto loopTime = chrono.restart().asSeconds();
    for (auto i{0u}; i < elements.size(); ++i) {
        elements[i]->refresh(loopTime);
    }
}

void Space::manageCollisions() {
    for (auto i{0u}; i < elements.size(); ++i) {
        for (auto j{0u}; j < elements.size(); ++j) {
            if (i != j) {
                elements[i]->testCollision(*elements[j]);
            }
        }
    }
}

void Space::show(sf::RenderWindow& frame) const {
    for (auto& element : elements) {
        element->show(frame);
    }
}

void Space::clean() {
    auto tabEnd = std::remove_if(std::begin(elements), std::end(elements), SpaceElement::estDetruit);
    elements.erase(tabEnd, std::end(elements));
    for (auto& element : toAdd) {
        elements.push_back(std::move(element));
    }
    toAdd.clear();
}

void Space::empty() {
    elements.clear();
    toAdd.clear();
}
