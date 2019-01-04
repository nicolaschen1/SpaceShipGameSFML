#include "Vector.h"
#undef __STRICT_ANSI__
#include <cmath>

void Vector::operator+=(Vector const& other) {
    x+= other.x;
    y+= other.y;
}

void Vector::operator-=(Vector const& other) {
    x-= other.x;
    y-= other.y;
}

Vector Vector::operator*(float coefficient) const {
    return Vector{x*coefficient, y*coefficient};
}

Vector Vector::createFromAngle(float size, float degreeAngle) {
    return {size*cos(degreeAngle/180.f*M_PI), size*sin(degreeAngle/180.f*M_PI)};
}
