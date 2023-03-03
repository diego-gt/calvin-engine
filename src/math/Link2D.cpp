#include "math/Link2D.hpp"

namespace math {
void Link2D::Rotate(double angle)
{
    m_joint_tail->Rotate(angle);
    if (m_joint_head != nullptr) {
        m_joint_head->Translate(m_joint_tail->Endpoint());
    }
}
}
