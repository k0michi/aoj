#include <iostream>
#include <string>

int main() {
  std::string deck;

  while (std::cin >> deck, deck != "-") {
    int m;
    std::cin >> m;

    for (int i = 0; i < m; i++) {
      int h;
      std::cin >> h;

      deck = deck.substr(h) + deck.substr(0, h);
    }

    std::cout << deck << std::endl;
  }

  return 0;
}