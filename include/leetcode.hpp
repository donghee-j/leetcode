#pragma once
#include <iostream>
#include <vector>

// print vector
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  os << "[";
  for (std::size_t i = 0; i < v.size(); ++i) {
    if (i > 0) os << ", ";
    os << v[i];
  }
  os << "]";

  return os;
}

// test
template <typename T, typename U>
void test(const T& got, const U& expected) {
  std::cout << std::boolalpha << "[" << (got == expected ? "PASS" : "FAIL")
            << "] "
            << "expected " << expected << ", "
            << "got " << got << "\n";
}