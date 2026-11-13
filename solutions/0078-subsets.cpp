// 78. Subsets
// https://leetcode.com/problems/subsets/

#include <utility>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
    std::vector<std::vector<int>> powerset;
    powerset.reserve(1 << nums.size());
    powerset.push_back({});

    for (int num : nums) {
      const int n = static_cast<int>(powerset.size());
      for (int i = 0; i < n; ++i) {
        std::vector<int> subset = powerset[i];
        subset.push_back(num);
        powerset.emplace_back(std::move(subset));
      }
    }

    return powerset;
  }
};

int main() {
  Solution s;
  test(sorted(s.subsets({1, 2, 3})),
       {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}});
  test(sorted(s.subsets({0})), {{}, {0}});
}