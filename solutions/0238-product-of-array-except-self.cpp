// 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/
// O(n) time, O(1) space (output array excluded)

#include <vector>

#include "leetcode.hpp"
class Solution {
 public:
  std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    const int size = static_cast<int>(nums.size());
    std::vector<int> result(size);

    int leftProduct = 1;
    for (int i = 0; i < size; ++i) {
      result[i] = leftProduct;
      leftProduct *= nums[i];
    }

    int rightProduct = 1;
    for (int i = size - 1; i >= 0; --i) {
      result[i] *= rightProduct;
      rightProduct *= nums[i];
    }

    return result;
  }
};

int main() {
  Solution s;
  test(s.productExceptSelf({1, 2, 3, 4}), {24, 12, 8, 6});
  test(s.productExceptSelf({-1, 1, 0, -3, 3}), {0, 0, 9, 0, 0});
}