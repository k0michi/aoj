#include <iomanip>
#include <iostream>

constexpr double PI = 3.141592653589793;

int main() {
  double r;
  std::cin >> r;

  double area = PI * r * r;
  double circ = 2 * PI * r;

  std::cout << std::fixed << std::setprecision(5);
  std::cout << area << ' ' << circ << std::endl;
  return 0;
}