// 567. Permutation in String
// https://leetcode.com/problems/permutation-in-string/

#include <array>
#include <string>

#include "include/leetcode.hpp"

class Solution {
 public:
  bool checkInclusion(const std::string& s1, const std::string& s2) {
    const int m = static_cast<int>(s1.size());
    const int n = static_cast<int>(s2.size());
    if (m > n) return false;

    std::array<int, 26> permutation{};
    for (char c : s1) ++permutation[c - 'a'];

    std::array<int, 26> window{};
    for (int i = 0; i < m; ++i) ++window[s2[i] - 'a'];

    int matches = 0;
    for (int i = 0; i < 26; ++i)
      if (window[i] == permutation[i]) ++matches;
    if (matches == 26) return true;

    for (int right = m; right < n; ++right) {
      int in = s2[right] - 'a';
      int out = s2[right - m] - 'a';

      ++window[in];
      if (window[in] == permutation[in])
        ++matches;
      else if (window[in] == permutation[in] + 1)
        --matches;

      --window[out];
      if (window[out] == permutation[out])
        ++matches;
      else if (window[out] == permutation[out] - 1)
        --matches;

      if (matches == 26) return true;
    }

    return false;
  }
};

int main() {
  Solution s;
  test(s.checkInclusion("ab", "eidbaoo"), true);
  test(s.checkInclusion("ab", "eidboaoo"), false);
}