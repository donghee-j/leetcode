// 572. Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree/

#include <optional>

#include "leetcode.hpp"

class Solution {
 public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr) return false;

    return is_same_tree(root, subRoot) || isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
  }

 private:
  bool is_same_tree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;

    return (p->val == q->val) && is_same_tree(p->left, q->left) &&
           is_same_tree(p->right, q->right);
  }
};

int main() {
  Solution s;
  TreeNode* root1 = make_tree({3, 4, 5, 1, 2});
  TreeNode* sub1 = make_tree({4, 1, 2});
  TreeNode* root2 = make_tree({3, 4, 5, 1, 2, std::nullopt, std::nullopt,
                               std::nullopt, std::nullopt, 0});
  TreeNode* sub2 = make_tree({4, 1, 2});

  test(s.isSubtree(root1, sub1), true);
  test(s.isSubtree(root2, sub2), false);

  for (TreeNode* t : {root1, sub1, root2, sub2}) free_tree(t);
}