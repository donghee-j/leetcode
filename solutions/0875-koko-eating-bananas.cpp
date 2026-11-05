// 875. Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/

#include <algorithm>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  int minEatingSpeed(const std::vector<int>& piles, int h) {
    int left = 1;
    int right = std::ranges::max(piles);

    auto can_finish = [&](int k) {
      int total = 0;
      for (int pile : piles) {
        total += (pile + k - 1) / k;
        if (total > h) return false;
      }

      return true;
    };

    while (left < right) {
      const int mid = left + (right - left) / 2;

      if (can_finish(mid))
        right = mid;
      else
        left = mid + 1;
    }

    return left;
  }
};

int main() {
  Solution s;
  test(s.minEatingSpeed({3, 6, 7, 11}, 8), 4);
  test(s.minEatingSpeed({30, 11, 23, 4, 20}, 5), 30);
  test(s.minEatingSpeed({30, 11, 23, 4, 20}, 6), 23);
}