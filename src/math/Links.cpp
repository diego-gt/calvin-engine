#include "math/Links.h"

namespace math {
void Link2::Rotate(double angle)
{
    m_joint_tail->Rotate(angle);
    if (m_joint_head != nullptr) {
        m_joint_head->Translate(m_joint_tail->Endpoint());
    }
}
}
