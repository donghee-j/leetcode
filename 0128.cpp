// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/

#include <algorithm>
#include <unordered_set>
#include <vector>

#include "include/leetcode.hpp"

class Solution {
 public:
  int longestConsecutive(const std::vector<int>& nums) {
    std::unordered_set<int> numset(nums.begin(), nums.end());

    int best = 0;
    for (int start : numset) {
      if (numset.contains(start - 1)) continue;

      int length = 1;
      int next = start + 1;
      while (numset.contains(next)) {
        ++length;
        ++next;
      }

      best = std::max(best, length);
    }

    return best;
  }
};

int main() {
  Solution s;
  test(s.longestConsecutive({100, 4, 200, 1, 3, 2}), 4);
  test(s.longestConsecutive({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}), 9);
  test(s.longestConsecutive({1, 0, 1, 2}), 3);
}