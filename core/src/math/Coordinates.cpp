#include "math/Coordinates.hpp"

#include <cmath>

namespace usc::math {
double DistanceBetweenCartesian2(Cartesian2 a, Cartesian2 b) {
  double delta_x = b.x - a.x;
  double delta_y = b.y - a.y;

  return sqrt(pow(delta_x, 2) + pow(delta_y, 2));
}

Angle AngleBetweenCartesian2(Cartesian2 a, Cartesian2 b) {
  double delta_x = b.x - a.x;
  double delta_y = b.y - a.y;

  return Angle(atan2(delta_y, delta_x), AngleType::Radians);
}
} // namespace usc::math

namespace usc::conv {
math::Polar Cartesian2ToPolar(math::Cartesian2 origin, math::Cartesian2 value) {
  double radius     = math::DistanceBetweenCartesian2(origin, value);
  math::Angle theta = math::AngleBetweenCartesian2(origin, value);

  return math::Polar{radius, theta};
}

math::Cartesian2 PolarToCartesian2(math::Cartesian2 origin, math::Polar value) {
  double x = value.radius * cos(value.theta.Radians());
  double y = value.radius * sin(value.theta.Radians());

  return math::Cartesian2{x + origin.x, y + origin.y};
}
} // namespace usc::conv
