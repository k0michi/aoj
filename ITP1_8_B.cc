#include <iostream>
#include <string>

int main() {
  std::string x;

  while (std::getline(std::cin, x), x != "0") {
    int sum = 0;

    for (char digit : x) {
      sum += std::stoi(std::string{digit});
    }

    std::cout << sum << std::endl;
  }

  return 0;
}