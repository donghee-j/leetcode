// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/description/

#include <ostream>
#include <string>
#include <unordered_map>

#include "include/leetcode.hpp"

class Solution {
 public:
  bool isAnagram(std::string_view s, std::string_view t) {
    if (s.size() != t.size()) return false;

    auto count = [](std::string_view str) {
      std::unordered_map<char, int> map;
      for (char c : str) ++map[c];

      return map;
    };

    return count(s) == count(t);
  }
};

int main() {
  Solution s;
  test(s.isAnagram("anagram", "nagaram"), true);
  test(s.isAnagram("rat", "car"), false);
}