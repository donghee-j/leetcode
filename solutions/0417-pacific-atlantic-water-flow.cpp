// 417. Pacific Atlantic Water Flow
// https://leetcode.com/problems/pacific-atlantic-water-flow/

#include <array>
#include <utility>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<int>> pacificAtlantic(
      const std::vector<std::vector<int>>& heights) {
    const int rows = static_cast<int>(heights.size());
    const int cols = static_cast<int>(heights[0].size());

    const int top = 0;
    const int bottom = rows - 1;
    const int left = 0;
    const int right = cols - 1;
    std::vector<std::vector<char>> pacific(rows, std::vector<char>(cols, 0));
    std::vector<std::vector<char>> atlantic(rows, std::vector<char>(cols, 0));
    for (int c = 0; c < cols; ++c) {
      dfs(heights, pacific, top, c);
      dfs(heights, atlantic, bottom, c);
    }
    for (int r = 0; r < rows; ++r) {
      dfs(heights, pacific, r, left);
      dfs(heights, atlantic, r, right);
    }

    std::vector<std::vector<int>> result;
    result.reserve(rows * cols);
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (pacific[r][c] && atlantic[r][c]) result.push_back({r, c});
      }
    }

    return result;
  }

 private:
  static constexpr std::array<std::pair<int, int>, 4> directions{
      {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

  static void dfs(const std::vector<std::vector<int>>& heights,

                  std::vector<std::vector<char>>& reachable, int r, int c) {
    if (reachable[r][c] != 0) return;
    reachable[r][c] = 1;

    for (auto& [dr, dc] : directions) {
      const int nr = r + dr;
      const int nc = c + dc;

      if (nr < 0 || nr >= std::ssize(heights)) continue;
      if (nc < 0 || nc >= std::ssize(heights[0])) continue;
      if (heights[nr][nc] < heights[r][c]) continue;

      dfs(heights, reachable, nr, nc);
    }
  }
};

int main() {
  Solution s;
  test(s.pacificAtlantic({{1}}), {{0, 0}});
  test(sorted_outer(s.pacificAtlantic({{1, 2, 2, 3, 5},
                                       {3, 2, 3, 4, 4},
                                       {2, 4, 5, 3, 1},
                                       {6, 7, 1, 4, 5},
                                       {5, 1, 1, 2, 4}})),
       {{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}});
}
