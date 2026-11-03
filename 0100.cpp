// 100. Same Tree
// https://leetcode.com/problems/same-tree/

#include <optional>

#include "leetcode.hpp"

class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;

    return (p->val == q->val) && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
  }
};

int main() {
  Solution s;
  TreeNode* p1 = make_tree({1, 2, 3});
  TreeNode* q1 = make_tree({1, 2, 3});
  TreeNode* p2 = make_tree({1, 2});
  TreeNode* q2 = make_tree({1, std::nullopt, 2});
  TreeNode* p3 = make_tree({1, 2, 1});
  TreeNode* q3 = make_tree({1, 1, 2});

  test(s.isSameTree(p1, q1), true);
  test(s.isSameTree(p2, q2), false);
  test(s.isSameTree(p3, q3), false);

  for (TreeNode* t : {p1, q1, p2, q2, p3, q3}) free_tree(t);
}