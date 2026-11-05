// 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/
// O(n) time, O(1) space (output array excluded)

#include <vector>

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

int main() { return 0; }