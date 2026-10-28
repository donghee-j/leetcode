// 981. Time Based Key-Value Store
// https://leetcode.com/problems/time-based-key-value-store/
// Worst O(n)

#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "leetcode.hpp"

class TimeMap {
 public:
  TimeMap() = default;

  void set(const std::string& key, const std::string& value, int timestamp) {
    data_.push_back({key, value, timestamp});
  }

  std::string get(const std::string& key, int timestamp) const {
    int left = 0;
    int right = static_cast<int>(data_.size());
    int bound = right - 1;

    while (left < right) {
      const int mid = left + (right - left) / 2;
      const Pair& pair = data_[mid];

      if (pair.timestamp <= timestamp) {
        bound = mid;
        left = mid + 1;
      } else
        right = mid;
    }

    for (int i = bound; i >= 0; --i) {
      if (data_[i].key == key) return data_[i].value;
    }

    return "";
  }

 private:
  struct Pair {
    std::string key;
    std::string value;
    int timestamp;
  };
  std::vector<Pair> data_;
};

int main() {
  TimeMap* obj = new TimeMap();
  obj->set("foo", "bar", 1);
  std::cout << obj->get("foo", 1) << "\n";  // return "bar"
  std::cout << obj->get("foo", 3) << "\n";  // return "bar"
  obj->set("foo", "bar2", 4);
  std::cout << obj->get("foo", 4) << "\n";  // return "bar2"
  std::cout << obj->get("foo", 5) << "\n";  // return "bar2"
}