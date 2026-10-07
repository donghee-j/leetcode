// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <algorithm>
#include <limits>
#include <vector>

#include "include/leetcode.hpp"

class Solution {
 public:
  int maxProfit(const std::vector<int>& prices) {
    int minPrice = std::numeric_limits<int>::max();
    int best = 0;

    for (int price : prices) {
      minPrice = std::min(minPrice, price);
      // if price is new minPrice, profit is 0 -> does not affect best
      best = std::max(best, price - minPrice);
    }

    return best;
  }
};

int main() {
  Solution s;
  test(s.maxProfit({7, 1, 5, 3, 6, 4}), 5);
  test(s.maxProfit({7, 6, 4, 3, 1}), 0);
  test(s.maxProfit({5, 9, 1, 10}), 9);
}