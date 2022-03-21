#include "math/Joint2D.hpp"
#include "math/Angle.hpp"

namespace usc::math {
void Joint2D::Rotate(double angle, AngleType angle_type) { m_vector->Rotate(angle, angle_type); }

void Joint2D::Translate(Cartesian2 new_origin) { m_vector->Translate(new_origin); }
}
