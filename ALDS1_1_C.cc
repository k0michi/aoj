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
  std::cin >> n;

  int count = 0;

  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;

    if (isPrimeNumber(x)) {
      count++;
    }
  }

  std::cout << count << std::endl;
  return 0;
}