// 703. Kth Largest Element in a Stream
// https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <iostream>
#include <queue>
#include <vector>

#include "leetcode.hpp"

class KthLargest {
 public:
  KthLargest(int k, const std::vector<int>& nums) : k_(k) {
    for (int num : nums) add(num);
  }

  int add(int val) {
    largest_.push(val);
    if (std::ssize(largest_) > k_) largest_.pop();

    return largest_.top();
  }

 private:
  int k_;
  std::priority_queue<int, std::vector<int>, std::greater<int>> largest_;
};

int main() {
  KthLargest kth_largest1(3, {4, 5, 8, 2});
  test(kth_largest1.add(3), 4);   // return 4;
  test(kth_largest1.add(5), 5);   // return 5
  test(kth_largest1.add(10), 5);  // return 5
  test(kth_largest1.add(9), 8);   // return 8
  test(kth_largest1.add(4), 8);   // return 8

  std::cout << "\n";
  KthLargest kth_largest2(4, {7, 7, 7, 7, 8, 3});
  test(kth_largest2.add(2), 7);   // return 7
  test(kth_largest2.add(10), 7);  // return 7
  test(kth_largest2.add(9), 7);   // return 7
  test(kth_largest2.add(9), 8);   // return 8
}