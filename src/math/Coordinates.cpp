#include "math/Coordinates.hpp"

#include <cmath>

namespace math {
f64 DistanceBetweenCartesian2(Cartesian2 a, Cartesian2 b)
{
    f64 delta_x = b.x - a.x;
    f64 delta_y = b.y - a.y;

    return sqrt(pow(delta_x, 2) + pow(delta_y, 2));
}

Angle AngleBetweenCartesian2(Cartesian2 a, Cartesian2 b)
{
    f64 delta_x = b.x - a.x;
    f64 delta_y = b.y - a.y;

    return Angle(atan2(delta_y, delta_x));
}
} // namespace usc::math

namespace convert {
math::Polar Cartesian2ToPolar(math::Cartesian2 origin, math::Cartesian2 value)
{
    f64 radius = math::DistanceBetweenCartesian2(origin, value);
    math::Angle theta = math::AngleBetweenCartesian2(origin, value);

    return math::Polar { radius, theta };
}

math::Cartesian2 PolarToCartesian2(math::Cartesian2 origin, math::Polar value)
{
    f64 x = value.radius * cos(value.theta.value());
    f64 y = value.radius * sin(value.theta.value());

    return math::Cartesian2 { x + origin.x, y + origin.y };
}
} // namespace usc::conv
