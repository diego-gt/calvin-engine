#pragma once

#include "core/Types.hpp"
#include "core/Visibility.hpp"

namespace usc::math {
enum AngleType { Radians,
    Degrees };

class API_EXPORT Angle {
public:
    Angle(f64 value, AngleType angle_type);
    Angle() = default;

    // Get angle value in Degrees
    f64 Degrees();

    // Get angle value in Radians
    f64 Radians();

    // Change angle value
    void Set(f64 value, AngleType at);

private:
    f64 m_degrees { 0 }, m_radians { 0 };
};
} // namespace usc::math

namespace usc::conv {
API_EXPORT f64 DegreesToRadians(f64 value);
API_EXPORT f64 RadiansToDegrees(f64 value);
} // namespace usc::conv
