#include <iostream>

int main() {
  int d;

  while (std::cin >> d, !std::cin.eof()) {
    int s = 0;

    for (int i = 0; i < 600 / d; i++) {
      int x = i * d;
      s += x * x * d;
    }

    std::cout << s << std::endl;
  }

  return 0;
}