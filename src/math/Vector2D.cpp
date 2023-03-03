#include "math/Vector2D.hpp"
#include "math/Angle.hpp"

#include <fmt/core.h>
#include <iostream>

namespace math {
Vector2D::Vector2D(Cartesian2 start, Cartesian2 end)
{
    m_start = start;
    m_end = end;
    m_length = DistanceBetweenCartesian2(start, end);
    m_angle = AngleBetweenCartesian2(start, end);
}

Vector2D::Vector2D(Cartesian2 origin, f64 length, Angle angle)
{
    m_length = length;
    m_angle = angle;
    m_start = origin;
    m_end = convert::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2D::Rotate(f64 rotation)
{
    m_angle.Set(rotation);
    m_end = convert::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2D::RotateTo(Angle angle)
{
    // To rotate a Vector in 2D, we need to give the new angle value we want the
    // vector on We then assign that new value to the Vector2D's angle, and
    // recalculate the endpoint Length and origin stay the same
    m_angle = angle;

    m_end = convert::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2D::Resize(f64 length)
{
    m_length = length;

    m_end = convert::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2D::Translate(Cartesian2 origin)
{
    m_start = origin;

    m_end = convert::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2D::Debug()
{
    fmt::println("== Vector2D Debug Information ==");
    fmt::println("X: ({:.2}, {:.2})", m_start.x, m_start.y);
    fmt::println("Y: ({:.2}, {:.2})", m_start.x, m_start.y);
    fmt::println("Length: {}", m_length);
    fmt::println("Angle (deg): {:.2}", convert::RadiansToDegrees(m_angle.value()));
    fmt::println("Angle (rad): {:.2}", m_angle.value());
}
} // namespace usc::math
