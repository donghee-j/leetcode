// 297. Serialize and Deserialize Binary Tree
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include <optional>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

#include "leetcode.hpp"

class Codec {
 public:
  std::string serialize(TreeNode* root) const {
    std::ostringstream out;
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();

      if (node == nullptr) {
        out << "null ";
        continue;
      }

      out << node->val << " ";
      q.push(node->left);
      q.push(node->right);
    }

    return out.str();
  }

  TreeNode* deserialize(const std::string& data) const {
    std::istringstream in(data);

    TreeNode* root = read_node(in);
    if (root == nullptr) return nullptr;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();

      node->left = read_node(in);
      if (node->left != nullptr) q.push(node->left);

      node->right = read_node(in);
      if (node->right != nullptr) q.push(node->right);
    }

    return root;
  }

 private:
  static TreeNode* read_node(std::istringstream& in) {
    std::string token;
    if (!(in >> token) || token == "null") return nullptr;
    return new TreeNode(std::stoi(token));
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