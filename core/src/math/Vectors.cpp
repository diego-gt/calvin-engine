#include "math/Vectors.hpp"

#include <iostream>

namespace usc::math {
Vector2::Vector2(Cartesian2 start, Cartesian2 end) {
  m_start  = start;
  m_end    = end;
  m_length = DistanceBetweenCartesian2(start, end);
  m_angle  = AngleBetweenCartesian2(start, end);
}

Vector2::Vector2(Cartesian2 origin, double length, Angle angle) {
  m_length = length;
  m_angle  = angle;
  m_start  = origin;
  m_end    = conv::PolarToCartesian2(m_start, Polar{m_length, m_angle});
}

void Vector2::Rotate(double rotation, AngleType at) {
  m_angle.Set(rotation, at);
  m_end = conv::PolarToCartesian2(m_start, Polar{m_length, m_angle});
}

void Vector2::RotateTo(Angle angle) {
  // To rotate a Vector in 2D, we need to give the new angle value we want the
  // vector on We then assign that new value to the Vector2's angle, and
  // recalculate the endpoint Length and origin stay the same
  m_angle = angle;

  m_end = conv::PolarToCartesian2(m_start, Polar{m_length, m_angle});
}

void Vector2::Resize(double length) {
  m_length = length;

  m_end = conv::PolarToCartesian2(m_start, Polar{m_length, m_angle});
}

void Vector2::Translate(Cartesian2 origin) {
  m_start = origin;

  m_end = conv::PolarToCartesian2(m_start, Polar{m_length, m_angle});
}

void Vector2::PrintInfo() {
  std::cout << "Vector2:\n"
            << "\tX: (" << m_start.x << ", " << m_start.y << ")\n"
            << "\tY: (" << m_end.x << ", " << m_end.y << ")\n"
            << "\tLength: " << m_length << "\n"
            << "\tAngle (deg): " << m_angle.Degrees() << "\n"
            << "\tAngle (rad): " << m_angle.Radians() << "\n";
}
} // namespace usc::math
