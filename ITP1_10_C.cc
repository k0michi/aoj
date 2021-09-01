#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n;

  while (std::cin >> n, n != 0) {
    std::vector<int> s(n);

    for (int i = 0; i < n; i++) {
      std::cin >> s[i];
    }

    double m = std::accumulate(s.begin(), s.end(), 0) / static_cast<double>(n);
    double a = 0;

    for (int i = 0; i < n; i++) {
      a += std::pow(s[i] - m, 2);
    }

    a = std::sqrt(a / n);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << a << std::endl;
  }

  return 0;
}