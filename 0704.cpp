// 704. Binary Search
// https://leetcode.com/problems/binary-search/

#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  int search(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size());
    while (left < right) {
      const int mid = (left + right) / 2;

      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        left = mid + 1;
      else
        right = mid;
    }

    return -1;
  }
};

int main() {
  Solution s;
  test(s.search({-1, 0, 3, 5, 9, 12}, 9), 4);
  test(s.search({-1, 0, 3, 5, 9, 12}, 2), -1);
}