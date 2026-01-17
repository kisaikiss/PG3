#include "MathStructs.h"

Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2 operator+(const Vector2& v1, const Vector2& v2) {
    return Vector2(v1.x + v2.x, v1.y + v2.y);
}

Vector2 operator-(const Vector2& v1, const Vector2& v2) {
    return Vector2(v1.x - v2.x, v1.y - v2.y);
}