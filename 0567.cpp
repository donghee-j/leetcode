// 567. Permutation in String
// https://leetcode.com/problems/permutation-in-string/

#include <string>
#include <string_view>
#include <unordered_map>

#include "include/leetcode.hpp"

class Solution {
 public:
  bool checkInclusion(const std::string& s1, const std::string& s2) {
    const int m = static_cast<int>(s1.size());
    const int n = static_cast<int>(s2.size());
    if (m > n) return false;

    std::unordered_map<char, int> permutation;
    for (char c : s1) ++permutation[c];

    std::unordered_map<char, int> window;
    for (int i = 0; i < m; ++i) ++window[s2[i]];
    if (permutation == window) return true;

    for (int right = m; right < n; ++right) {
      int left = right - m;

      ++window[s2[right]];
      if (--window[s2[left]] == 0) window.erase(s2[left]);

      if (permutation == window) return true;
    }

    return false;
  }
};

int main() {
  Solution s;
  test(s.checkInclusion("ab", "eidooba"), true);
  test(s.checkInclusion("ab", "eidboaoo"), false);
}