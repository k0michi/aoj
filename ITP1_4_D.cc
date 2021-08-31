#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int min = 1000000;
  int max = -1000000;
  long sum = 0;

  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;

    min = std::min(a, min);
    max = std::max(a, max);
    sum += a;
  }

  std::cout << min << ' ' << max << ' ' << sum << std::endl;
  return 0;
}