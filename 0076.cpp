// 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/

#include <limits>
#include <string>
#include <unordered_map>

#include "leetcode.hpp"

class Solution {
 public:
  std::string minWindow(const std::string& s, const std::string& t) {
    const int m = static_cast<int>(s.size());
    const int n = static_cast<int>(t.size());

    if (n > m) return "";

    int count = n;
    std::unordered_map<char, int> need;
    for (char c : t) ++need[c];

    int best_left = 0;
    int best_length = std::numeric_limits<int>::max();

    int left = 0;
    for (int right = 0; right < m; ++right) {
      const char in = s[right];
      auto it = need.find(in);
      if (it != need.end()) {
        if (it->second > 0) --count;
        --it->second;
      }

      while (count == 0) {
        if (right - left + 1 < best_length) {
          best_left = left;
          best_length = right - left + 1;
        }

        const char out = s[left];
        auto it = need.find(out);

        if (it != need.end()) {
          ++it->second;
          if (it->second > 0) ++count;
        }

        ++left;
      }
    }

    if (best_length == std::numeric_limits<int>::max()) return "";

    return s.substr(best_left, best_length);
  }
};

int main() {
  Solution s;
  test(s.minWindow("ADOBECODEBANC", "ABC"), "BANC");
  test(s.minWindow("a", "a"), "a");
  test(s.minWindow("a", "aa"), "");
}