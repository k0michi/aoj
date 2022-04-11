#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> hills(10);

  for (int i = 0; i < 10; i++) {
    std::cin >> hills[i];
  }

  std::sort(hills.begin(), hills.end(), std::greater<int>());

  std::cout << hills[0] << std::endl;
  std::cout << hills[1] << std::endl;
  std::cout << hills[2] << std::endl;
  return 0;
}