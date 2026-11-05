// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/

#include <optional>

#include "leetcode.hpp"

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    TreeNode* prev = nullptr;
    return inorder(root, prev);
  }

 private:
  static bool inorder(TreeNode* node, TreeNode*& prev) {
    if (node == nullptr) return true;

    if (!inorder(node->left, prev)) return false;
    if (prev != nullptr && prev->val >= node->val) return false;
    prev = node;
    return inorder(node->right, prev);
  }
};

int main() {
  Solution s;
  TreeNode* tree1 = make_tree({2, 1, 3});
  TreeNode* tree2 = make_tree({5, 1, 4, std::nullopt, std::nullopt, 3, 6});

  test(s.isValidBST(tree1), true);
  test(s.isValidBST(tree2), false);

  free_tree(tree1);
  free_tree(tree2);
}