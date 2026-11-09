// 297. Serialize and Deserialize Binary Tree
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "leetcode.hpp"

class Codec {
 public:
  std::string serialize(TreeNode* root) const {
    std::ostringstream out;
    dfs(root, out);

    return out.str();
  }

  TreeNode* deserialize(const std::string& data) const {
    std::istringstream in(data);
    return build(in);
  }

 private:
  static void dfs(TreeNode* node, std::ostringstream& out) {
    if (node == nullptr) {
      out << "null ";
      return;
    }

    out << node->val << " ";

    dfs(node->left, out);
    dfs(node->right, out);
  }

  static TreeNode* build(std::istringstream& in) {
    std::string token;
    if (!(in >> token) || token == "null") return nullptr;

    TreeNode* node = new TreeNode(std::stoi(token));

    node->left = build(in);
    node->right = build(in);

    return node;
  }
};

int main() {
  Codec c;
  TreeNode* tree1 = make_tree({1, 2, 3, std::nullopt, std::nullopt, 4, 5});
  TreeNode* result1 = c.deserialize(c.serialize(tree1));
  TreeNode* tree2 = make_tree({});
  TreeNode* result2 = c.deserialize(c.serialize(tree2));
  TreeNode* tree3 = make_tree({1, 2});
  TreeNode* result3 = c.deserialize(c.serialize(tree3));

  test(to_vector(result1), {1, 2, 3, std::nullopt, std::nullopt, 4, 5});
  test(to_vector(result2), {});
  test(to_vector(result3), {1, 2});

  for (TreeNode* t : {tree1, result1, tree2, result2, tree3, result3})
    free_tree(t);
}