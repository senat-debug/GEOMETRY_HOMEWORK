
#ifndef VECTOR_H
#define VECTOR_H
struct Point2f ;

#include "point.h"
#include <string>
#include <cmath>

struct Vector2f {
    float x;
    float y;
};

Vector2f MakeV2f(float x, float y);// pour la creation du vecteur a partir de ses coordonnees
Vector2f MakeV2f(const Point2f& a, const Point2f& b);// pour la creation du vecteur a partir de deux points
Vector2f Add(const Vector2f& a, const Vector2f& b);// pour l'addition de deux vecteurs
Vector2f Sub(const Vector2f& a, const Vector2f& b);// pour la soustraction de deux vecteurs
Vector2f Scale(const Vector2f& v, float scalar);// pour le redimensionnement du vecteur
float Dot(const Vector2f& a, const Vector2f& b);// pour le produit scalaire de deux vecteurs
float Length(const Vector2f& v);
Vector2f Normalize(const Vector2f& v);// pour la normalisation du vecteur
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t);
float Determinant(const Vector2f& a, const Vector2f& b);// pour le determinant de deux vecteurs

std::string ToString(const Vector2f& v); //pour afficher le vecteur
#endif
