// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <algorithm>
#include <ranges>
#include <vector>

#include "include/leetcode.hpp"

class Solution {
 public:
  int maxProfit(const std::vector<int>& prices) {
    int size = std::ssize(prices);
    if (size < 2) return 0;

    int sell = size - 1;
    int buy = sell - 1;

    int currentMaxProfit = prices[sell] - prices[buy];
    int buyPricePrev = prices[buy];
    while (buy >= 0) {
      if (prices[buy] < buyPricePrev) {
        currentMaxProfit =
            std::max(currentMaxProfit, prices[sell] - prices[buy]);
      }

      if (prices[buy] > prices[sell]) {
        sell = buy;
      }

      buyPricePrev = prices[buy];
      --buy;
    }

    return std::max(currentMaxProfit, 0);
  }
};

int main() {
  Solution s;
  test(s.maxProfit({7, 1, 5, 3, 6, 4}), 5);
  test(s.maxProfit({7, 6, 4, 3, 1}), 0);
  test(s.maxProfit({5, 9, 1, 10}), 9);
}