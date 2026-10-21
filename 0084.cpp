// 84. Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <algorithm>
#include <stack>
#include <vector>

#include "leetcode.hpp"
class Solution {
 public:
  int largestRectangleArea(const std::vector<int>& heights) {
    const int n = static_cast<int>(heights.size());
    std::stack<int> stack_l;
    std::stack<int> stack_r;
    std::vector<int> left(n, -1);
    std::vector<int> right(n, n);

    for (int i = 0; i < n; ++i) {
      while (!stack_r.empty() && heights[stack_r.top()] >= heights[i]) {
        right[stack_r.top()] = i;
        stack_r.pop();
      }

      stack_r.push(i);
    }

    for (int i = n - 1; i >= 0; --i) {
      while (!stack_l.empty() && heights[stack_l.top()] >= heights[i]) {
        left[stack_l.top()] = i;
        stack_l.pop();
      }

      stack_l.push(i);
    }

    int best = 0;
    for (int i = 0; i < n; ++i) {
      best = std::max(best, heights[i] * (right[i] - left[i] - 1));
    }

    return best;
  }
};

int main() {
  Solution s;
  test(s.largestRectangleArea({2, 1, 5, 6, 2, 3}), 10);
  test(s.largestRectangleArea({2, 4}), 4);
}