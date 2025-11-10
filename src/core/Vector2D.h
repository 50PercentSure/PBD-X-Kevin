//
// Created by Kevin Zheng on 11/9/2025.
//

#ifndef PBD_X_VECTOR2D_H
#define PBD_X_VECTOR2D_H

#include <cmath>

class Vector2D {
public:
    float x, y;

    Vector2D() : x(0), y(0) {}
    Vector2D(float x, float y) : x(x), y(y) {}

    Vector2D operator+(const Vector2D &other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D &other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    Vector2D operator/(float scalar) const {
        return Vector2D(x / scalar, y / scalar);
    }

    Vector2D &operator+=(const Vector2D &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2D &operator-=(const Vector2D &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2D &operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2D &operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    float magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2D normalized() const {
        float mag = magnitude();
        if (mag > 0) return Vector2D(x/mag, y/mag);
        return Vector2D(0, 0);
    }

    float dot(const Vector2D &other) const {
        return x * other.x + y * other.y;
    }

    static float distance(const Vector2D &a, const Vector2D &b) {
        return (b - a).magnitude();
    }
};

#endif //PBD_X_VECTOR2D_H