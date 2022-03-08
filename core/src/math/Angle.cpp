#include "math/Angle.hpp"

namespace usc::conv {
const double pi = 3.14159265358979323846;

double DegreesToRadians(double value) { return value * (pi / 180); }

double RadiansToDegrees(double value) { return value * (180 / pi); }
} // namespace usc::conv

namespace usc::math {
Angle::Angle(double value, AngleType at) {
  // Since we initialize the values to 0, we can call Resize to set the the
  // correct values.
  Set(value, at);
}

void Angle::Set(double value, AngleType at) {
  // value is signed, so the direction is handled by the sign
  switch (at) {
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

double Angle::Degrees() { return m_degrees; }

double Angle::Radians() { return m_radians; }
} // namespace usc::math
