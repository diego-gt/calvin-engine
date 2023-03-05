#include "math/Joints.h"
#include "math/Angle.h"

namespace math {
void Joint2::Rotate(double angle)
{
    m_vector->Rotate(angle);
}

void Joint2::Translate(Cartesian2 new_origin)
{
    m_vector->Translate(new_origin);
}
}
