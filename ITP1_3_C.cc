#include <iostream>
#include <utility>

int main() {
  int x, y;

  while (std::cin >> x >> y, x != 0 || y != 0) {
    if (x > y) {
      std::swap(x, y);
    }

    std::cout << x << ' ' << y << std::endl;
  }

  return 0;
}