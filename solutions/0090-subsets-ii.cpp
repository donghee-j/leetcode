// 90. Subsets II
// https://leetcode.com/problems/subsets-ii/

#include <array>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<int>> subsetsWithDup(const std::vector<int>& nums) {
    std::vector<int> cur;
    std::vector<std::vector<int>> result;
    cur.reserve(nums.size());
    result.reserve(1 << nums.size());

    Freq freq{};  // nums in [min_val, max_val]
    for (int n : nums) ++freq[n - min_val];

    backtrack(freq, 0, cur, result);

    return result;
  }

 private:
  static constexpr int min_val = -10;
  static constexpr int max_val = 10;
  using Freq = std::array<int, max_val - min_val + 1>;

  static void backtrack(const Freq& freq, int i, std::vector<int>& cur,
                        std::vector<std::vector<int>>& result) {
    if (i == std::ssize(freq)) {
      result.push_back(cur);
      return;
    }

    backtrack(freq, i + 1, cur, result);
    for (int j = 0; j < freq[i]; ++j) {
      cur.push_back(min_val + i);
      backtrack(freq, i + 1, cur, result);
    }
    cur.resize(cur.size() - freq[i]);
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
