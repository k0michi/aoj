#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int coins = 0;
  coins += n / 25;
  n %= 25;
  coins += n / 10;
  n %= 10;
  coins += n / 5;
  n %= 5;
  coins += n;

  std::cout << coins << std::endl;
  return 0;
}