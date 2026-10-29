#pragma once
#include <initializer_list>
#include <iostream>
#include <vector>

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

// test
template <typename T, typename U>
void test(const T& got, const U& expected) {
  std::cout << std::boolalpha << "[" << (got == expected ? "PASS" : "FAIL")
            << "] "
            << "expected " << expected << ", "
            << "got " << got << "\n";
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