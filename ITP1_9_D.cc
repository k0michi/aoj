#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::string str;
  int q;
  std::cin >> str >> q;

  for (int i = 0; i < q; i++) {
    std::string command;
    int a, b;
    std::cin >> command >> a >> b;

    if (command == "print") {
      std::cout << str.substr(a, b - a + 1) << std::endl;
    } else if (command == "reverse") {
      std::reverse(str.begin() + a, str.begin() + (b + 1));
    } else if (command == "replace") {
      std::string p;
      std::cin >> p;

      str.replace(a, b - a + 1, p);
    }
  }

  return 0;
}