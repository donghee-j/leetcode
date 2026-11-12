# LeetCode Solutions

LeetCode solutions in C++20. Each solution file compiles and runs on its own, and most include test cases in `main()`.

## Structure

```text
.
├── include/
│   └── leetcode.hpp    # Shared data structures and test helpers
└── solutions/          # One file per problem
```

## Usage

```bash
clang++ -std=c++20 -Iinclude solutions/0001-two-sum.cpp && ./a.out
```

`test()` prints each result in this format:

```text
[PASS] expected 3, got 3
```

## Helpers

Provided by `include/leetcode.hpp`.

| Name                                 | Description                                                                                   |
| ------------------------------------ | --------------------------------------------------------------------------------------------- |
| `test(got, expected)`                | Compares two values and prints `PASS` or `FAIL`                                               |
| `sorted(v)`                          | Returns a sorted copy of a vector, including inner vectors, for answers accepted in any order |
| `operator<<`                         | Prints `std::vector` and `std::optional`                                                      |
| `ListNode`, `make_list`, `free_list` | Linked list node, creation, and cleanup                                                       |
| `TreeNode`, `make_tree`, `free_tree` | Binary tree node, creation from level-order values, and cleanup                               |
| `find_node(root, val)`               | Finds the node with value `val` in a tree                                                     |
| `to_vector(head)`, `to_vector(root)` | Converts a linked list or tree to a `std::vector`                                             |

## Solutions

### Hash Map & Array

| #   | Problem                                                                                     | Solution                                               | Tags        |
| --- | ------------------------------------------------------------------------------------------- | ------------------------------------------------------ | ----------- |
| 1   | [Two Sum](https://leetcode.com/problems/two-sum/)                                           | [C++](solutions/0001-two-sum.cpp)                      |             |
| 36  | [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)                                 | [C++](solutions/0036-valid-sudoku.cpp)                 |             |
| 49  | [Group Anagrams](https://leetcode.com/problems/group-anagrams/)                             | [C++](solutions/0049-group-anagrams.cpp)               |             |
| 128 | [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) | [C++](solutions/0128-longest-consecutive-sequence.cpp) |             |
| 217 | [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)                     | [C++](solutions/0217-contains-duplicate.cpp)           |             |
| 238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | [C++](solutions/0238-product-of-array-except-self.cpp) | prefix sum  |
| 242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram/)                               | [C++](solutions/0242-valid-anagram.cpp)                |             |
| 347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)           | [C++](solutions/0347-top-k-frequent-elements.cpp)      | bucket sort |

### Two Pointers

