#ifndef ESPACE_H
#define ESPACE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "SpaceElement.h"
#include <iostream>

class Space
{
    public:
        Space();
        void add(std::unique_ptr<SpaceElement> element);
        void refresh();
        void manageCollisions();
        void show(sf::RenderWindow& frame) const;
        void clean();
        void empty();
        inline bool isEmpty() const {return elements.empty() && toAdd.empty();};

    protected:

    private:
        std::vector<std::unique_ptr<SpaceElement>> elements{};
        std::vector<std::unique_ptr<SpaceElement>> toAdd{};
        sf::Clock chrono{};
};

#endif // ESPACE_H
