// 239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/

#include <deque>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> maxima;
    std::deque<int> dq;

    for (int right = 0; right < n; ++right) {
      if (!dq.empty() && dq.front() < right - k + 1) dq.pop_front();

      while (!dq.empty() && nums[dq.back()] <= nums[right]) dq.pop_back();

      dq.push_back(right);

      if (right >= k - 1) maxima.push_back(nums[dq.front()]);
    }

    return maxima;
  }
};

int main() {
  Solution s;
  test(s.maxSlidingWindow({1, 3, -1, -3, 5, 3, 6, 7}, 3),
       std::vector<int>{3, 3, 5, 5, 6, 7});
  test(s.maxSlidingWindow({1}, 1), std::vector<int>{1});
}