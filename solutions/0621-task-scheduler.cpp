// 621. Task Scheduler
// https://leetcode.com/problems/task-scheduler/

#include <array>
#include <queue>
#include <utility>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  int leastInterval(const std::vector<char>& tasks, int n) {
    int time = 0;
    std::queue<std::pair<int, int>> cooling;  // remaining, ready_time
    std::priority_queue<int> available;       // remaining

    std::array<int, 26> freq{};
    for (char t : tasks) ++freq[t - 'A'];
    for (int c : freq) {
      if (c > 0) available.push(c);
    }

    while (true) {
      while (!cooling.empty() && cooling.front().second <= time) {
        available.push(cooling.front().first);
        cooling.pop();
      }

      if (available.empty() && cooling.empty()) break;

      if (available.empty())
        time = cooling.front().second;
      else {
        int remaining = available.top() - 1;
        if (remaining > 0) cooling.emplace(remaining, time + n + 1);
        available.pop();
        ++time;
      }
    }

    return time;
  }
};

int main() {
  Solution s;
  test(s.leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 2), 8);
  test(s.leastInterval({'A', 'C', 'A', 'B', 'D', 'B'}, 1), 6);
  test(s.leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 3), 10);
}