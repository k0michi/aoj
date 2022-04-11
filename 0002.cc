#include <iostream>

int main() {
  int a, b;

  while (std::cin >> a >> b, !std::cin.eof()) {
    int digits = 0;
    int c = a + b;

    while (c > 0) {
      digits++;
      c /= 10;
    }

    std::cout << digits << std::endl;
  }

  return 0;
}