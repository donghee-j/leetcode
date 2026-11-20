// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

#include <array>
#include <queue>
#include <utility>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  int numIslands(const std::vector<std::vector<char>>& grid) {
    const int rows = std::ssize(grid);
    const int cols = std::ssize(grid[0]);
    std::vector<std::vector<char>> filled(rows, std::vector<char>(cols, 0));
    int count = 0;

    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (grid[r][c] == '1' && filled[r][c] == 0) {
          ++count;
          flood_fill(r, c, filled, grid);
        }
      }
    }

    return count;
  }

 private:
  static constexpr std::array<std::pair<int, int>, 4> directions{
      {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

  static void flood_fill(int start_r, int start_c,
                         std::vector<std::vector<char>>& filled,
                         const std::vector<std::vector<char>>& grid) {
    const int rows = std::ssize(grid);
    const int cols = std::ssize(grid[0]);

    std::queue<std::pair<int, int>> land;
    filled[start_r][start_c] = 1;
    land.emplace(start_r, start_c);

    while (!land.empty()) {
      const auto [r, c] = land.front();
      land.pop();

      for (const auto& [dr, dc] : directions) {
        const int nr = r + dr;
        const int nc = c + dc;

        if (nr < 0 || nr >= rows) continue;
        if (nc < 0 || nc >= cols) continue;
        if (grid[nr][nc] == '0' || filled[nr][nc] == 1) continue;

        filled[nr][nc] = 1;
        land.emplace(nr, nc);
      }
    }
  }
};

int main() {
  Solution s;
  test(s.numIslands({{'0'}}), 0);
  test(s.numIslands({{'1'}}), 1);
  test(s.numIslands({{'1', '1', '1', '1', '0'},
                     {'1', '1', '0', '1', '0'},
                     {'1', '1', '0', '0', '0'},
                     {'0', '0', '0', '0', '0'}}),
       1);
  test(s.numIslands({{'1', '1', '0', '0', '0'},
                     {'1', '1', '0', '0', '0'},
                     {'0', '0', '1', '0', '0'},
                     {'0', '0', '0', '1', '1'}}),
       3);
}
