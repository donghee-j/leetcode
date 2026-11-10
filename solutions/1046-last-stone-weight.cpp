// 1046. Last Stone Weight
// https://leetcode.com/problems/last-stone-weight/

#include <queue>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  int lastStoneWeight(const std::vector<int>& stones) {
    std::priority_queue<int> q(stones.begin(), stones.end());

    while (q.size() > 1) {
      // max heap: s1 >= s2
      const int s1 = q.top();
      q.pop();
      const int s2 = q.top();
      q.pop();

      if (s1 > s2) q.push(s1 - s2);
    }

    return q.empty() ? 0 : q.top();
  }
};

int main() {
  Solution s;
  test(s.lastStoneWeight({2, 7, 4, 1, 8, 1}), 1);
  test(s.lastStoneWeight({1}), 1);
  test(s.lastStoneWeight({1, 1}), 0);
}