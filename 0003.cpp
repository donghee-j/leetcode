// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <algorithm>
#include <ranges>
#include <string>
#include <unordered_set>

#include "include/leetcode.hpp"

class Solution {
 public:
  int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_set<char> window;
    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < std::ssize(s); ++right) {
      while (window.contains(s[right])) {
        window.erase(s[left]);
        ++left;
      }

      window.insert(s[right]);
      maxLength = std::max(maxLength, right - left + 1);
    }

    return maxLength;
  }
};

int main() {
  Solution s;

  test(s.lengthOfLongestSubstring("abcabcbb"), 3);
  test(s.lengthOfLongestSubstring("bbbbb"), 1);
  test(s.lengthOfLongestSubstring("pwwkew"), 3);

  return 0;
}