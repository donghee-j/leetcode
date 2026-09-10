// 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/
// O(n) time, O(n) space

#include <vector>

class Solution {
 public:
  std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    const int size = static_cast<int>(nums.size());

    std::vector<int> leftProduct(size);
    leftProduct[0] = 1;
    for (int i = 1; i < size; ++i) {
      leftProduct[i] = nums[i - 1] * leftProduct[i - 1];
    }

    std::vector<int> rightProduct(size);
    rightProduct[size - 1] = 1;
    for (int j = size - 2; j >= 0; --j) {
      rightProduct[j] = nums[j + 1] * rightProduct[j + 1];
    }

    std::vector<int> result(size);
    for (int i = 0; i < size; ++i) {
      result[i] = leftProduct[i] * rightProduct[i];
    }

    return result;
  }
};

int main() { return 0; }