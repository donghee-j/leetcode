// 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  int findMin(const std::vector<int>& nums) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left < right) {
      const int mid = left + (right - left) / 2;

      if (nums[mid] > nums[right])
        left = mid + 1;
      else
        right = mid;
    }

    return nums[left];
  }
};

int main() {
  Solution s;
  test(s.findMin({3, 4, 5, 1, 2}), 1);
  test(s.findMin({4, 5, 6, 7, 0, 1, 2}), 0);
  test(s.findMin({11, 13, 15, 17}), 11);
}