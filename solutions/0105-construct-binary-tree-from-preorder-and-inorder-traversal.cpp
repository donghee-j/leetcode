// 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <optional>
#include <unordered_map>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  TreeNode* buildTree(const std::vector<int>& preorder,
                      const std::vector<int>& inorder) {
    const int n = static_cast<int>(preorder.size());
    std::unordered_map<int, int> inorder_map;
    for (int i = 0; i < n; ++i) inorder_map[inorder[i]] = i;

    int pre = 0;
    return build(preorder, inorder_map, pre, 0, n);
  }

 private:
  static TreeNode* build(const std::vector<int>& preorder,
                         const std::unordered_map<int, int>& inorder_map,
                         int& pre, int start, int end) {
    // range [start, end)
    if (start >= end) return nullptr;

    TreeNode* node = new TreeNode(preorder[pre]);
    const int mid = inorder_map.at(node->val);
    ++pre;

    node->left = build(preorder, inorder_map, pre, start, mid);
    node->right = build(preorder, inorder_map, pre, mid + 1, end);

    return node;
  }
};

int main() {
  Solution s;
  TreeNode* tree1 = s.buildTree({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7});
  TreeNode* tree2 = s.buildTree({-1}, {-1});

  test(to_vector(tree1), {3, 9, 20, std::nullopt, std::nullopt, 15, 7});
  test(to_vector(tree2), {-1});

  free_tree(tree1);
  free_tree(tree2);
}