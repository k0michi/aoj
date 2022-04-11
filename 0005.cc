#include <iostream>

long gcd(long m, long n) {
  if (n == 0) {
    return m;
  } else {
    return gcd(n, m % n);
  }
}

long lcm(long m, long n) { return m * n / gcd(m, n); }

int main() {
  int a, b;

  while (std::cin >> a >> b, !std::cin.eof()) {
    std::cout << gcd(a, b) << ' ' << lcm(a, b) << std::endl;
  }

  return 0;
}