#include <cmath>
#include <iostream>

constexpr double PI = 3.141592653589793;

void readLine(int &a, int &b) {
  std::string line;
  std::cin >> line;
  int delimiter = line.find(',');
  a = std::stoi(line.substr(0, delimiter));
  b = std::stoi(line.substr(delimiter + 1));
}

int main() {
  int angle = 0;
  double x = 0, y = 0;
  int d, a;

  while (readLine(d, a), d != 0 || a != 0) {
    x += d * std::sin(angle * (PI / 180));
    y += d * std::cos(angle * (PI / 180));
    angle += a;
  }

  std::cout << static_cast<int>(x) << std::endl;
  std::cout << static_cast<int>(y) << std::endl;
  return 0;
}