// 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/

#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    const int rows = static_cast<int>(matrix.size());
    const int cols = static_cast<int>(matrix[0].size());

    int left = 0;
    int right = rows * cols;

    while (left < right) {
      const int mid = left + (right - left) / 2;
      const int row = mid / cols;
      const int col = mid % cols;

      if (matrix[row][col] == target)
        return true;
      else if (matrix[row][col] < target)
        left = mid + 1;
      else
        right = mid;
    }

    return false;
  }
};

int main() {
  Solution s;
  test(s.searchMatrix({{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 3),
       true);
  test(s.searchMatrix({{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 13),
       false);
}