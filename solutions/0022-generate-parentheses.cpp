// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

#include <string>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> results;
    std::string current;
    current.reserve(2 * n);

    parenthesis(current, 0, 0, n, results);

    return results;
  }

 private:
  static void parenthesis(std::string& current, int open, int close, int n,
                          std::vector<std::string>& results) {
    if (close == n) {
      results.push_back(current);
      return;
    }

    if (open < n) {
      current.push_back('(');
      parenthesis(current, open + 1, close, n, results);
      current.pop_back();
    }

    if (close < open) {
      current.push_back(')');
      parenthesis(current, open, close + 1, n, results);
      current.pop_back();
    }
  }
};

int main() {
  Solution s;
  test(s.generateParenthesis(3),
       {"((()))", "(()())", "(())()", "()(())", "()()()"});
  test(s.generateParenthesis(1), {"()"});
}