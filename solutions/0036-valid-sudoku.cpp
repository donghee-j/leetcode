// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

#include <array>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  bool isValidSudoku(const std::vector<std::vector<char>>& board) {
    std::array<std::array<bool, 9>, 9> row_check{};
    std::array<std::array<bool, 9>, 9> col_check{};
    std::array<std::array<bool, 9>, 9> box_check{};

    for (int row = 0; row < 9; ++row) {
      for (int col = 0; col < 9; ++col) {
        if (board[row][col] == '.') continue;

        const int num = board[row][col] - '1';
        const int box = (row / 3) * 3 + (col / 3);

        if (row_check[row][num] || col_check[col][num] || box_check[box][num])
          return false;

        row_check[row][num] = true;
        col_check[col][num] = true;
        box_check[box][num] = true;
      }
    }

    return true;
  }
};

int main() {
  Solution s;
  test(s.isValidSudoku({{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}),
       true);
  test(s.isValidSudoku({{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}),
       false);
}