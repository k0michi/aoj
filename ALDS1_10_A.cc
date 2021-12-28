#include <iostream>
#include <vector>

std::vector<int> memo(45);

int fib(int n) {
  if (memo[n] != 0) {
    return memo[n];
  }

  int r;

  if (n == 0 || n == 1) {
    r = 1;
  } else {
    r = fib(n - 1) + fib(n - 2);
  }

  memo[n] = r;
  return r;
}

int main() {
  int n;
  std::cin >> n;

  std::cout << fib(n) << std::endl;
  return 0;
}