// 133. Clone Graph
// https://leetcode.com/problems/clone-graph/

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "leetcode.hpp"

class Node {
 public:
  int val;
  std::vector<Node*> neighbors;

  Node() : val(0) {}
  explicit Node(int v) : val(v) {}
  Node(int v, std::vector<Node*> nbs) : val(v), neighbors(std::move(nbs)) {}
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;

    std::unordered_map<Node*, Node*> clone;
    clone[node] = new Node(node->val);

    std::queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
      Node* cur = q.front();
      q.pop();

      Node* cur_copy = clone[cur];
      cur_copy->neighbors.reserve(cur->neighbors.size());
      for (Node* nb : cur->neighbors) {
        auto it = clone.find(nb);
        if (it == clone.end()) {
          it = clone.emplace(nb, new Node(nb->val)).first;
          q.push(nb);
        };
        cur_copy->neighbors.push_back(it->second);
      }
    }

    return clone.at(node);
  }
};

class ConnectedGraph {
 public:
  ConnectedGraph() = default;
  explicit ConnectedGraph(Node* _node) : node(_node) {}
  explicit ConnectedGraph(const std::vector<std::vector<int>>& adj_list) {
    if (adj_list.empty()) {
      node = nullptr;
      return;
    }

    const int m = std::ssize(adj_list);
    std::vector<Node*> nodes;
    nodes.reserve(m);
    for (int i = 1; i <= m; ++i) {
      Node* n = new Node(i);
      nodes.push_back(n);
    }

    for (int i = 0; i < m; ++i) {
      const auto& list = adj_list[i];
      Node* n = nodes[i];
      n->neighbors.reserve(list.size());
      for (int adj : list) n->neighbors.push_back(nodes[adj - 1]);
    }

    node = nodes[0];
  }

  ConnectedGraph(const ConnectedGraph&) = delete;
  ConnectedGraph(ConnectedGraph&&) = delete;
  ConnectedGraph& operator=(const ConnectedGraph&) = delete;
  ConnectedGraph& operator=(ConnectedGraph&&) = delete;

  ~ConnectedGraph() {
    std::unordered_set<Node*> nodes = get_nodes();
    for (Node* n : nodes) delete n;
  }

  Node* node = nullptr;

 private:
  std::unordered_set<Node*> get_nodes() const {
    if (node == nullptr) return {};

    std::unordered_set<Node*> visited{node};
    std::queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
      Node* cur = q.front();
      q.pop();

      for (Node* n : cur->neighbors) {
        if (visited.insert(n).second) q.push(n);
      }
    }

    return visited;
  }
};

bool is_deep_copy(const ConnectedGraph& original, const ConnectedGraph& copy) {
  if (original.node == nullptr) return copy.node == nullptr;
  if (copy.node == nullptr) return false;

  std::unordered_map<Node*, Node*> pairs;
  std::queue<std::pair<Node*, Node*>> q;
  pairs.emplace(original.node, copy.node);
  q.emplace(original.node, copy.node);

  while (!q.empty()) {
    const auto [o, c] = q.front();
    q.pop();

    if (o == c) return false;
    if (o->val != c->val) return false;
    if (o->neighbors.size() != c->neighbors.size()) return false;

    for (int i = 0; i < std::ssize(o->neighbors); ++i) {
      Node* on = o->neighbors[i];
      Node* cn = c->neighbors[i];

      auto [it, inserted] = pairs.emplace(on, cn);
      if (inserted) {
        q.emplace(on, cn);
      } else if (it->second != cn)
        return false;
    }
  }

  return true;
}

int main() {
  Solution s;

  ConnectedGraph g1({{2, 4}, {1, 3}, {2, 4}, {1, 3}});
  ConnectedGraph c1(s.cloneGraph(g1.node));
  test(is_deep_copy(g1, c1), true);

  ConnectedGraph g2({{}});
  ConnectedGraph c2(s.cloneGraph(g2.node));
  test(is_deep_copy(g2, c2), true);

  ConnectedGraph g3(nullptr);
  ConnectedGraph c3(s.cloneGraph(g3.node));
  test(is_deep_copy(g3, c3), true);
}
