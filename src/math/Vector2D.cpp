#include "math/Vector2D.hpp"

#include <iostream>

namespace usc::math {
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
    m_end = conv::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2D::Rotate(f64 rotation, AngleType angle_type)
{
    m_angle.Set(rotation, angle_type);
    m_end = conv::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2D::RotateTo(Angle angle)
{
    // To rotate a Vector in 2D, we need to give the new angle value we want the
    // vector on We then assign that new value to the Vector2D's angle, and
    // recalculate the endpoint Length and origin stay the same
    m_angle = angle;

    m_end = conv::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2D::Resize(f64 length)
{
    m_length = length;

    m_end = conv::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2D::Translate(Cartesian2 origin)
{
    m_start = origin;

    m_end = conv::PolarToCartesian2(m_start, Polar { m_length, m_angle });
}

void Vector2D::PrintInfo()
{
    std::cout << "Vector2D:\n"
              << "\tX: (" << m_start.x << ", " << m_start.y << ")\n"
              << "\tY: (" << m_end.x << ", " << m_end.y << ")\n"
              << "\tLength: " << m_length << "\n"
              << "\tAngle (deg): " << m_angle.Degrees() << "\n"
              << "\tAngle (rad): " << m_angle.Radians() << "\n";
}
} // namespace usc::math
