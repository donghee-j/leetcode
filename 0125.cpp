// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/

#include <algorithm>
#include <cctype>
#include <iterator>
#include <string>

#include "include/leetcode.hpp"

class Solution {
 public:
  bool isPalindrome(const std::string& s) {
    std::string preprocessed = s;
    std::erase_if(preprocessed,
                  [](unsigned char c) { return !std::isalnum(c); });
    std::ranges::transform(preprocessed, preprocessed.begin(),
                           [](unsigned char c) { return std::tolower(c); });

    int left = 0;
    int right = std::ssize(preprocessed) - 1;
    while (left < right) {
      if (preprocessed[left] != preprocessed[right]) return false;

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