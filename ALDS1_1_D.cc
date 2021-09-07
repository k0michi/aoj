#include <algorithm>
#include <iostream>
#include <limits>

int main() {
  int n, R;
  std::cin >> n;
  std::cin >> R;

  int minR = R;
  int maxProfit = std::numeric_limits<int>::min();

  for (int i = 1; i < n; i++) {
    std::cin >> R;

    maxProfit = std::max(maxProfit, R - minR);
    minR = std::min(minR, R);
  }

  std::cout << maxProfit << std::endl;
  return 0;
}