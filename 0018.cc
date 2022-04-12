#include <algorithm>
#include <array>
#include <iostream>

int main() {
  std::array<int, 5> numbers;

  for (int i = 0; i < 5; i++) {
    std::cin >> numbers[i];
  }

  std::sort(numbers.begin(), numbers.end(), std::greater<int>());

  for (int i = 0; i < 5; i++) {
    if (i > 0) {
      std::cout << ' ';
    }

    std::cout << numbers[i];
  }

  std::cout << std::endl;
  return 0;
}