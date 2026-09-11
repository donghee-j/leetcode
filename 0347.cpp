// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

#include <algorithm>
#include <ranges>
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
    // sort -- O(n log n) time
    // std::ranges::sort(sorted, [](const auto& a, const auto& b) {
    //   return a.second > b.second;
    // });

    // alt 1: partial_sort (heap) -- O(n log k) time
    // std::ranges::partial_sort(
    //     sorted, sorted.begin() + k,
    //     [](const auto& a, const auto& b) { return a.second > b.second; });

    // alt 2: nth_element ()
    std::ranges::nth_element(
        sorted, sorted.begin() + k,
        [](const auto& a, const auto& b) { return a.second > b.second; });

    auto topK = sorted | std::views::take(k) | std::views::keys;

    return {topK.begin(), topK.end()};
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