#include "math/Angle.hpp"
#include "math/core.h"

namespace convert {
f64 DegreesToRadians(f64 value) { return value * (math::PI / 180); }

f64 RadiansToDegrees(f64 value) { return value * (180 / math::PI); }
} // namespace usc::conv

namespace math {
void Angle::Set(f64 value)
{
    m_value = value;
}
} // namespace usc::math
