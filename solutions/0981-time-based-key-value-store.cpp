// 981. Time Based Key-Value Store
// https://leetcode.com/problems/time-based-key-value-store/

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "leetcode.hpp"

class TimeMap {
 public:
  TimeMap() = default;

  void set(const std::string& key, const std::string& value, int timestamp) {
    data_[key].push_back({timestamp, value});
  }

  std::string get(const std::string& key, int timestamp) const {
    const auto it = data_.find(key);
    if (it == data_.end()) return "";

    const auto& values = it->second;
    int left = 0;
    int right = static_cast<int>(values.size()) - 1;
    int best = -1;
    while (left <= right) {
      const int mid = left + (right - left) / 2;

      if (values[mid].first <= timestamp) {
        best = mid;
        left = mid + 1;
      } else
        right = mid - 1;
    }

    return best >= 0 ? values[best].second : "";
  }

 private:
  std::unordered_map<std::string, std::vector<std::pair<int, std::string>>>
      data_;  // key, {timestamp, value}
};

int main() {
  TimeMap obj;
  obj.set("foo", "bar", 1);
  std::cout << obj.get("foo", 1) << "\n";  // return "bar"
  std::cout << obj.get("foo", 3) << "\n";  // return "bar"
  obj.set("foo", "bar2", 4);
  std::cout << obj.get("foo", 4) << "\n";  // return "bar2"
  std::cout << obj.get("foo", 5) << "\n";  // return "bar2"
}