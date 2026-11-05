// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/

#include <optional>
#include <queue>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<int> rightSideView(TreeNode* root) {
    if (root == nullptr) return {};

    std::vector<int> vals;
    std::queue<TreeNode*> level;
    std::queue<TreeNode*> next_level;
    next_level.push(root);

    while (!next_level.empty()) {
      std::swap(level, next_level);
      vals.push_back(level.back()->val);

      while (!level.empty()) {
        TreeNode* node = level.front();
        level.pop();

        if (node->left != nullptr) next_level.push(node->left);
        if (node->right != nullptr) next_level.push(node->right);
      }
    }

    return vals;
  }
};

int main() {
  Solution s;
  TreeNode* tree1 = make_tree({1, 2, 3, std::nullopt, 5, std::nullopt, 4});
  TreeNode* tree2 =
      make_tree({1, 2, 3, 4, std::nullopt, std::nullopt, std::nullopt, 5});
  TreeNode* tree3 = make_tree({1, std::nullopt, 3});
  TreeNode* tree4 = make_tree({});

  test(s.rightSideView(tree1), {1, 3, 4});
  test(s.rightSideView(tree2), {1, 3, 4, 5});
  test(s.rightSideView(tree3), {1, 3});
  test(s.rightSideView(tree4), {});

  for (TreeNode* t : {tree1, tree2, tree3, tree4}) free_tree(t);
}