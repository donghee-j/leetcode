// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

#include <iterator>
#include <unordered_map>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (int num : nums) {
      ++freq[num];
    }

    std::vector<std::vector<int>> buckets(nums.size() + 1);
    for (const auto& pair : freq) {
      buckets[pair.second].push_back(pair.first);
    }

    std::vector<int> result;
    result.reserve(k);
    for (int i = std::ssize(buckets) - 1; i >= 0; --i) {
      for (int num : buckets[i]) {
        result.push_back(num);
        if (std::ssize(result) == k) break;
      }

      if (std::ssize(result) == k) break;
    }

    return result;
  }
};

int main() {
  Solution s;
  test(sorted(s.topKFrequent({1, 1, 1, 2, 2, 3}, 2)), {1, 2});
  test(sorted(s.topKFrequent({1}, 1)), {1});
  test(sorted(s.topKFrequent({1, 2, 1, 2, 1, 2, 3, 1, 3, 2}, 2)), {1, 2});
}