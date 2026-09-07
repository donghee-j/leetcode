#include <iostream>
#include <unordered_map>
#include <vector>

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
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  std::vector<int> result = s.twoSum(nums, target);
  for (int x : result) {
    std::cout << x << " ";
  }
  return 0;
}