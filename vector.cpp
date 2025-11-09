#include "vector.h"// pour les differentes operations sur les vecteurs
#include "utils.h" 
#include "point.h" // pour les differentes operations sur les points  
#include <cmath>// pour les fonctions mathematiques
#include <sstream>// pour la conversion en string

Vector2f MakeV2f(float x, float y) {
    return {x, y};
}

Vector2f MakeV2f(const Point2f& a, const Point2f& b) {
    return { b.x - a.x, b.y - a.y };
}

Vector2f Add(const Vector2f& a, const Vector2f& b) {
    return { a.x + b.x, a.y + b.y };
}

Vector2f Sub(const Vector2f& a, const Vector2f& b) {
    return { a.x - b.x, a.y - b.y };
}

Vector2f Scale(const Vector2f& v, float scalar) {
    return { v.x * scalar, v.y * scalar };
}

float Dot(const Vector2f& a, const Vector2f& b) {
    return a.x*b.x + a.y*b.y;
}

float Length(const Vector2f& v) {
    return std::sqrt(v.x*v.x + v.y*v.y);
}

Vector2f Normalize(const Vector2f& v) {
    float len = Length(v);
    if (len == 0.0f) return {0.0f, 0.0f};
    return { v.x / len, v.y / len };
}

float Determinant(const Vector2f& a, const Vector2f& b) {
    return a.x * b.y - a.y * b.x;
}

std::string ToString(const Vector2f& v) {
    std::ostringstream oss;
    oss << "(" << v.x << ", " << v.y << ")";
    return oss.str();
}