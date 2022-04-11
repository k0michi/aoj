#include <cmath>
#include <iostream>

bool isPrimeNumber(int x) {
  if (x == 2) {
    return true;
  }

  if (x < 2 || x % 2 == 0) {
    return false;
  }

  int sqrtX = static_cast<int>(std::sqrt(x));

  for (int i = 3; i <= sqrtX; i += 2) {
    if (x % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  int n;

  while (std::cin >> n, !std::cin.eof()) {
    int count = 0;

    for (int i = 2; i <= n; i++) {
      if (isPrimeNumber(i)) {
        count++;
      }
    }

    std::cout << count << std::endl;
  }

  return 0;
}