#include <iostream>
#include <vector>

void test(const std::vector<int>& numbers, int target,
          const std::vector<int>& expected);

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
  // Test cases
  test({2, 7, 11, 15}, 9, {1, 2});
  test({2, 3, 4}, 6, {1, 3});
  test({-1, 0}, -1, {1, 2});

  return 0;
}

void test(const std::vector<int>& numbers, int target,
          const std::vector<int>& expected) {
  Solution s;
  std::vector<int> got = s.twoSum(numbers, target);
  std::cout << (got == expected ? "PASS" : "FAIL");
  std::cout << " expected: ";
  for (int x : expected) std::cout << x << " ";
  std::cout << " got: ";
  for (int x : got) std::cout << x << " ";
  std::cout << "\n";
}