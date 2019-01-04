#include "Coordinates.h"
#include <iostream>
#include <cmath>
#include <algorithm>

int Coordinates::lengthSpace{0};
int Coordinates::heightSpace{0};

Coordinates::Coordinates() {
    if(lengthSpace == 0 || heightSpace == 0) {
        std::cerr << "Attention : une coordonnée a été créée avant l’initialisation de l’espace !" << std::endl;
    }
}

Coordinates::Coordinates(float px, float py) : x(px), y(py) {
    computeAgain();
}

void Coordinates::operator+=(Vector const& vector) {
    x += vector.x;
    y += vector.y;
    computeAgain();
}

void Coordinates::SpaceInit(int length, int height) {
    // sending an error message if the space was already initialized
    if(lengthSpace != 0 || heightSpace != 0) {
        std::cerr << "Warning: the space was already initialized !" << std::endl;
    }
    lengthSpace = length;
    heightSpace = height;
}

void Coordinates::computeAgain() {
    while(x>lengthSpace) {
        x -= lengthSpace;
    }
    while(x < 0) {
        x += lengthSpace;
    }
    while(y > heightSpace) {
        y -= heightSpace;
    }
    while(y < 0) {
        y += heightSpace;
    }
}

float Coordinates::computeDistance(Coordinates const& other) const {
    auto delta = Vector{std::min({abs(x-other.x), abs(x-other.x-lengthSpace), abs(x-other.x+lengthSpace)}), std::min({abs(y-other.y), abs(y-other.y-heightSpace), abs(y-other.y+heightSpace)})};
    return sqrt(delta.x*delta.x+delta.y*delta.y);
}
