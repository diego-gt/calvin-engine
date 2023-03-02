#include "math/Joint2D.hpp"
#include "math/Link2D.hpp"
#include "math/Vector2D.hpp"

namespace um = usc::math;

int main()
{
    // setting up a robot arm without effector starting from the ground so 0, 0
    um::Vector2D vec1(um::Cartesian2 { 1, 1 }, 2, um::Angle(90, um::AngleType::Degrees));
    um::Vector2D vec2(vec1.End(), 2, um::Angle(90, um::AngleType::Degrees));
    um::Vector2D vec3(vec2.End(), 2, um::Angle(90, um::AngleType::Degrees));

    um::Joint2D j1(&vec1);
    um::Joint2D j2(&vec2);
    um::Joint2D j3(&vec3);

    um::Link2D l1(&j1, &j2);
    um::Link2D l2(&j2, &j3);
    um::Link2D l3(&j3, nullptr);

    vec1.Debug();
    vec2.Debug();
    vec3.Debug();

    l2.Rotate(-45, um::AngleType::Degrees);

    vec1.Debug();
    vec2.Debug();
    vec3.Debug();

    return 0;
}
