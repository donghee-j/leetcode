// 994. Rotting Oranges
// leetcode.com/problems/rotting-oranges/

#include <array>
#include <queue>
#include <utility>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  int orangesRotting(const std::vector<std::vector<int>>& grid) {
    const int rows = std::ssize(grid);
    const int cols = std::ssize(grid[0]);
    std::vector<std::vector<int>> oranges(grid);

    int fresh_count = 0;
    std::queue<std::pair<int, int>> level;
    std::queue<std::pair<int, int>> next_level;
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (oranges[r][c] == fresh)
          ++fresh_count;
        else if (oranges[r][c] == rotten)
          next_level.emplace(r, c);
      }
    }

    int time = 0;
    while (fresh_count > 0 && !next_level.empty()) {
      std::swap(level, next_level);

      while (!level.empty()) {
        const auto [r, c] = level.front();
        level.pop();

        for (auto& [dr, dc] : directions) {
          const int nr = r + dr;
          const int nc = c + dc;
          if (nr < 0 || nr >= rows) continue;
          if (nc < 0 || nc >= cols) continue;
          if (oranges[nr][nc] != fresh) continue;

          oranges[nr][nc] = rotten;
          --fresh_count;
          next_level.emplace(nr, nc);
        }
      }
      ++time;
    }

    return fresh_count > 0 ? -1 : time;
  }

 private:
  static constexpr int fresh = 1;
  static constexpr int rotten = 2;
  static constexpr std::array<std::pair<int, int>, 4> directions{
      {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
};

int main() {
  Solution s;
  test(s.orangesRotting({{0, 2}}), 0);
  test(s.orangesRotting({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}), 4);
  test(s.orangesRotting({{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}), -1);
}
