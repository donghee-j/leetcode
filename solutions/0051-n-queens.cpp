// 51. N-Queens
// https://leetcode.com/problems/n-queens/description/

#include <string>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> boards;
    std::vector<std::vector<int>> result;
    std::vector<int> cur;
    cur.reserve(n);

    backtrack(n, cur, result);

    boards.reserve(result.size());
    for (const auto& idx : result) boards.push_back(render(idx));

    return boards;
  }

 private:
  static void backtrack(int n, std::vector<int>& cur,
                        std::vector<std::vector<int>>& result) {
    if (std::ssize(cur) == n) {
      result.push_back(cur);
      return;
    }

    for (int col = 0; col < n; ++col) {
      if (can_place(cur, col)) {
        cur.push_back(col);
        backtrack(n, cur, result);
        cur.pop_back();
      }
    }
  }

  static bool can_place(const std::vector<int>& queens, int col) {
    const int row = std::ssize(queens);
    for (int r = 0; r < row; ++r) {
      const int row_diff = row - r;
      const int col_diff = col - queens[r];
      if (col_diff == 0 || col_diff == row_diff || col_diff == -row_diff)
        return false;
    }
    return true;
  }

  static std::vector<std::string> render(const std::vector<int>& queens) {
    const size_t n = queens.size();
    std::vector<std::string> result;
    result.reserve(n);

    for (int q : queens) {
      result.emplace_back(n, '.');
      result.back()[q] = 'Q';
    }

    return result;
  }
};

int main() {
  Solution s;
  test(s.solveNQueens(1), {{"Q"}});
  test(s.solveNQueens(2), {});
  test(sorted_outer(s.solveNQueens(4)),
       {{"..Q.", "Q...", "...Q", ".Q.."}, {".Q..", "...Q", "Q...", "..Q."}});
}
