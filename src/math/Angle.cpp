#include "math/Angle.hpp"

namespace convert {
// TODO: move this constant to a more logical place
const f64 pi = 3.14159265358979323846;

f64 DegreesToRadians(f64 value) { return value * (pi / 180); }

f64 RadiansToDegrees(f64 value) { return value * (180 / pi); }
} // namespace usc::conv

namespace math {
void Angle::Set(f64 value)
{
    m_value = value;
}
} // namespace usc::math
