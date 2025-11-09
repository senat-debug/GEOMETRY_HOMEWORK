#include "point.h"
#include "utils.h"


Point2f MakeP2f(float x, float y) { //
    return {x, y};
}

Point2f Translate(const Point2f& p, float dx, float dy) {
    return { p.x + dx, p.y + dy };
}

Point2f Translate(const Point2f& p, const Vector2f& v) {
    return { p.x + v.x, p.y + v.y };
}

Point2f Scale(const Point2f& p, float sx, float sy) {
    return { p.x * sx, p.y * sy };
}

Point2f Scale(const Point2f& p, const Vector2f& s) {
    return { p.x * s.x, p.y * s.y };
}

Point2f Rotate(const Point2f& p, float angleDegree) {
    float rad = angleDegree * 3.14159265358979323846f / 180.0f;
    float c = std::cos(rad), s = std::sin(rad);
    float x = p.x * c - p.y * s;
    float y = p.x * s + p.y * c;
    return {x, y};
}

std::string ToString(const Point2f& p) {
    std::ostringstream oss;
    oss << "(" << p.x << ", " << p.y << ")";
    return oss.str();
}