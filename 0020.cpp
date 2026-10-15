// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

#include <stack>
#include <string>

#include "leetcode.hpp"

class Solution {
 public:
  bool isValid(const std::string& s) {
    std::stack<char> open;

    for (char c : s) {
      if (isOpen(c))
        open.push(c);
      else if (isClose(c)) {
        if (!open.empty() && matching(c) == open.top())
          open.pop();
        else
          return false;
      }
    }

    return open.empty();
  }

 private:
  static bool isOpen(char c) { return c == '(' || c == '{' || c == '['; }

  static bool isClose(char c) { return c == ')' || c == '}' || c == ']'; }

  static char matching(char close) {
    switch (close) {
      case ')':
        return '(';
      case '}':
        return '{';
      case ']':
        return '[';
      default:
        return 0;
    }
  }
};

int main() {
  Solution s;
  test(s.isValid("()"), true);
  test(s.isValid("()[]{}"), true);
  test(s.isValid("(]"), false);
  test(s.isValid("([])"), true);
  test(s.isValid("([)]"), false);
}