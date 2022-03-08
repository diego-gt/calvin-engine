#include "math/Links.hpp"
#include "utils/Print.hpp"

namespace usc::math {
Link2::Link2(math::Vector2& tail, math::Vector2& head)
{
    m_tail = tail;
    m_head = head;
}

void Link2::PrintInfo()
{
    usc::txt::Println("Link2 Info:");
    usc::txt::TabPrintln("Tail:");
    m_tail.PrintInfo();
    usc::txt::TabPrintln("Head:");
    m_head.PrintInfo();
}
} // namespace usc::phys
