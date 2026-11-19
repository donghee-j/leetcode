// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/

#include <string>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  std::vector<std::vector<std::string>> partition(const std::string& s) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> cur;
    cur.reserve(s.size());

    backtrack(s, 0, cur, result);

    return result;
  }

 private:
  static void backtrack(const std::string& s, int start,
                        std::vector<std::string>& cur,
                        std::vector<std::vector<std::string>>& result) {
    if (start == std::ssize(s)) {
      result.push_back(cur);
      return;
    }

    for (int i = start; i < std::ssize(s); ++i) {
      if (is_palindrome(s, start, i)) {
        cur.push_back(s.substr(start, i - start + 1));
        backtrack(s, i + 1, cur, result);
        cur.pop_back();
      }
    }
  }

  static bool is_palindrome(const std::string& s, int lo, int hi) {
    while (lo < hi) {
      if (s[lo] != s[hi]) return false;
      ++lo;
      --hi;
    }
    return true;
  }
};

int main() {
  Solution s;
  test(sorted_outer(s.partition("aab")), {{"aa", "b"}, {"a", "a", "b"}});
  test(s.partition("a"), {{"a"}});
}