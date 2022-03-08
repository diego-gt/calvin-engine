#include "utils/Print.hpp"

#include <iostream>

namespace usc::txt {
void Println(const std::string &message) { std::cout << message << "\n"; }
void Print(const std::string &message) { std::cout << message; }

void TabPrintln(const std::string &message, int tab_count) {
  std::cout << std::string('\t', tab_count) << message << "\n";
}
} // namespace usc::txt
