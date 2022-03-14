#include "math/Link2D.hpp"

namespace usc::math {
void Link2D::Rotate(double angle, AngleType at)
{
    m_joint_tail->Rotate(angle, at);
    if (m_joint_head != nullptr) {
        m_joint_head->Translate(m_joint_tail->Endpoint());
    }
}
}
