// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/

#include <algorithm>
#include <array>
#include <utility>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum2(
      const std::vector<int>& candidates, int target) {
    std::vector<int> cur;
    std::vector<std::vector<int>> result;
    cur.reserve(candidates.size());

    std::array<int, max_val - min_val + 1> freq{};
    std::vector<std::pair<int, int>> groups;
    groups.reserve(max_val - min_val + 1);

    for (int n : candidates) ++freq[n - min_val];
    for (int i = 0; i < std::ssize(freq); ++i) {
      if (freq[i] > 0) groups.emplace_back(i + min_val, freq[i]);
    }

    backtrack(groups, 0, target, cur, result);

    return result;
  }

 private:
  static constexpr int min_val = 1;
  static constexpr int max_val = 50;

  static void backtrack(const std::vector<std::pair<int, int>>& groups, int i,
                        int remaining, std::vector<int>& cur,
                        std::vector<std::vector<int>>& result) {
    if (remaining == 0) {
      result.push_back(cur);
      return;
    }
    if (i == std::ssize(groups)) return;

    const auto& [num, count] = groups[i];
    if (num > remaining) return;

    const int max_push = std::min(count, remaining / num);
    backtrack(groups, i + 1, remaining, cur, result);
    for (int j = 1; j <= max_push; ++j) {
      cur.push_back(num);
      backtrack(groups, i + 1, remaining - j * num, cur, result);
    }
    cur.resize(cur.size() - max_push);
  }
};

int main() {
  Solution s;
  test(s.combinationSum2({1}, 2), {});
  test(sorted(s.combinationSum2({10, 1, 2, 7, 6, 1, 5}, 8)),
       {{1, 7}, {2, 6}, {1, 1, 6}, {1, 2, 5}});
  test(sorted(s.combinationSum2({2, 5, 2, 1, 2}, 5)), {{5}, {1, 2, 2}});
}
