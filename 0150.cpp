// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <stack>
#include <string>
#include <vector>

#include "include/leetcode.hpp"

class Solution {
 public:
  int evalRPN(const std::vector<std::string>& tokens) {
    std::stack<int> rpn;
    for (const std::string& token : tokens) {
      if (isOperator(token)) {
        const int rhs = rpn.top();
        rpn.pop();
        const int lhs = rpn.top();
        rpn.pop();

        int result = operation(lhs, rhs, token);

        rpn.push(result);
      } else {
        rpn.push(std::stoi(token));
      }
    }

    return rpn.top();
  }

 private:
  static bool isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
  }

  static int operation(int lhs, int rhs, const std::string& token) {
    switch (token[0]) {
      case '+':
        return lhs + rhs;
      case '-':
        return lhs - rhs;
      case '*':
        return lhs * rhs;
      case '/':
        return lhs / rhs;
      default:
        return 0;
    }
  }
};

int main() {
  Solution s;
  test(s.evalRPN({"2", "1", "+", "3", "*"}), 9);
  test(s.evalRPN({"4", "13", "5", "/", "+"}), 6);
  test(s.evalRPN({"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+",
                  "5", "+"}),
       22);
}