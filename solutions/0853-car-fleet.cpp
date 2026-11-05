// 853. Car Fleet
// https://leetcode.com/problems/car-fleet/

#include <algorithm>
#include <utility>
#include <vector>

#include "leetcode.hpp"

class Solution {
 public:
  int carFleet(int target, const std::vector<int>& position,
               const std::vector<int>& speed) {
    const int n = static_cast<int>(position.size());
    std::vector<std::pair<int, double>> cars;  // <position, arrival>
    cars.reserve(n);
    for (int i = 0; i < n; ++i) {
      cars.push_back({position[i],
                      (static_cast<double>(target) - position[i]) / speed[i]});
    }

    auto by_position_desc = [](const auto& a, const auto& b) {
      return a.first > b.first;
    };
    std::ranges::sort(cars, by_position_desc);

    int fleets = 0;
    double front_arrival = -1.0;
    for (const auto& car : cars) {
      if (car.second > front_arrival) {
        ++fleets;
        front_arrival = car.second;
      }
    }

    return fleets;
  }
};

int main() {
  Solution s;
  test(s.carFleet(12, {10, 8, 0, 5, 3}, {2, 4, 1, 1, 3}), 3);
  test(s.carFleet(10, {3}, {3}), 1);
  test(s.carFleet(100, {0, 2, 4}, {4, 2, 1}), 1);
}