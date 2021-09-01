#include <iostream>
#include <locale>
#include <string>

int main() {
  std::string string;
  std::getline(std::cin, string);

  std::locale locale;

  for (char letter : string) {
    if (std::isalpha(letter, locale)) {
      if (std::islower(letter, locale)) {
        std::cout << std::toupper(letter, locale);
      } else {
        std::cout << std::tolower(letter, locale);
      }
    } else {
      std::cout << letter;
    }
  }

  std::cout << std::endl;
  return 0;
}