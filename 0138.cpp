// 138. Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/

#include <unordered_map>
#include <vector>

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    std::unordered_map<Node*, Node*> old_to_new;
    Node dummy(0);
    Node* cur = &dummy;
    Node* n = head;

    while (n != nullptr) {
      Node* new_node = new Node(n->val);
      new_node->random = n->random;

      cur->next = new_node;
      old_to_new[n] = new_node;

      cur = new_node;
      n = n->next;
    }

    cur = dummy.next;
    while (cur != nullptr) {
      cur->random = cur->random != nullptr ? old_to_new[cur->random] : nullptr;
      cur = cur->next;
    }

    return dummy.next;
  }
};

int main() {}