#include "math/Angle.hpp"

namespace usc::conv {
const f64 pi = 3.14159265358979323846;

f64 DegreesToRadians(f64 value) { return value * (pi / 180); }

f64 RadiansToDegrees(f64 value) { return value * (180 / pi); }
} // namespace usc::conv

namespace usc::math {
Angle::Angle(f64 value, AngleType angle_type)
{
    // Since we initialize the values to 0, we can call Resize to set the the
    // correct values.
    Set(value, angle_type);
}

void Angle::Set(f64 value, AngleType angle_type)
{
    // value is signed, so the direction is handled by the sign
    switch (angle_type) {
    case AngleType::Radians:
        m_radians += value;
        m_degrees = conv::RadiansToDegrees(m_radians);
        break;
    case AngleType::Degrees:
        m_degrees += value;
        m_radians = conv::DegreesToRadians(m_degrees);
        break;
    }
}

f64 Angle::Degrees() { return m_degrees; }

f64 Angle::Radians() { return m_radians; }
} // namespace usc::math
