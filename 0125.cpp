// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/

#include <algorithm>
#include <cctype>
#include <iterator>
#include <string>

#include "leetcode.hpp"

class Solution {
 public:
  bool isPalindrome(const std::string& s) {
    int left = 0;
    int right = std::ssize(s) - 1;
    while (left < right) {
      if (!std::isalnum(static_cast<unsigned char>(s[left]))) {
        ++left;
        continue;
      }

      if (!std::isalnum(static_cast<unsigned char>(s[right]))) {
        --right;
        continue;
      }

      if (std::tolower(static_cast<unsigned char>(s[left])) !=
          std::tolower(static_cast<unsigned char>(s[right])))
        return false;

      ++left;
      --right;
    }

    return true;
  }
};

int main() {
  Solution s;
  test(s.isPalindrome("A man, a plan, a canal: Panama"), true);
  test(s.isPalindrome("race a car"), false);
  test(s.isPalindrome(" "), true);
}