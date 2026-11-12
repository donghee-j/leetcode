// 295. Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/

#include <queue>
#include <vector>

#include "leetcode.hpp"

class MedianFinder {
 public:
  MedianFinder() = default;

  void addNum(int num) {
    if (front_.empty() || num > front_.top())
      back_.push(num);
    else
      front_.push(num);

    const size_t m = front_.size();
    const size_t n = m + back_.size();

    if (m < n / 2) {
      front_.push(back_.top());
      back_.pop();
    } else if (m > n / 2) {
      back_.push(front_.top());
      front_.pop();
    }
  }

  double findMedian() const {
    const size_t n = front_.size() + back_.size();

    if (n % 2 == 1)
      return back_.top();
    else
      return (static_cast<double>(front_.top()) + back_.top()) / 2.0;
  }

 private:
  std::priority_queue<int> front_;
  std::priority_queue<int, std::vector<int>, std::greater<int>> back_;
};

int main() {
  MedianFinder mf;
  mf.addNum(1);
  test(mf.findMedian(), 1.0);
  mf.addNum(2);
  test(mf.findMedian(), 1.5);
  mf.addNum(3);
  test(mf.findMedian(), 2.0);
  mf.addNum(4);
  test(mf.findMedian(), 2.5);
  mf.addNum(0);
  test(mf.findMedian(), 2);
}