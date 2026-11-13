// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/

#include <algorithm>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> candidates,
                                               int target) {
    std::vector<int> cur;
    std::vector<std::vector<int>> result;
    cur.reserve(20);      // target <= 40, candidates[i] >= 2
    result.reserve(150);  // combination < 150

    std::ranges::sort(candidates);
    backtrack(candidates, 0, cur, target, result);

    return result;
  }

 private:
  static void backtrack(const std::vector<int>& nums, int i,
                        std::vector<int>& cur, int remaining,
                        std::vector<std::vector<int>>& result) {
    if (remaining == 0) {
      result.push_back(cur);
      return;
    }
    if (i >= std::ssize(nums) || nums[i] > remaining) return;

    cur.push_back(nums[i]);
    backtrack(nums, i, cur, remaining - nums[i], result);
    cur.pop_back();

    backtrack(nums, i + 1, cur, remaining, result);
  }
};

int main() {
  Solution s;
  test(sorted(s.combinationSum({2, 3, 6, 7}, 7)), {{7}, {2, 2, 3}});
  test(sorted(s.combinationSum({2, 3, 5}, 8)),
       {{3, 5}, {2, 3, 3}, {2, 2, 2, 2}});
  test(s.combinationSum({2}, 1), {});
}