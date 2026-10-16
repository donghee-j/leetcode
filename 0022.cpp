// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

#include <string>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> results;

    parenthesis("", 0, 0, n, results);

    return results;
  }

 private:
  static void parenthesis(std::string current, int open, int close, int n,
                          std::vector<std::string>& results) {
    if (close == n) {
      results.push_back(current);
      return;
    }

    if (open < n) parenthesis(current + "(", open + 1, close, n, results);

    if (close < open) parenthesis(current + ")", open, close + 1, n, results);
  }
};

int main() {
  Solution s;
  test(s.generateParenthesis(3),
       std::vector<std::string>{"((()))", "(()())", "(())()", "()(())",
                                "()()()"});
  test(s.generateParenthesis(1), std::vector<std::string>{"()"});
}