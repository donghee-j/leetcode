// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <array>
#include <string>
#include <string_view>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::string> letterCombinations(const std::string& digits) {
    if (digits.empty()) return {};

    std::vector<std::string> result;
    std::string cur;
    backtrack(digits, 0, cur, result);

    return result;
  }

 private:
  static constexpr char digit_start = '2';
  static constexpr std::array<std::string_view, 8> letters{
      {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}};

  static void backtrack(const std::string& digits, int i, std::string& cur,
                        std::vector<std::string>& result) {
    if (i == std::ssize(digits)) {
      result.push_back(cur);
      return;
    }

    const auto& letter = letters[digits[i] - digit_start];
    for (char c : letter) {
      cur.push_back(c);
      backtrack(digits, i + 1, cur, result);
      cur.pop_back();
    }
  }
};

int main() {
  Solution s;
  test(sorted(s.letterCombinations("2")), {"a", "b", "c"});
  test(sorted(s.letterCombinations("23")),
       {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});
}
