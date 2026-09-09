// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/description/

#include <ostream>
#include <string>
#include <unordered_map>

#include "include/leetcode.hpp"

class Solution {
 public:
  bool isAnagram(const std::string& s, const std::string& t) {
    std::unordered_map<char, int> sMap;
    for (char c : s) {
      if (sMap.insert({c, 1}).second) continue;
      ++sMap[c];
    }

    std::unordered_map<char, int> tMap;
    for (char c : t) {
      if (tMap.insert({c, 1}).second) continue;
      ++tMap[c];
    }

    return sMap == tMap;
  }
};

int main() {
  Solution s;
  test(s.isAnagram("anagram", "nagaram"), true);
  test(s.isAnagram("rat", "car"), false);
}