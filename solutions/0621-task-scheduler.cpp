// 621. Task Scheduler
// https://leetcode.com/problems/task-scheduler/

#include <algorithm>
#include <array>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  int leastInterval(const std::vector<char>& tasks, int n) {
    std::array<int, 26> freq{};
    for (char c : tasks) ++freq[c - 'A'];

    const int max_count = std::ranges::max(freq);
    const int count_of_max =
        static_cast<int>(std::ranges::count(freq, max_count));

    return std::max(static_cast<int>(tasks.size()),
                    (max_count - 1) * (n + 1) + count_of_max);
  }
};

int main() {
  Solution s;
  test(s.leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 2), 8);
  test(s.leastInterval({'A', 'C', 'A', 'B', 'D', 'B'}, 1), 6);
  test(s.leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 3), 10);
}