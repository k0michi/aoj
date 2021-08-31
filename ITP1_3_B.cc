#include <iostream>

int main() {
  int i = 1, x;

  while (std::cin >> x, x != 0) {
    std::cout << "Case " << i << ": " << x << std::endl;
    i++;
  }

  return 0;
}