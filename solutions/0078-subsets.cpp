// 78. Subsets
// https://leetcode.com/problems/subsets/

#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
    std::vector<int> subset;
    std::vector<std::vector<int>> powerset;
    subset.reserve(nums.size());
    powerset.reserve(1 << nums.size());

    backtrack(nums, 0, subset, powerset);

    return powerset;
  }

 private:
  static void backtrack(const std::vector<int>& nums, int i,
                        std::vector<int>& cur,
                        std::vector<std::vector<int>>& out) {
    if (i == std::ssize(nums)) {
      out.push_back(cur);
      return;
    }

    cur.push_back(nums[i]);
    backtrack(nums, i + 1, cur, out);

    cur.pop_back();
    backtrack(nums, i + 1, cur, out);
  }
};

int main() {
  Solution s;
  test(sorted(s.subsets({1, 2, 3})),
       {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}});
  test(sorted(s.subsets({0})), {{}, {0}});
}