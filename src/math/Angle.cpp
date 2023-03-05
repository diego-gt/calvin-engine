#include "math/Angle.h"
#include "math/core.h"

namespace convert {
f64 DegreesToRadians(f64 degrees) { return degrees * (math::PI / 180); }

f64 RadiansToDegrees(f64 radians) { return radians * (180 / math::PI); }
} // namespace convert
