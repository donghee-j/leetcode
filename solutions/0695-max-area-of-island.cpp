// 695. Max Area of Island
// https://leetcode.com/problems/max-area-of-island/

#include <algorithm>
#include <array>
#include <utility>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  int maxAreaOfIsland(const std::vector<std::vector<int>>& grid) {
    const int rows = std::ssize(grid);
    const int cols = std::ssize(grid[0]);
    int best = 0;
    std::vector<std::vector<char>> visited(rows, std::vector<char>(cols, 0));

    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (grid[r][c] == 1 && visited[r][c] == 0)
          best = std::max(best, flood_fill(grid, visited, r, c));
      }
    }

    return best;
  }

 private:
  static constexpr std::array<std::pair<int, int>, 4> directions{
      {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

  static int flood_fill(const std::vector<std::vector<int>>& grid,
                        std::vector<std::vector<char>>& visited, int r, int c) {
    if (r < 0 || r >= std::ssize(grid)) return 0;
    if (c < 0 || c >= std::ssize(grid[0])) return 0;
    if (grid[r][c] == 0 || visited[r][c] != 0) return 0;

    visited[r][c] = 1;
    int area = 1;
    for (const auto& [dr, dc] : directions)
      area += flood_fill(grid, visited, r + dr, c + dc);

    return area;
  }
};

int main() {
  Solution s;
  test(s.maxAreaOfIsland({{0, 0, 0, 0, 0, 0, 0, 0}}), 0);
  test(s.maxAreaOfIsland({{0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}}),
       3);
  test(s.maxAreaOfIsland({{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                          {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                          {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}}),
       6);
}
