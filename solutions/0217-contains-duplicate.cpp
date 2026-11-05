// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/

#include <iostream>
#include <unordered_set>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int num : nums) {
      if (!seen.insert(num).second) return true;
      // Or use structured binding
      // auto [it, inserted] = seen.intert(num);
      // if (!inserted) return true;
    }
    return false;
  }
};

int main() {
  Solution s;
  test(s.containsDuplicate({1, 2, 3, 1}), true);
  test(s.containsDuplicate({1, 2, 3, 4}), false);
  test(s.containsDuplicate({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}), true);
}
