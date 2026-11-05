// 146. LRU Cache
// https://leetcode.com/problems/lru-cache/

#include <iostream>
#include <unordered_map>

struct Node {
 public:
  int key = 0;
  int val = 0;
  Node* prev = nullptr;
  Node* next = nullptr;

  Node() = default;
  Node(int key, int val) : key(key), val(val) {}
};

class LRUCache {
 public:
  LRUCache(int capacity) : capacity_(capacity) {
    dummy_head_.next = &dummy_tail_;
    dummy_tail_.prev = &dummy_head_;
  }

  LRUCache(const LRUCache& cache) = delete;
  LRUCache& operator=(const LRUCache&) = delete;

  ~LRUCache() {
    Node* cur = dummy_head_.next;
    while (cur != &dummy_tail_) {
      Node* next = cur->next;
      delete cur;
      cur = next;
    }
  }

  int get(int key) {
    auto it = cache_map_.find(key);
    if (it == cache_map_.end()) return -1;

    Node* node = it->second;
    move_to_tail(node);
    return node->val;
  }

  void put(int key, int value) {
    auto it = cache_map_.find(key);
    if (it == cache_map_.end()) {
      Node* node = new Node(key, value);
      append_to_tail(node);
      cache_map_[key] = node;

      if (static_cast<int>(cache_map_.size()) > capacity_) {
        Node* lru = dummy_head_.next;
        cache_map_.erase(lru->key);
        detach(lru);
        delete lru;
      }
    } else {
      Node* node = it->second;
      node->val = value;
      move_to_tail(node);
    }
  }

 private:
  const int capacity_;
  Node dummy_head_, dummy_tail_;
  std::unordered_map<int, Node*> cache_map_;

  void detach(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void append_to_tail(Node* node) {
    Node* tail = dummy_tail_.prev;
    tail->next = node;
    node->prev = tail;
    node->next = &dummy_tail_;
    dummy_tail_.prev = node;
  }

  void move_to_tail(Node* node) {
    detach(node);
    append_to_tail(node);
  }
};

int main() {
  LRUCache lRUCache(2);
  lRUCache.put(1, 1);                    // cache is {1=1}
  lRUCache.put(2, 2);                    // cache is {1=1, 2=2}
  std::cout << lRUCache.get(1) << "\n";  // return 1
  lRUCache.put(3, 3);  // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  std::cout << lRUCache.get(2) << "\n";  // returns -1 (not found)
  lRUCache.put(4, 4);  // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  std::cout << lRUCache.get(1) << "\n";  // return -1 (not found)
  std::cout << lRUCache.get(3) << "\n";  // return 3
  std::cout << lRUCache.get(4) << "\n";  // return 4
}