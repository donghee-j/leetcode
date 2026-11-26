// 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/

#include <array>
#include <queue>
#include <utility>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  void solve(std::vector<std::vector<char>>& board) {
    const int rows = static_cast<int>(board.size());
    const int cols = static_cast<int>(board[0].size());
    const int top = 0;
    const int bottom = rows - 1;
    const int left = 0;
    const int right = cols - 1;

    std::queue<std::pair<int, int>> q;
    auto add_to_queue = [&](int r, int c) {
      if (board[r][c] == 'O') {
        board[r][c] = '#';
        q.emplace(r, c);
      }
    };
    for (int c = 0; c < cols; ++c) {
      add_to_queue(top, c);
      add_to_queue(bottom, c);
    }
    for (int r = top + 1; r < bottom; ++r) {
      add_to_queue(r, left);
      add_to_queue(r, right);
    }

    while (!q.empty()) {
      const auto [r, c] = q.front();
      q.pop();

      for (const auto& [dr, dc] : directions) {
        const int nr = r + dr;
        const int nc = c + dc;

        if (nr < 0 || nr >= rows) continue;
        if (nc < 0 || nc >= cols) continue;
        if (board[nr][nc] != 'O') continue;

        board[nr][nc] = '#';
        q.emplace(nr, nc);
      }
    }

    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (board[r][c] == 'O')
          board[r][c] = 'X';
        else if (board[r][c] == '#')
          board[r][c] = 'O';
      }
    }
  }

 private:
  static constexpr std::array<std::pair<int, int>, 4> directions{
      {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
};

int main() {
  Solution s;

  std::vector<std::vector<char>> board1 = {{'X'}};
  s.solve(board1);
  test(board1, {{'X'}});

  std::vector<std::vector<char>> board2 = {{'O'}};
  s.solve(board2);
  test(board2, {{'O'}});

  std::vector<std::vector<char>> board3 = {{'X', 'X', 'X', 'X'},
                                           {'X', 'O', 'O', 'X'},
                                           {'X', 'X', 'O', 'X'},
                                           {'X', 'O', 'X', 'X'}};
  s.solve(board3);
  test(board3, {{'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X'},
                {'X', 'X', 'X', 'X'},
                {'X', 'O', 'X', 'X'}});
}
