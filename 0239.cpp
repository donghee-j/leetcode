// 239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/

#include <deque>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> max_window;
    std::deque<int> max_idx;

    for (int right = 0; right < n; ++right) {
      if (!max_idx.empty() && max_idx.front() < right - k + 1)
        max_idx.pop_front();

      while (!max_idx.empty() && nums[max_idx.back()] <= nums[right])
        max_idx.pop_back();

      max_idx.push_back(right);

      if (right >= k - 1) max_window.push_back(nums[max_idx.front()]);
    }

    return max_window;
  }
};

int main() {
  Solution s;
  test(s.maxSlidingWindow({1, 3, -1, -3, 5, 3, 6, 7}, 3),
       std::vector<int>{3, 3, 5, 5, 6, 7});
  test(s.maxSlidingWindow({1}, 1), std::vector<int>{1});
}