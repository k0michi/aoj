#include <iostream>
#include <locale>
#include <string>

std::locale locale;

int main() {
  std::string text;
  std::getline(std::cin, text);

  for (int i = 0; i < text.size(); i++) {
    std::cout << std::toupper(text[i], locale);
  }

  std::cout << std::endl;
  return 0;
}