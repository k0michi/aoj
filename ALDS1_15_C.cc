#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::tuple<int, int>> activities(n);

  for (int i = 0; i < n; i++) {
    int s, t;
    std::cin >> s >> t;
    activities[i] = std::make_tuple(s, t);
  }

  std::sort(activities.begin(), activities.end(),
            [](const std::tuple<int, int> &a, const std::tuple<int, int> &b) {
              return std::get<1>(a) < std::get<1>(b);
            });

  int answer = 0;
  int time = -1;

  for (int i = 0; i < n; i++) {
    int s, t;
    std::tie(s, t) = activities[i];

    if (time < s) {
      answer++;
      time = t;
    }
  }

  std::cout << answer << std::endl;
  return 0;
}