| #   | Problem                                                                                               | Solution                                                   |
| --- | ----------------------------------------------------------------------------------------------------- | ---------------------------------------------------------- |
| 15  | [3Sum](https://leetcode.com/problems/3sum/)                                                           | [C++](solutions/0015-3sum.cpp)                             |
| 125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)                                   | [C++](solutions/0125-valid-palindrome.cpp)                 |
| 167 | [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | [C++](solutions/0167-two-sum-ii-input-array-is-sorted.cpp) |

### Sliding Window

| #   | Problem                                                                                                                         | Solution                                                                 | Tags  |
| --- | ------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------ | ----- |
| 3   | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [C++](solutions/0003-longest-substring-without-repeating-characters.cpp) |       |
| 76  | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)                                             | [C++](solutions/0076-minimum-window-substring.cpp)                       |       |
| 239 | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)                                                 | [C++](solutions/0239-sliding-window-maximum.cpp)                         |       |
| 424 | [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)               | [C++](solutions/0424-longest-repeating-character-replacement.cpp)        |       |
| 567 | [Permutation in String](https://leetcode.com/problems/permutation-in-string/)                                                   | [C++](solutions/0567-permutation-in-string.cpp)                          | array |

### Stack

| #   | Problem                                                                                             | Solution                                                   |
| --- | --------------------------------------------------------------------------------------------------- | ---------------------------------------------------------- |
| 20  | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)                               | [C++](solutions/0020-valid-parentheses.cpp)                |
| 84  | [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)     | [C++](solutions/0084-largest-rectangle-in-histogram.cpp)   |
| 150 | [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/) | [C++](solutions/0150-evaluate-reverse-polish-notation.cpp) |
| 155 | [Min Stack](https://leetcode.com/problems/min-stack/)                                               | [C++](solutions/0155-min-stack.cpp)                        |
| 739 | [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)                             | [C++](solutions/0739-daily-temperatures.cpp)               |
| 853 | [Car Fleet](https://leetcode.com/problems/car-fleet/)                                               | [C++](solutions/0853-car-fleet.cpp)                        |

### Binary Search

| #   | Problem                                                                                                     | Solution                                                       |
| --- | ----------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------- |
| 33  | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)             | [C++](solutions/0033-search-in-rotated-sorted-array.cpp)       |
| 74  | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)                                     | [C++](solutions/0074-search-a-2d-matrix.cpp)                   |
| 153 | [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | [C++](solutions/0153-find-minimum-in-rotated-sorted-array.cpp) |
| 704 | [Binary Search](https://leetcode.com/problems/binary-search/)                                               | [C++](solutions/0704-binary-search.cpp)                        |
| 875 | [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)                                   | [C++](solutions/0875-koko-eating-bananas.cpp)                  |
| 981 | [Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/)                     | [C++](solutions/0981-time-based-key-value-store.cpp)           |

### Linked List

| #   | Problem                                                                                             | Solution                                                   | Tags               |
| --- | --------------------------------------------------------------------------------------------------- | ---------------------------------------------------------- | ------------------ |
| 19  | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | [C++](solutions/0019-remove-nth-node-from-end-of-list.cpp) |                    |
| 21  | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)                     | [C++](solutions/0021-merge-two-sorted-lists.cpp)           |                    |
| 23  | [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)                         | [C++](solutions/0023-merge-k-sorted-lists.cpp)             | divide and conquer |
| 25  | [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)                 | [C++](solutions/0025-reverse-nodes-in-k-group.cpp)         |                    |
| 138 | [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)       | [C++](solutions/0138-copy-list-with-random-pointer.cpp)    |                    |
| 143 | [Reorder List](https://leetcode.com/problems/reorder-list/)                                         | [C++](solutions/0143-reorder-list.cpp)                     |                    |
| 146 | [LRU Cache](https://leetcode.com/problems/lru-cache/)                                               | [C++](solutions/0146-lru-cache.cpp)                        |                    |
| 206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)                           | [C++](solutions/0206-reverse-linked-list.cpp)              |                    |

### Tree

| #    | Problem                                                                                                                                               | Solution                                                                            | Tags     |
| ---- | ----------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------- | -------- |
| 98   | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)                                                             | [C++](solutions/0098-validate-binary-search-tree.cpp)                               | inorder  |
| 100  | [Same Tree](https://leetcode.com/problems/same-tree/)                                                                                                 | [C++](solutions/0100-same-tree.cpp)                                                 |          |
| 102  | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)                                                 | [C++](solutions/0102-binary-tree-level-order-traversal.cpp)                         | BFS      |
| 104  | [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)                                                           | [C++](solutions/0104-maximum-depth-of-binary-tree.cpp)                              |          |
| 105  | [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | [C++](solutions/0105-construct-binary-tree-from-preorder-and-inorder-traversal.cpp) | preorder |
| 124  | [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)                                                           | [C++](solutions/0124-binary-tree-maximum-path-sum.cpp)                              |          |
| 199  | [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)                                                             | [C++](solutions/0199-binary-tree-right-side-view.cpp)                               | BFS      |
| 226  | [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)                                                                               | [C++](solutions/0226-invert-binary-tree.cpp)                                        |          |
| 230  | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)                                                         | [C++](solutions/0230-kth-smallest-element-in-a-bst.cpp)                             | inorder  |
| 235  | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)                       | [C++](solutions/0235-lowest-common-ancestor-of-a-binary-search-tree.cpp)            | DFS      |
| 297  | [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)                                         | [C++](solutions/0297-serialize-and-deserialize-binary-tree.cpp)                     | BFS, DFS |
| 572  | [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/)                                                                     | [C++](solutions/0572-subtree-of-another-tree.cpp)                                   |          |
| 1448 | [Count Good Nodes in Binary Tree](https://leetcode.com/problems/count-good-nodes-in-binary-tree/)                                                     | [C++](solutions/1448-count-good-nodes-in-binary-tree.cpp)                           |          |

### Heap & Priority Queue

| #    | Problem                                                                                           | Solution                                                  | Tags  |
| ---- | ------------------------------------------------------------------------------------------------- | --------------------------------------------------------- | ----- |
| 355  | [Design Twitter](https://leetcode.com/problems/design-twitter/)                                   | [C++](solutions/0355-design-twitter.cpp)                  |       |
| 621  | [Task Scheduler](https://leetcode.com/problems/task-scheduler/)                                   | [C++](solutions/0621-task-scheduler.cpp)                  | array |
| 709  | [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/) | [C++](solutions/0709-kth-largest-element-in-a-stream.cpp) |       |
| 973  | [K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)           | [C++](solutions/0973-k-closest-points-to-origin.cpp)      |       |
| 1046 | [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)                             | [C++](solutions/1046-last-stone-weight.cpp)               |       |

### Other

| #   | Problem                                                                                           | Solution                                                  | Tags      |
| --- | ------------------------------------------------------------------------------------------------- | --------------------------------------------------------- | --------- |
| 22  | [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)                       | [C++](solutions/0022-generate-parentheses.cpp)            | recursion |
| 121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [C++](solutions/0121-best-time-to-buy-and-sell-stock.cpp) | DP        |
