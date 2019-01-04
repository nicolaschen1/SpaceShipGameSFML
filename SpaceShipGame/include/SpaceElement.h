#ifndef ELEMENTESPACE_H
#define ELEMENTESPACE_H

#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Coordinates.h"
#include <experimental/string_view>
#include <iostream>

enum class TypeElement {VAISSEAU, ASTEROID, MISSILE, AUTRE};

class SpaceElement
{
    public:
        virtual ~SpaceElement() = default;
        explicit SpaceElement(std::experimental::string_view const&);
        void refresh(float time);
        virtual void show(sf::RenderWindow& frame) const;
        float getRadius() const;
        void testCollision(SpaceElement& other);
        virtual void reactCollision(TypeElement type) = 0;

        static inline bool estDetruit(std::unique_ptr<SpaceElement>& element) {return element->destroyed;};

    protected:
        virtual void update(float time);
        TypeElement type{TypeElement::AUTRE};
        bool destroyed{false};
        sf::Sprite sprite{};
        Coordinates position{};
        Vector speed{0.f, 0.f};
        float AngularSpeed{};
};

#endif // ELEMENTESPACE_H
