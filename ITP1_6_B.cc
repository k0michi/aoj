#include <array>
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  std::array<std::array<bool, 13>, 4> cards = {};

  for (int i = 0; i < n; i++) {
    char suit;
    int rank;
    std::cin >> suit >> rank;

    if (suit == 'S') {
      cards[0][rank - 1] = true;
    } else if (suit == 'H') {
      cards[1][rank - 1] = true;
    } else if (suit == 'C') {
      cards[2][rank - 1] = true;
    } else if (suit == 'D') {
      cards[3][rank - 1] = true;
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      if (!cards[i][j]) {
        char suit;
        int rank = j + 1;

        if (i == 0) {
          suit = 'S';
        } else if (i == 1) {
          suit = 'H';
        } else if (i == 2) {
          suit = 'C';
        } else if (i == 3) {
          suit = 'D';
        }

        std::cout << suit << ' ' << rank << std::endl;
      }
    }
  }

  return 0;
}