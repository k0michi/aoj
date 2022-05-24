#include <iostream>

int solve(int n, int count) {
  if (n == 0) {
    return 1;
  }

  if (n < 0 || n > count * 9) {
    return 0;
  }

  int combinations = 0;

  for (int i = 0; i <= 9; i++) {
    combinations += solve(n - i, count - 1);
  }

  return combinations;
}

int main() {
  int n;

  while (std::cin >> n, !std::cin.eof()) {
    std::cout << solve(n, 4) << std::endl;
  }

  return 0;
}