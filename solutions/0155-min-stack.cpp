// 155. Min Stack
// https://leetcode.com/problems/min-stack/

#include <algorithm>
#include <stack>

class MinStack {
 public:
  MinStack() = default;

  void push(int value) {
    data_.push(value);
    min_.empty() ? min_.push(value) : min_.push(std::min(min_.top(), value));
  }

  void pop() {
    data_.pop();
    min_.pop();
  }

  int top() const { return data_.top(); }

  int getMin() const { return min_.top(); }

 private:
  std::stack<int> data_;
  std::stack<int> min_;
};