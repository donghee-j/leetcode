// 104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <algorithm>
#include <optional>

#include "leetcode.hpp"

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

int main() {
  Solution s;
  TreeNode* tree1 = make_tree({3, 9, 20, std::nullopt, std::nullopt, 15, 7});
  TreeNode* tree2 = make_tree({1, std::nullopt, 2});

  test(s.maxDepth(tree1), 3);
  test(s.maxDepth(tree2), 2);

  free_tree(tree1);
  free_tree(tree2);
}