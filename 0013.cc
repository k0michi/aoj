#include <iostream>
#include <stack>

int main() {
  int n;
  std::stack<int> cars;

  while (std::cin >> n, !std::cin.eof()) {
    if (n == 0) {
      std::cout << cars.top() << std::endl;
      cars.pop();
    } else {
      cars.push(n);
    }
  }

  return 0;
}