#pragma once

#include "core/Visibility.hpp"
#include "math/Angle.hpp"

// Primitives & helper functions
namespace usc::math {
struct API_EXPORT Cartesian2 {
    f64 x, y;
};

const Cartesian2 OriginPoint2 { 0, 0 };

struct API_EXPORT Cartesian3 {
    f64 x, y, z;
};

const Cartesian3 OriginPoint3 { 0, 0, 0 };

struct API_EXPORT Polar {
    f64 radius;
    Angle theta;
};

API_EXPORT f64 DistanceBetweenCartesian2(Cartesian2 a, Cartesian2 b);
API_EXPORT Angle AngleBetweenCartesian2(Cartesian2 a, Cartesian2 b);
} // namespace usc::math

// functions to convert between primitive types
namespace usc::conv {
API_EXPORT math::Polar Cartesian2ToPolar(math::Cartesian2 origin, math::Cartesian2 value);
API_EXPORT math::Cartesian2 PolarToCartesian2(math::Cartesian2 origin, math::Polar value);
} // namespace usc::conv
