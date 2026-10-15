// 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/

#include <stack>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
    const int n = static_cast<int>(temperatures.size());
    std::stack<int> indices;
    std::vector<int> result(n);

    for (int i = 0; i < n; ++i) {
      while (!indices.empty() &&
             temperatures[indices.top()] < temperatures[i]) {
        result[indices.top()] = i - indices.top();
        indices.pop();
      }

      indices.push(i);
    }

    return result;
  }
};

int main() {
  Solution s;
  test<std::vector<int>, std::vector<int>>(
      s.dailyTemperatures({73, 74, 75, 71, 69, 72, 76, 73}),
      {1, 1, 4, 2, 1, 1, 0, 0});
  test<std::vector<int>, std::vector<int>>(
      s.dailyTemperatures({30, 40, 50, 60}), {1, 1, 1, 0});
  test<std::vector<int>, std::vector<int>>(
      s.dailyTemperatures({30, 20, 30, 20}), {0, 1, 0, 0});
}