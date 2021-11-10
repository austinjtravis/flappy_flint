#include <iostream>
#include <math.h>
#include <Vector2.hpp>

Vector2::Vector2(float x, float y) :
    x(x), y(y) {}

float Vector2::dot(const Vector2& vec)
{
    return this->x * vec.x + this->y + vec.y;
}

void Vector2::unit()
{
    const float norm = sqrt(pow(this->x, 2) + pow(this->y, 2));
    this->x /= norm;
    this->y /= norm;
}

Vector2 operator+(const Vector2& vec1, const Vector2& vec2)
{
    return Vector2(vec1.x + vec2.x, vec1.y + vec2.y);
}

Vector2 operator-(const Vector2& vec1, const Vector2& vec2)
{
    return Vector2(vec1.x - vec2.x, vec1.y - vec2.y);
}

Vector2 operator*(const Vector2& vec, const float scale)
{
    return Vector2(scale * vec.x, scale * vec.y);
}

Vector2 operator/(const Vector2& vec, const float scale)
{
    return Vector2(scale / vec.x, scale / vec.y);
}
