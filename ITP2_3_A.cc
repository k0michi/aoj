#include <algorithm>
#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  auto result = std::minmax({a, b, c});
  std::cout << result.first << ' ' << result.second << std::endl;
  return 0;
}