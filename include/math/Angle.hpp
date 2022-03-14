#pragma once

#include "utils/Visibility.hpp"

namespace usc::math {
enum AngleType { Radians,
    Degrees };

class API_EXPORT Angle {
public:
    Angle(double value, AngleType at);
    Angle() = default;

    // Get angle value in Degrees
    double Degrees();

    // Get angle value in Radians
    double Radians();

    // Change angle value
    void Set(double value, AngleType at);

private:
    double m_degrees { 0 }, m_radians { 0 };
};
} // namespace usc::math

namespace usc::conv {
API_EXPORT double DegreesToRadians(double value);
API_EXPORT double RadiansToDegrees(double value);
} // namespace usc::conv
