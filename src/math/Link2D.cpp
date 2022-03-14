#include "math/Link2D.hpp"

namespace usc::math {
void Link2D::Rotate(double angle, AngleType angle_type)
{
    m_joint_tail->Rotate(angle, angle_type);
    if (m_joint_head != nullptr) {
        m_joint_head->Translate(m_joint_tail->Endpoint());
    }
}
}
