// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/

#include <optional>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    std::vector<int> vals;
    inorder(root, vals);

    for (int i = 0; i + 1 < static_cast<int>(vals.size()); ++i) {
      if (vals[i] >= vals[i + 1]) return false;
    }

    return true;
  }

 private:
  static void inorder(TreeNode* root, std::vector<int>& vals) {
    if (root == nullptr) return;

    inorder(root->left, vals);
    vals.push_back(root->val);
    inorder(root->right, vals);
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