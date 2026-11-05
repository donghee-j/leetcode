// 1448. Count Good Nodes in Binary Tree
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

#include <algorithm>
#include <limits>
#include <optional>

#include "leetcode.hpp"

class Solution {
 public:
  int goodNodes(TreeNode* root) {
    return count_good(root, std::numeric_limits<int>::min());
  }

 private:
  static int count_good(TreeNode* node, int path_max) {
    if (node == nullptr) return 0;

    bool is_good = node->val >= path_max;
    int new_max = std::max(node->val, path_max);
    return is_good + count_good(node->left, new_max) +
           count_good(node->right, new_max);
  }
};

int main() {
  Solution s;
  TreeNode* tree1 = make_tree({3, 1, 4, 3, std::nullopt, 1, 5});
  TreeNode* tree2 = make_tree({3, 3, std::nullopt, 4, 2});
  TreeNode* tree3 = make_tree({1});

  test(s.goodNodes(tree1), 4);
  test(s.goodNodes(tree2), 3);
  test(s.goodNodes(tree3), 1);

  for (TreeNode* t : {tree1, tree2, tree3}) free_tree(t);
}