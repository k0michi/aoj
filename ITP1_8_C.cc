#include <iostream>
#include <locale>
#include <vector>

int main() {
  char letter;

  std::locale locale;
  std::vector<int> counts(26);

  while (std::cin >> letter, !std::cin.eof()) {
    if (std::isalpha(letter, locale)) {
      if (std::isupper(letter, locale)) {
        letter = std::tolower(letter, locale);
      }

      counts[static_cast<int>(letter) - 97]++;
    }
  }

  for (int i = 0; i < 26; i++) {
    std::cout << static_cast<char>(i + 97) << " : " << counts[i] << std::endl;
  }

  return 0;
}