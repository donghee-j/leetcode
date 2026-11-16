// 46. Permutations
// https://leetcode.com/problems/permutations/

#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<int>> permute(std::vector<int> nums) {
    std::vector<std::vector<int>> result;

    backtrack(nums, 0, result);

    return result;
  }

 private:
  static void backtrack(std::vector<int>& nums, int start,
                        std::vector<std::vector<int>>& result) {
    if (start == std::ssize(nums)) {
      result.push_back(nums);
      return;
    }

    for (int i = start; i < std::ssize(nums); ++i) {
      std::swap(nums[start], nums[i]);
      backtrack(nums, start + 1, result);
      std::swap(nums[start], nums[i]);
    }
  }
};

int main() {
  Solution s;
  test(sorted_outer(s.permute({1, 2, 3})),
       {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}});
  test(sorted_outer(s.permute({0, 1})), {{0, 1}, {1, 0}});
  test(s.permute({1}), {{1}});
}