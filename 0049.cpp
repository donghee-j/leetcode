// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "include/leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(
      const std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    for (const auto& str : strs) {
      std::string key = str;
      std::ranges::sort(key);
      groups[key].push_back(str);
    }

    std::vector<std::vector<std::string>> result;
    for (auto& [_, group] : groups) result.push_back(std::move(group));

    return result;
  }
};

int main() { return 0; }