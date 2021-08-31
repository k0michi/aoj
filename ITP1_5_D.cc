#include <iostream>

void call(int n);

int main() {
  int n;
  std::cin >> n;

  call(n);

  return 0;
}

void call(int n) {
  for (int i = 1; i <= n; i++) {
    if (i % 3 == 0) {
      std::cout << ' ' << i;
      continue;
    }

    int x = i;

    while (x > 0) {
      if (x % 10 == 3) {
        std::cout << ' ' << i;
        break;
      }

      x /= 10;
    }
  }

  std::cout << std::endl;
}