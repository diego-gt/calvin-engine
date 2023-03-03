#pragma once

#include "core/Visibility.hpp"
#include "math/Angle.hpp"
#include "math/Coordinates.hpp"

namespace math {
class API_EXPORT Vector2D {
public:
    // Print debug info
    void Debug();

    Vector2D() = default;

    // Create a vector using two points
    Vector2D(Cartesian2 start, Cartesian2 end);

    // Using an origin, length and angle from the horizontal axis
    Vector2D(Cartesian2 origin, f64 length, Angle angle);

    // Get the starting point of the vector
    Cartesian2 Origin() { return m_start; }

    // Get the end point of the vector
    Cartesian2 End() { return m_end; }

    // Get the current length of the vector
    f64 Length() { return m_length; }

    // Get the current direction of the vector
    Angle Direction() { return m_angle; }

    // Change the rotation angle of the vector to a given angle
    void RotateTo(Angle angle);

    // Rotate vector by value
    void Rotate(f64 rotation);

    // Change the current length of the vector
    void Resize(f64 length);

    // Change the origin of the vector
    void Translate(Cartesian2 origin);

private:
    Cartesian2 m_start { 0, 0 }, m_end { 0, 0 };
    f64 m_length { 0 };
    Angle m_angle { 0 };
};
} // namespace math
