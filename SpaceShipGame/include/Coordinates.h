#ifndef Coordinates_H
#define Coordinates_H

#include "Vector.h"

class Coordinates
{
    public:
        static void SpaceInit(int length, int height); // static method because the space will be the same for all Coordinates objects
        static inline int getSpaceLength() {return lengthSpace;};
        static inline int getSpaceHeight() {return heightSpace;};
        Coordinates();
        Coordinates(float px, float py);

        // inline for more performance, returns in terms of performance to a direct access to the attribute
        inline float getX() const {return x;};
        inline float getY() const {return y;};

        void operator+=(Vector const& vector);
        float computeDistance(Coordinates const& other) const;

    private:
        void computeAgain(); // recalculate the coordinates so that they are within the limits; no need to access from outside, so private
        float x{lengthSpace/2.f};
        float y{heightSpace/2.f};

        // length and height of the space are static, shared by all Coordinates objects
        static int lengthSpace;
        static int heightSpace;
};

#endif // Coordinates_H
