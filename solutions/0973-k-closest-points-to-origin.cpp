// 973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/

#include <queue>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<int>> kClosest(
      const std::vector<std::vector<int>>& points, int k) {
    auto comparator = [](const std::vector<int>& a, const std::vector<int>& b) {
      return norm2(a) < norm2(b);
    };
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                        decltype(comparator)>
        pq;
    for (auto& p : points) {
      pq.push(p);
      if (std::ssize(pq) > k) pq.pop();
    }

    std::vector<std::vector<int>> result;
    result.reserve(k);
    while (!pq.empty()) {
      result.push_back(pq.top());
      pq.pop();
    }

    return result;
  }

 private:
  static int norm2(const std::vector<int>& a) {
    return a[0] * a[0] + a[1] * a[1];
  }
};

int main() {
  Solution s;
  test(s.kClosest({{0, 0}}, 1), {{0, 0}});
  test(s.kClosest({{1, 3}, {-2, 2}}, 1), {{-2, 2}});
  test(sorted(s.kClosest({{1, 3}, {-2, 2}}, 2)), {{-2, 2}, {1, 3}});
  test(sorted(s.kClosest({{0, 1}, {0, 1}}, 2)), {{0, 1}, {0, 1}});
  test(sorted(s.kClosest({{3, 3}, {5, -1}, {-2, 4}}, 2)), {{-2, 4}, {3, 3}});
}