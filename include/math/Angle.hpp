#pragma once

#include "core/Types.hpp"
#include "core/Visibility.hpp"

namespace math {
class API_EXPORT Angle {
public:
    Angle(f64 value)
        : m_value(value)
    {
    }
    Angle() = default;

    // Change angle value
    void Set(f64 value);
    f64 value() { return m_value; }

private:
    f64 m_value { 0 };
};
} // namespace math

namespace convert {
API_EXPORT f64 DegreesToRadians(f64 value);
API_EXPORT f64 RadiansToDegrees(f64 value);
} // namespace convert
