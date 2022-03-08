#pragma once

#include "utils/Visibility.hpp"

#include <string>

namespace usc::txt {
// Prints a message to stdout ending with an ending newline
API_EXPORT void Println(const std::string& message);

// Prints a message to stdout
API_EXPORT void Print(const std::string& message);

// Print a message with a tab at the beginning
API_EXPORT void TabPrintln(const std::string& message, int tab_count = 1);
} // namespace usc::txt
