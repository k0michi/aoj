#include <algorithm>
#include <iostream>
#include <locale>
#include <string>

int main() {
  std::string W, word;
  std::cin >> W;

  std::locale locale;
  int count = 0;

  while (std::cin >> word, word != "END_OF_TEXT") {
    std::transform(word.begin(), word.end(), word.begin(),
                   [&locale](auto c) { return std::tolower(c, locale); });

    if (word == W) {
      count++;
    }
  }

  std::cout << count << std::endl;
  return 0;
}