#include "math/Joint2D.hpp"
#include "math/Link2D.hpp"
#include "math/Vector2D.hpp"
#include "math/core.h"

int main()
{
    // setting up a robot arm without effector starting from the ground so 0, 0
    math::Vector2D vec1(math::Cartesian2 { 1, 1 }, 2, math::Angle(math::PI / 2));
    math::Vector2D vec2(vec1.End(), 2, math::Angle(math::PI / 2));
    math::Vector2D vec3(vec2.End(), 2, math::Angle(math::PI / 2));

    math::Joint2D j1(&vec1);
    math::Joint2D j2(&vec2);
    math::Joint2D j3(&vec3);

    math::Link2D l1(&j1, &j2);
    math::Link2D l2(&j2, &j3);
    math::Link2D l3(&j3, nullptr);

    vec1.Debug();
    vec2.Debug();
    vec3.Debug();

    l2.Rotate(-math::PI / 4);

    vec1.Debug();
    vec2.Debug();
    vec3.Debug();

    return 0;
}
