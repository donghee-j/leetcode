// 79. Word Search
// https://leetcode.com/problems/word-search/

#include <array>
#include <string>
#include <utility>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  bool exist(const std::vector<std::vector<char>>& board,
             const std::string& word) {
    std::vector<std::vector<char>> visited(board.size(),
                                           std::vector<char>(board[0].size()));

    for (int r = 0; r < std::ssize(board); ++r) {
      for (int c = 0; c < std::ssize(board[0]); ++c) {
        if (backtrack(board, visited, r, c, 0, word)) return true;
      }
    }

    return false;
  }

 private:
  static constexpr std::array<std::pair<int, int>, 4> directions{
      {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
  static bool backtrack(const std::vector<std::vector<char>>& board,
                        std::vector<std::vector<char>>& visited, int r, int c,
                        int i, const std::string& word) {
    if (i == std::ssize(word)) return true;

    if (r < 0 || r >= std::ssize(board)) return false;
    if (c < 0 || c >= std::ssize(board[0])) return false;
    if (visited[r][c] != '\0' || board[r][c] != word[i]) return false;

    visited[r][c] = '1';
    bool found = false;
    for (const auto& [dr, dc] : directions) {
      found = backtrack(board, visited, r + dr, c + dc, i + 1, word);
      if (found) break;
    }
    visited[r][c] = '\0';

    return found;
  }
};

int main() {
  Solution s;
  const std::vector<std::vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  test(s.exist(board, "ABCE"), true);
  test(s.exist(board, "ABCCED"), true);
  test(s.exist(board, "SEE"), true);
  test(s.exist(board, "ABCB"), false);
}
