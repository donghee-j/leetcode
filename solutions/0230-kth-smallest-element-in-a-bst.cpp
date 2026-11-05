// 230. Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include <optional>

#include "leetcode.hpp"

class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    TreeNode* node = nullptr;
    inorder(root, k, count, node);

    return node->val;
  }

 private:
  static void inorder(TreeNode* node, int k, int& count, TreeNode*& result) {
    if (node == nullptr || result != nullptr) return;

    inorder(node->left, k, count, result);
    if (++count == k) {
      result = node;
      return;
    }
    inorder(node->right, k, count, result);
  }
};

int main() {
  Solution s;
  TreeNode* tree1 = make_tree({3, 1, 4, std::nullopt, 2});
  TreeNode* tree2 = make_tree({5, 3, 6, 2, 4, std::nullopt, std::nullopt, 1});

  test(s.kthSmallest(tree1, 1), 1);
  test(s.kthSmallest(tree2, 3), 3);

  free_tree(tree1);
  free_tree(tree2);
}