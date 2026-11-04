// 235. Lowest Common Ancestor of a Binary Search
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include <algorithm>
#include <optional>

#include "leetcode.hpp"

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;

    const int val = root->val;
    const int a = std::min(p->val, q->val);
    const int b = std::max(p->val, q->val);

    if (b < val) return lowestCommonAncestor(root->left, p, q);
    if (a > val) return lowestCommonAncestor(root->right, p, q);

    return root;
  }
};

int main() {
  Solution s;
  TreeNode* tree1 =
      make_tree({6, 2, 8, 0, 4, 7, 9, std::nullopt, std::nullopt, 3, 5});
  TreeNode* tree2 = make_tree({2, 1});

  TreeNode* p1 = find_node(tree1, 2);
  TreeNode* q1 = find_node(tree1, 8);
  TreeNode* q2 = find_node(tree1, 4);
  TreeNode* p3 = find_node(tree2, 2);
  TreeNode* q3 = find_node(tree2, 1);

  test(s.lowestCommonAncestor(tree1, p1, q1)->val, 6);
  test(s.lowestCommonAncestor(tree1, p1, q2)->val, 2);
  test(s.lowestCommonAncestor(tree2, p3, q3)->val, 2);

  free_tree(tree1);
  free_tree(tree2);
}