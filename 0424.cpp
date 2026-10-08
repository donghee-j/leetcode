// 424. Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/

#include <algorithm>
#include <array>
#include <string>

#include "include/leetcode.hpp"

class Solution {
 public:
  int characterReplacement(const std::string& s, int k) {
    std::array<int, 26> count{};
    int left = 0;
    int best = 0;
    int maxCount = 0;

    for (int right = 0; right < static_cast<int>(s.size()); ++right) {
      maxCount = std::max(maxCount, ++count[s[right] - 'A']);

      if (right - left + 1 - maxCount > k) {
        --count[s[left] - 'A'];
        ++left;
      }

      best = std::max(best, right - left + 1);
    }

    return best;
  }
};

int main() {
  Solution s;
  test(s.characterReplacement("ABAB", 2), 4);
  test(s.characterReplacement("AABABBA", 1), 4);
}