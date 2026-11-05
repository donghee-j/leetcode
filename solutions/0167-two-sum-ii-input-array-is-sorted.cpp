// 167. Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <iostream>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
    int leftIdx = 0;
    int rightIdx = static_cast<int>(numbers.size()) - 1;
    while (leftIdx < rightIdx) {
      const int sum = numbers[leftIdx] + numbers[rightIdx];

      if (sum == target) {
        return {leftIdx + 1, rightIdx + 1};
      } else if (sum < target) {
        ++leftIdx;
      } else {
        --rightIdx;
      }
    }

    return {};
  }
};

int main() {
  Solution s;
  test(s.twoSum({2, 7, 11, 15}, 9), {1, 2});
  test(s.twoSum({2, 3, 4}, 6), {1, 3});
  test(s.twoSum({-1, 0}, -1), {1, 2});
}