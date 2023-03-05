#pragma once

#include "math/Vectors.h"

namespace math {
class API_EXPORT Joint2 {
public:
    Joint2(Vector2* vec)
        : m_vector(vec)
    {
    }

    void Rotate(f64 angle);

    Cartesian2 Endpoint() { return m_vector->End(); }

    void Translate(Cartesian2 new_origin);

private:
    Vector2* m_vector;
};
}
