#pragma once
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <optional>
#include <queue>
#include <type_traits>
#include <utility>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::optional<T>& opt) {
  if (opt.has_value()) return os << *opt;
  return os << "null";
}

// print vector
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  os << "[";
  for (std::size_t i = 0; i < v.size(); ++i) {
    if (i > 0) os << ", ";
    os << v[i];
  }
  os << "]";

  return os;
}

template <typename T>
void test(const T& got, const std::type_identity_t<T>& expected) {
  std::cout << std::boolalpha << "[" << (got == expected ? "PASS" : "FAIL")
            << "] "
            << "expected " << expected << ", "
            << "got " << got << "\n";
}

// sort results when a problem accepts answers in any order
template <typename T>
std::vector<T> sorted(std::vector<T> v) {
  std::ranges::sort(v);
  return v;
}

template <typename T>
std::vector<std::vector<T>> sorted(std::vector<std::vector<T>> v) {
  for (auto& inner : v) inner = sorted(std::move(inner));
  std::ranges::sort(v);
  return v;
}

struct ListNode {
  int val = 0;
  ListNode* next = nullptr;

  ListNode() = default;
  ListNode(int x) : val(x) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* make_list(std::initializer_list<int> vals) {
  ListNode dummy;
  ListNode* tail = &dummy;

  for (int v : vals) {
    tail->next = new ListNode(v);
    tail = tail->next;
  }

  return dummy.next;
}

void free_list(ListNode* head) {
  ListNode* cur = head;

  while (cur != nullptr) {
    ListNode* next = cur->next;
    delete cur;
    cur = next;
  }
}

std::vector<int> to_vector(ListNode* head) {
  std::vector<int> vals;
  ListNode* cur = head;

  while (cur != nullptr) {
    vals.push_back(cur->val);
    cur = cur->next;
  }

  return vals;
}

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

TreeNode* make_tree(std::initializer_list<std::optional<int>> vals) {
  if (vals.size() == 0) return nullptr;

  auto it = vals.begin();
  auto end = vals.end();

  TreeNode* root = new TreeNode(vals.begin()->value());
  ++it;

  std::queue<TreeNode*> q;
  q.push(root);

  while (!q.empty() && it != end) {
    TreeNode* node = q.front();
    q.pop();

    if (it->has_value()) {
      node->left = new TreeNode(**it);
      q.push(node->left);
    }
    ++it;

    if (it != end) {
      if (it->has_value()) {
        node->right = new TreeNode(**it);
        q.push(node->right);
      }
      ++it;
    }
  }

  return root;
}

void free_tree(TreeNode* root) {
  if (root == nullptr) return;

  free_tree(root->left);
  free_tree(root->right);
  delete root;
}

TreeNode* find_node(TreeNode* root, int val) {
  if (root == nullptr) return nullptr;
  if (root->val == val) return root;

  TreeNode* left = find_node(root->left, val);
  return left != nullptr ? left : find_node(root->right, val);
}

std::vector<std::optional<int>> to_vector(TreeNode* root) {
  if (root == nullptr) return {};

  std::vector<std::optional<int>> vals;
  std::queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();

    if (node == nullptr) {
      vals.push_back(std::nullopt);
      continue;
    }

    vals.push_back(node->val);
    q.push(node->left);
    q.push(node->right);
  }

  while (!vals.empty() && !vals.back().has_value()) vals.pop_back();
  return vals;
}
