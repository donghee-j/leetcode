// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/description/

#include <algorithm>
#include <array>
#include <string_view>

#include "include/leetcode.hpp"

class Solution {
 public:
  bool isAnagram(std::string_view s, std::string_view t) {
    if (s.size() != t.size()) return false;

    auto count = [](std::string_view str) {
      std::array<int, 26> arr{};
      for (char c : str) ++arr[c - 'a'];

      return arr;
    };

    return count(s) == count(t);
  }
};

int main() {
  Solution s;
  test(s.isAnagram("anagram", "nagaram"), true);
  test(s.isAnagram("rat", "car"), false);
}