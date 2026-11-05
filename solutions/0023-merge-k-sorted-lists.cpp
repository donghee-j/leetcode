// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/

#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
    if (lists.size() == 0) return nullptr;
    if (lists.size() == 1) return lists[0];

    const int n = static_cast<int>(lists.size());
    std::vector<ListNode*> merged_lists;
    for (int i = 0; i < static_cast<int>(lists.size()) / 2; ++i)
      merged_lists.push_back(merge_two_lists(lists[2 * i], lists[2 * i + 1]));
    if (n % 2 == 1) merged_lists.push_back(lists[n - 1]);

    return mergeKLists(merged_lists);
  }

 private:
  ListNode* merge_two_lists(ListNode* list1, ListNode* list2) {
    ListNode dummy;
    ListNode* tail = &dummy;
    ListNode* cur1 = list1;
    ListNode* cur2 = list2;

    while (cur1 != nullptr && cur2 != nullptr) {
      if (cur1->val <= cur2->val) {
        tail->next = cur1;
        cur1 = cur1->next;
      } else {
        tail->next = cur2;
        cur2 = cur2->next;
      }
      tail = tail->next;
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
  ListNode* merged1 = s.mergeKLists(
      {make_list({1, 4, 5}), make_list({1, 3, 4}), make_list({2, 6})});
  ListNode* merged2 = s.mergeKLists({});
  ListNode* merged3 = s.mergeKLists({make_list({})});

  test(to_vector(merged1), {1, 1, 2, 3, 4, 4, 5, 6});
  test(to_vector(merged2), {});
  test(to_vector(merged3), {});

  free_list(merged1);
  free_list(merged2);
  free_list(merged3);
}