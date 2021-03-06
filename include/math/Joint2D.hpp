#pragma once

#include "math/Vector2D.hpp"

namespace usc::math {
class API_EXPORT Joint2D {
public:
    Joint2D(Vector2D* vec)
        : m_vector(vec)
    {
    }

    void Rotate(f64 angle, AngleType angle_type);

    Cartesian2 Endpoint() { return m_vector->End(); }

    void Translate(Cartesian2 new_origin);

private:
    Vector2D* m_vector;
};
}
