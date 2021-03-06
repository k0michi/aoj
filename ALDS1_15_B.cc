#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <tuple>

int main() {
  int N, W;
  std::cin >> N >> W;
  std::priority_queue<std::tuple<double, int, int>> items;

  for (int i = 0; i < N; i++) {
    int vi, wi;
    std::cin >> vi >> wi;
    items.push({static_cast<double>(vi) / wi, vi, wi});
  }

  double value = 0;
  int weight = 0;

  while (weight <= W && items.size() > 0) {
    auto item = items.top();
    items.pop();

    int weightToPut = std::min(std::get<2>(item), W - weight);
    value += std::get<0>(item) * weightToPut;
    weight += weightToPut;
  }

  std::cout << std::fixed << std::setprecision(6);
  std::cout << value << std::endl;
  return 0;
}