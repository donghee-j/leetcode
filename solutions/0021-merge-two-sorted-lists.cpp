// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

#include "leetcode.hpp"

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy;
    ListNode* tail = &dummy;
    ListNode* cur1 = list1;
    ListNode* cur2 = list2;

    while (cur1 != nullptr && cur2 != nullptr) {
      if (cur1->val <= cur2->val) {
        tail->next = cur1;
        tail = tail->next;
        cur1 = cur1->next;
      } else {
        tail->next = cur2;
        tail = tail->next;
        cur2 = cur2->next;
      }
    }

    if (cur1 == nullptr) {
      tail->next = cur2;
    }

    if (cur2 == nullptr) {
      tail->next = cur1;
    }

    return dummy.next;
  }
};

int main() {
  Solution s;

  ListNode* list1_1 = make_list({1, 2, 4});
  ListNode* list1_2 = make_list({1, 3, 4});
  ListNode* merged1 = s.mergeTwoLists(list1_1, list1_2);

  ListNode* list2_1 = make_list({});
  ListNode* list2_2 = make_list({});
  ListNode* merged2 = s.mergeTwoLists(list2_1, list2_2);

  ListNode* list3_1 = make_list({});
  ListNode* list3_2 = make_list({0});
  ListNode* merged3 = s.mergeTwoLists(list3_1, list3_2);

  test(to_vector(merged1), std::vector<int>{1, 1, 2, 3, 4, 4});
  test(to_vector(merged2), std::vector<int>{});
  test(to_vector(merged3), std::vector<int>{0});

  free_list(merged1);
  free_list(merged2);
  free_list(merged3);
}