#pragma once

#include "math/Joints.h"

namespace math {
class API_EXPORT Link2 {
public:
    Link2(Joint2* joint_tail, Joint2* joint_head)
        : m_joint_tail(joint_tail)
        , m_joint_head(joint_head)
    {
    }

    void Rotate(f64 angle);

private:
    Joint2* m_joint_tail;
    Joint2* m_joint_head;
};
}
