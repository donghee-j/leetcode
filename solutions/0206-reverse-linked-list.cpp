// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

#include "leetcode.hpp"

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
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
};

int main() {
  Solution s;
  ListNode* list1 = make_list({1, 2, 3, 4, 5});
  ListNode* list2 = make_list({1, 2});
  ListNode* list3 = make_list({});

  test(to_vector(s.reverseList(list1)), std::vector<int>{5, 4, 3, 2, 1});
  test(to_vector(s.reverseList(list2)), std::vector<int>{2, 1});
  test(to_vector(s.reverseList(list3)), std::vector<int>{});

  free_list(list1);
  free_list(list2);
  free_list(list3);
}