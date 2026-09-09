// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/

#include <iostream>
#include <unordered_set>
#include <vector>

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

void test(const std::vector<int>& nums, bool expected);

int main() {
  test({1, 2, 3, 1}, true);
  test({1, 2, 3, 4}, false);
  test({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, true);

  return 0;
}

void test(const std::vector<int>& nums, bool expected) {
  Solution s;
  bool result = s.containsDuplicate(nums);

  std::cout << std::boolalpha;
  std::cout << (result == expected ? "PASS" : "FAIL") << " ";
  std::cout << "expected " << expected << ", ";
  std::cout << "got " << result << "\n";
}
