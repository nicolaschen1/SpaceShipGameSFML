#ifndef VECTEUR_H
#define VECTEUR_H


struct Vector
{
    void operator+=(Vector const& other);
    void operator-=(Vector const& other);
    Vector operator*(float coefficient) const;
    static Vector createFromAngle(float size, float degreeAngle);

    float x{0.f};
    float y{0.f};
};

#endif // VECTEUR_H
