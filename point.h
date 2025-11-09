#ifndef POINT_H
#define POINT_H
struct Vector2f ;

#include <string>
#include "vector.h"

struct Point2f {
    float x;
    float y;
};
Point2f MakeP2f(float x, float y);// pour la creation du point a partir de ses coordonnees
Point2f Translate(const Point2f& p, float dx, float dy); // pour la translation du point par rapport aux deplacements dx et dy 
Point2f Translate(const Point2f& p, const Vector2f& v); // pour la translation du point par rapport au vecteur v
Point2f Scale(const Point2f& p, float sx, float sy);  // pour l'homothetie du point par rapport aux facteurs sx et sy
Point2f Scale(const Point2f& p, const Vector2f& s); // pour l'homothetie du point par rapport au vecteur s
Point2f Rotate(const Point2f& p, float angleDegree);  // pour la rotation du point d'un angle en degre
std::string ToString(const Point2f& p); // pour afficher le point
#endif