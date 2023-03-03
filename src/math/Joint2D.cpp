#include "math/Joint2D.hpp"
#include "math/Angle.hpp"

namespace math {
void Joint2D::Rotate(double angle)
{
    m_vector->Rotate(angle);
}

void Joint2D::Translate(Cartesian2 new_origin)
{
    m_vector->Translate(new_origin);
}
}
