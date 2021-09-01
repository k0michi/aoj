#include <cmath>
#include <iomanip>
#include <iostream>

constexpr double PI = 3.141592653589793;

double toRad(double deg);

int main() {
  int a, b, C;
  std::cin >> a >> b >> C;

  double h = b * std::sin(toRad(C));
  double S = a * h / 2;
  double c = std::sqrt(a * a + b * b - 2 * a * b * std::cos(toRad(C)));
  double L = a + b + c;

  std::cout << std::fixed << std::setprecision(4);
  std::cout << S << std::endl;
  std::cout << L << std::endl;
  std::cout << h << std::endl;
  return 0;
}

double toRad(double deg) { return deg * PI / 180; }