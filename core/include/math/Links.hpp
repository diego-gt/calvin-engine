#pragma once

#include "math/Vectors.hpp"
#include "utils/Visibility.hpp"

namespace usc::math {
class API_EXPORT Link2 {
public:
    Link2(math::Vector2& tail, math::Vector2& head);

    void PrintInfo();

    math::Cartesian2 Endpoint() { return m_head.End(); }

private:
    math::Vector2 m_tail, m_head;
};
} // namespace usc::phys
