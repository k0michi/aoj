#include <iomanip>
#include <iostream>

int main() {
  double a, b, c, d, e, f;

  while (std::cin >> a >> b >> c >> d >> e >> f, !std::cin.eof()) {
    double x = (c * e - b * f) / (a * e - b * d);
    double y = (a * f - c * d) / (a * e - b * d);

    // Magic
    if (x == 0) {
      x = 0;
    }

    if (y == 0) {
      y = 0;
    }

    std::cout << std::fixed << std::setprecision(3);
    std::cout << x << ' ' << y << std::endl;
  }

  return 0;
}