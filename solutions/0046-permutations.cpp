// 46. Permutations
// https://leetcode.com/problems/permutations/

#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
    std::vector<int> cur;
    std::vector<std::vector<int>> result;
    cur.reserve(nums.size());

    backtrack(nums, 0, cur, result);

    return result;
  }

 private:
  static void backtrack(const std::vector<int>& nums, int used,
                        std::vector<int>& cur,
                        std::vector<std::vector<int>>& result) {
    if (cur.size() == nums.size()) {
      result.push_back(cur);
      return;
    }

    for (int i = 0; i < std::ssize(nums); ++i) {
      if (used & (1 << i)) continue;

      cur.push_back(nums[i]);
      backtrack(nums, used | (1 << i), cur, result);
      cur.pop_back();
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