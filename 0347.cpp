// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

#include "include/leetcode.hpp"

class Solution {
 public:
  std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (int num : nums) {
      ++freq[num];
    }

    std::vector<std::pair<int, int>> sorted(freq.begin(), freq.end());
    std::ranges::sort(sorted, [](const auto& a, const auto& b) {
      return a.second > b.second;
    });

    std::vector<int> topK;
    topK.reserve(k);
    for (int i = 0; i < k; ++i) {
      topK.push_back(sorted[i].first);
    }
    return topK;
  }
};

int main() {
  Solution s;
  test<std::vector<int>, std::vector<int>>(
      s.topKFrequent({1, 1, 1, 2, 2, 3}, 2), {1, 2});
  test<std::vector<int>, std::vector<int>>(s.topKFrequent({1}, 1), {1});
  test<std::vector<int>, std::vector<int>>(
      s.topKFrequent({1, 2, 1, 2, 1, 2, 3, 1, 3, 2}, 2), {1, 2});
}