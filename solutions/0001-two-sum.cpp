// 1. Two Sum
// https://leetcode.com/problems/two-sum/

#include <iostream>
#include <unordered_map>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int> const& nums, int target) {
    // save iterated elements. key: number, value: index
    std::unordered_map<int, int> seen;

    for (int i = 0; i < std::ssize(nums); ++i) {
      int num = nums[i];
      int complement = target - num;

      auto it = seen.find(complement);
      if (it != seen.end()) {
        return {it->second, i};
      }

      seen.emplace(num, i);
    }

    return {};
  }
};

int main() {
  Solution s;
  test(s.twoSum({2, 7, 11, 15}, 9), {0, 1});
  test(s.twoSum({3, 2, 4}, 6), {1, 2});
  test(s.twoSum({3, 3}, 6), {0, 1});
}