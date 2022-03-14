#pragma once

#include "math/Joint2D.hpp"

namespace usc::math {
class API_EXPORT Link2D {
public:
    Link2D(Joint2D* joint_tail, Joint2D* joint_head)
        : m_joint_tail(joint_tail)
        , m_joint_head(joint_head)
    {
    }

    void Rotate(f64 angle, AngleType angle_type);

private:
    Joint2D* m_joint_tail;
    Joint2D* m_joint_head;
};
}
