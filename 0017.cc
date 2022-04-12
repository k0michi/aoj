#include <iostream>
#include <string>

std::string decode(std::string text, int key) {
  for (int i = 0; i < text.size(); i++) {
    if (text[i] != ' ' && text[i] != '.') {
      text[i] = (text[i] - 'a' + key) % 26 + 'a';
    }
  }

  return text;
}

bool isSentence(const std::string &text) {
  return text.find("th") != std::string::npos &&
         (text.find("the") != std::string::npos ||
          text.find("this") != std::string::npos ||
          text.find("that") != std::string::npos);
}

int main() {
  std::string text;
  while (std::getline(std::cin, text), !std::cin.eof()) {
    int key = 1;
    std::string decoded;

    while (decoded = decode(text, key), !isSentence(decoded)) {
      key++;
    }

    std::cout << decoded << std::endl;
  }

  return 0;
}