// 15. 3 Sum
// https://leetcode.com/problems/3sum/

#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(const std::vector<int>& nums) {
    std::vector<int> sorted = nums;
    std::ranges::sort(sorted);

    const int n = std::ssize(sorted);
    std::vector<std::vector<int>> result;
    for (int i = 0; i < n - 2; ++i) {
      // early termination
      if (sorted[i] > 0) break;
      // duplicate
      if (i > 0 && sorted[i] == sorted[i - 1]) continue;

      int lo = i + 1;
      int hi = n - 1;

      // find lo and hi that satisfy nums[lo] + nums[hi] = -nums[i]
      while (lo < hi) {
        // duplicate
        if ((lo != i + 1) && (sorted[lo] == sorted[lo - 1])) {
          ++lo;
          continue;
        }
        if ((hi != n - 1) && (sorted[hi] == sorted[hi + 1])) {
          --hi;
          continue;
        }

        const int sum = sorted[lo] + sorted[hi];
        const int target = -sorted[i];

        if (sum > target)
          --hi;
        else if (sum < target)
          ++lo;
        else {
          result.push_back({sorted[i], sorted[lo], sorted[hi]});
          ++lo;
          --hi;
        }
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  test(sorted(s.threeSum({-1, 0, 1, 2, -1, -4})), {{-1, -1, 2}, {-1, 0, 1}});
  test(sorted(s.threeSum({0, 1, 1})), {});
  test(sorted(s.threeSum({0, 0, 0})), {{0, 0, 0}});
}
