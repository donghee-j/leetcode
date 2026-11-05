// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/
#include <utility>

#include "leetcode.hpp"

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return root;

    std::swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);

    return root;
  }
};

int main() {
  Solution s;
  TreeNode* tree1 = s.invertTree(make_tree({4, 2, 7, 1, 3, 6, 9}));
  TreeNode* tree2 = s.invertTree(make_tree({2, 1, 3}));
  TreeNode* tree3 = s.invertTree(make_tree({}));

  test(to_vector(tree1), std::vector<std::optional<int>>{4, 7, 2, 9, 6, 3, 1});
  test(to_vector(tree2), std::vector<std::optional<int>>{2, 3, 1});
  test(to_vector(tree3), std::vector<std::optional<int>>{});

  free_tree(tree1);
  free_tree(tree2);
  free_tree(tree3);
}