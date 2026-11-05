// 143. Reorder List
// https://leetcode.com/problems/reorder-list/

#include "leetcode.hpp"

class Solution {
 public:
  void reorderList(ListNode* head) {
    ListNode* new_tail = find_new_tail(head);
    ListNode* list2 = new_tail->next;
    new_tail->next = nullptr;

    merge(head, reverse(list2));
  }

 private:
  ListNode* find_new_tail(ListNode* head) {
    // (size / 2)th node is always tail
    int size = 0;
    ListNode* cur = head;
    ListNode* tail = head;

    while (cur != nullptr) {
      ++size;
      cur = cur->next;
    }

    for (int i = 0; i < size / 2; ++i) {
      tail = tail->next;
    }

    return tail;
  }

  ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;

    while (cur != nullptr) {
      ListNode* next = cur->next;
      cur->next = prev;

      prev = cur;
      cur = next;
    }

    return prev;
  }

  void merge(ListNode* list1, ListNode* list2) {
    // list 2 is shorter than list 1
    ListNode* cur1 = list1;
    ListNode* cur2 = list2;

    while (cur2 != nullptr) {
      ListNode* next1 = cur1->next;
      ListNode* next2 = cur2->next;

      cur1->next = cur2;
      cur2->next = next1;

      cur1 = next1;
      cur2 = next2;
    }
  }
};

int main() {
  Solution s;
  ListNode* list1 = make_list({1, 2, 3, 4});
  ListNode* list2 = make_list({1, 2, 3, 4, 5});

  s.reorderList(list1);
  s.reorderList(list2);

  test(to_vector(list1), std::vector<int>{1, 4, 2, 3});
  test(to_vector(list2), std::vector<int>{1, 5, 2, 4, 3});

  free_list(list1);
  free_list(list2);
}