#include <iostream>

int main() {
  int S;
  std::cin >> S;

  int s = S % 60;
  S /= 60;
  int m = S % 60;
  S /= 60;
  int h = S;

  std::cout << h << ':' << m << ':' << s << std::endl;
  return 0;
}