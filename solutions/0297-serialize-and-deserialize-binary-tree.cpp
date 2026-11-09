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
    const std::vector<std::optional<int>> vals = to_vector(root);
    std::string serial;

    for (auto val : vals) {
      if (val.has_value())
        serial.append(std::to_string(val.value()));
      else
        serial.append("null");
      serial.push_back(delimiter);
    }

    return serial;
  }

  TreeNode* deserialize(const std::string& data) const {
    std::vector<std::optional<int>> vals;
    std::stringstream ss(data);
    std::string val;

    while (std::getline(ss, val, delimiter)) {
      if (val != "null")
        vals.push_back(std::stoi(val));
      else
        vals.push_back(std::nullopt);
    }

    return make_tree(vals);
  }

 private:
  const char delimiter = ' ';

  static std::vector<std::optional<int>> to_vector(TreeNode* root) {
    if (root == nullptr) return {};

    std::vector<std::optional<int>> vals;
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();

      if (node != nullptr) {
        vals.push_back(node->val);
        q.push(node->left);
        q.push(node->right);
      } else
        vals.push_back(std::nullopt);
    }

    while (!vals.empty() && !vals.back().has_value()) vals.pop_back();

    return vals;
  }

  static TreeNode* make_tree(const std::vector<std::optional<int>>& vals) {
    if (vals.empty() || !vals[0]) return nullptr;

    auto it = vals.begin();
    auto end = vals.end();

    TreeNode* root = new TreeNode(it->value());
    ++it;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty() && it != end) {
      TreeNode* node = q.front();
      q.pop();

      if (it->has_value()) {
        node->left = new TreeNode(it->value());
        q.push(node->left);
      }
      ++it;

      if (it != end) {
        if (it->has_value()) {
          node->right = new TreeNode(it->value());
          q.push(node->right);
        }
        ++it;
      }
    }

    return root;
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