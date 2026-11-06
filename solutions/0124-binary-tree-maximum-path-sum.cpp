// 124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include <algorithm>
#include <limits>

#include "leetcode.hpp"

class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    int best = std::numeric_limits<int>::min();
    gain(root, best);

    return best;
  }

 private:
  static int gain(TreeNode* node, int& best) {
    if (node == nullptr) return 0;

    const int left = std::max(gain(node->left, best), 0);
    const int right = std::max(gain(node->right, best), 0);

    best = std::max(best, node->val + left + right);

    return node->val + std::max(left, right);
  }
};

int main() {
  Solution s;
  TreeNode* tree1 = make_tree({1, 2, 3});
  TreeNode* tree2 = make_tree({-10, 9, 20, std::nullopt, std::nullopt, 15, 7});
  TreeNode* tree3 = make_tree({100, 10, 2, 3, 9, std::nullopt, std::nullopt});
  TreeNode* tree4 = make_tree({-1});

  test(s.maxPathSum(tree1), 6);
  test(s.maxPathSum(tree2), 42);
  test(s.maxPathSum(tree3), 121);
  test(s.maxPathSum(tree4), -1);

  for (TreeNode* t : {tree1, tree2, tree3, tree4}) free_tree(t);
}