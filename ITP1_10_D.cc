#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> x(n), y(n);

  for (int i = 0; i < n; i++) {
    std::cin >> x[i];
  }

  for (int i = 0; i < n; i++) {
    std::cin >> y[i];
  }

  double d1 = 0, d2 = 0, d3 = 0, dI = std::numeric_limits<double>::min();

  for (int i = 0; i < n; i++) {
    d1 += std::abs(x[i] - y[i]);
    d2 += std::pow(std::abs(x[i] - y[i]), 2);
    d3 += std::pow(std::abs(x[i] - y[i]), 3);
    dI = std::max(static_cast<double>(std::abs(x[i] - y[i])), dI);
  }

  d2 = std::sqrt(d2);
  d3 = std::cbrt(d3);

  std::cout << std::fixed << std::setprecision(5);
  std::cout << d1 << std::endl;
  std::cout << d2 << std::endl;
  std::cout << d3 << std::endl;
  std::cout << dI << std::endl;
  return 0;
}