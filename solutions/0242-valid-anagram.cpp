// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/description/

#include <array>
#include <string_view>

#include "leetcode.hpp"

class Solution {
 public:
  bool isAnagram(std::string_view s, std::string_view t) {
    if (s.size() != t.size()) return false;

    std::array<int, 26> arr{};
    for (char c : s) ++arr[c - 'a'];

    for (char c : t) {
      if (--arr[c - 'a'] < 0) return false;
    }

    return true;
  }
};

int main() {
  Solution s;
  test(s.isAnagram("anagram", "nagaram"), true);
  test(s.isAnagram("rat", "car"), false);
  test(s.isAnagram("aacc", "ccac"), false);
}