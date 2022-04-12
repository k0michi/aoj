#include <iostream>

long factorial(int n) {
  long value = 1;

  for (int i = n; i > 1; i--) {
    value *= i;
  }

  return value;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << factorial(n) << std::endl;
  return 0;
}