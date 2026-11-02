// 25. Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/

#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0, head);
    ListNode* group_dummy = &dummy;

    while (true) {
      ListNode* kth = group_dummy;
      for (int i = 0; i < k && kth != nullptr; ++i) kth = kth->next;
      if (kth == nullptr) break;

      ListNode* next_group_dummy = group_dummy->next;
      reverse_group(group_dummy, kth->next);

      group_dummy = next_group_dummy;
    }

    return dummy.next;
  }

 private:
  void reverse_group(ListNode* dummy_head, ListNode* dummy_tail) {
    // dummy_head - ... k nodes to reverse ... - dummy_tail
    ListNode* cur = dummy_head->next;
    ListNode* prev = dummy_tail;

    while (cur != dummy_tail) {
      ListNode* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    dummy_head->next = prev;
  }
};

int main() {
  Solution s;
  ListNode* reversed1 = s.reverseKGroup(make_list({1, 2, 3, 4, 5}), 2);
  ListNode* reversed2 = s.reverseKGroup(make_list({1, 2, 3, 4, 5}), 3);

  test(to_vector(reversed1), std::vector<int>{2, 1, 4, 3, 5});
  test(to_vector(reversed2), std::vector<int>{3, 2, 1, 4, 5});

  free_list(reversed1);
  free_list(reversed2);
}