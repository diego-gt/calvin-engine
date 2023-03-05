#include "math/Vectors.h"
#include "math/Angle.h"

#include <fmt/core.h>
#include <iostream>

namespace math {
Vector2::Vector2(Cartesian2 start, Cartesian2 end)
{
    m_start = start;
    m_end = end;
    m_length = DistanceBetweenCartesian2(start, end);
    m_angle = AngleBetweenCartesian2(start, end);
}

Vector2::Vector2(Cartesian2 origin, f64 length, Angle angle)
{
    m_start = origin;
    m_length = length;
    m_angle = angle;
    m_end = convert::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2::Rotate(f64 rotation)
{
    m_angle += rotation;
    m_end = convert::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2::RotateTo(Angle angle)
{
    // To rotate a Vector in 2, we need to give the new angle value we want the
    // vector on We then assign that new value to the Vector2's angle, and
    // recalculate the endpoint Length and origin stay the same
    m_angle = angle;

    m_end = convert::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2::Resize(f64 length)
{
    m_length = length;

    m_end = convert::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2::Translate(Cartesian2 origin)
{
    m_start = origin;

    m_end = convert::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2::Debug()
{
    fmt::println("== Vector2 Debug Information ==");
    fmt::println("X: ({:.2}, {:.2})", m_start.x, m_start.y);
    fmt::println("Y: ({:.2}, {:.2})", m_end.x, m_end.y);
    fmt::println("Length: {}", m_length);
    fmt::println("Angle (deg): {:.2}", convert::RadiansToDegrees(m_angle));
    fmt::println("Angle (rad): {:.2}", m_angle);
}
} // namespace usc::math
