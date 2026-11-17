// 90. Subsets II
// https://leetcode.com/problems/subsets-ii/

#include <array>
#include <utility>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<int>> subsetsWithDup(const std::vector<int>& nums) {
    std::vector<int> cur;
    std::vector<std::vector<int>> result;
    cur.reserve(nums.size());
    result.reserve(1 << nums.size());

    std::array<int, max_val - min_val + 1>
        freq{};                               // nums in [min_val, max_val]
    std::vector<std::pair<int, int>> groups;  // {num, freq}
    for (int n : nums) ++freq[n - min_val];
    for (int i = 0; i < std::ssize(freq); ++i) {
      if (freq[i] > 0) groups.emplace_back(min_val + i, freq[i]);
    }

    backtrack(groups, 0, cur, result);

    return result;
  }

 private:
  static constexpr int min_val = -10;
  static constexpr int max_val = 10;

  static void backtrack(const std::vector<std::pair<int, int>>& groups, int i,
                        std::vector<int>& cur,
                        std::vector<std::vector<int>>& result) {
    if (i == std::ssize(groups)) {
      result.push_back(cur);
      return;
    }

    const auto [num, freq] = groups[i];

    backtrack(groups, i + 1, cur, result);
    for (int j = 0; j < freq; ++j) {
      cur.push_back(num);
      backtrack(groups, i + 1, cur, result);
    }
    cur.resize(cur.size() - freq);
  }
};

int main() {
  Solution s;
  test(sorted(s.subsetsWithDup({0})), {{}, {0}});
  test(sorted(s.subsetsWithDup({1, 1})), {{}, {1}, {1, 1}});
  test(sorted(s.subsetsWithDup({-10, 10})), {{}, {-10}, {10}, {-10, 10}});
  test(sorted(s.subsetsWithDup({1, 2, 2})),
       {{}, {1}, {2}, {1, 2}, {2, 2}, {1, 2, 2}});
}
