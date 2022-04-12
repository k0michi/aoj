#include <iostream>
#include <limits>
#include <vector>

int main() {
  int n;

  while (std::cin >> n, n != 0) {
    std::vector<int> sumFrom(n);
    int sumMax = std::numeric_limits<int>::min();

    for (int i = 0; i < n; i++) {
      int a;
      std::cin >> a;

      for (int j = 0; j <= i; j++) {
        sumFrom[j] += a;

        if (sumFrom[j] > sumMax) {
          sumMax = sumFrom[j];
        }
      }
    }

    std::cout << sumMax << std::endl;
  }

  return 0;
}