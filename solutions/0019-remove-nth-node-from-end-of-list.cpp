// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0, head);
    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    for (int i = 0; i < n + 1; ++i) fast = fast->next;

    while (fast != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }
    // Now slow points (n+1)th node from end of the list

    ListNode* target = slow->next;
    slow->next = target->next;
    delete target;

    return dummy.next;
  }
};

int main() {
  Solution s;
  ListNode* list1 = make_list({1, 2, 3, 4, 5});
  ListNode* list2 = make_list({1});
  ListNode* list3 = make_list({1, 2});

  ListNode* removed1 = s.removeNthFromEnd(list1, 2);
  ListNode* removed2 = s.removeNthFromEnd(list2, 1);
  ListNode* removed3 = s.removeNthFromEnd(list3, 1);

  test(to_vector(removed1), {1, 2, 3, 5});
  test(to_vector(removed2), {});
  test(to_vector(removed3), {1});

  free_list(removed1);
  free_list(removed2);
  free_list(removed3);
}