// 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <optional>
#include <queue>
#include <utility>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};

    std::vector<std::vector<int>> result;
    std::queue<TreeNode*> level;
    std::queue<TreeNode*> next_level;
    next_level.push(root);

    while (!next_level.empty()) {
      std::vector<int> vals;
      std::swap(level, next_level);

      while (!level.empty()) {
        TreeNode* node = level.front();
        level.pop();

        vals.push_back(node->val);
        if (node->left != nullptr) next_level.push(node->left);
        if (node->right != nullptr) next_level.push(node->right);
      }

      result.push_back(std::move(vals));
    }

    return result;
  }
};

int main() {
  Solution s;
  TreeNode* tree1 = make_tree({3, 9, 20, std::nullopt, std::nullopt, 15, 7});
  TreeNode* tree2 = make_tree({1});
  TreeNode* tree3 = make_tree({});

  test(s.levelOrder(tree1),
       std::vector<std::vector<int>>{{3}, {9, 20}, {15, 7}});
  test(s.levelOrder(tree2), std::vector<std::vector<int>>{{1}});
  test(s.levelOrder(tree3), std::vector<std::vector<int>>{});

  for (TreeNode* t : {tree1, tree2, tree3}) free_tree(t);
}