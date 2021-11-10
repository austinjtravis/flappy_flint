#pragma once

// FIXME: Template this
class Vector2
{
public:
    Vector2() = default;
    Vector2(float x, float y);

    float dot(const Vector2& vec);
    void unit();

    friend Vector2 operator+(const Vector2& vec1, const Vector2& vec2);
    friend Vector2 operator-(const Vector2& vec1, const Vector2& vec2);
    friend Vector2 operator*(const Vector2& vec, const float scale);
    friend Vector2 operator/(const Vector2& vec, const float scale);

    float x, y;
};
