#pragma once

#include "core/Types.hpp"
#include "core/Visibility.hpp"

namespace math {
using Angle = f64;
} // namespace math

namespace convert {
API_EXPORT f64 DegreesToRadians(f64 degrees);
API_EXPORT f64 RadiansToDegrees(f64 radians);
} // namespace convert
