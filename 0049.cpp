// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

#include <algorithm>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

#include "include/leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(
      const std::vector<std::string>& strs) {
    if (strs.size() == 1) return {strs};

    std::unordered_map<std::string, std::vector<std::string>> map;
    for (auto str : strs) {
      auto originalStr = str;
      std::ranges::sort(str);
      map[str].push_back(originalStr);
    }

    auto values = std::views::values(map);
    return std::vector<std::vector<std::string>>(values.begin(), values.end());
  }
};

int main() {
  Solution s;
  test(s.groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"}),
       {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}});
}