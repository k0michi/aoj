#include <iostream>
#include <string>

int main() {
  std::string str;
  std::cin >> str;

  for (int i = 0; i < str.size(); i++) {
    std::cout << str[str.size() - i - 1];
  }

  std::cout << std::endl;
  return 0;
}