#include <iostream>

int main() {
  int a, b;
  char op;

  while (std::cin >> a >> op >> b, op != '?') {
    int value;

    if (op == '+') {
      value = a + b;
    } else if (op == '-') {
      value = a - b;
    } else if (op == '*') {
      value = a * b;
    } else if (op == '/') {
      value = a / b;
    }

    std::cout << value << std::endl;
  }

  return 0;
}