#include <iostream>
#include <string>
#include <utility>
#include <vector>

struct Card {
  char suit;
  int value;

  bool operator==(const Card &card) const {
    return suit == card.suit && value == card.value;
  }

  std::string toString() { return suit + std::to_string(value); }
};

void bubbleSort(std::vector<Card> &seq) {
  int i = 0;
  bool flag = true;

  while (flag) {
    flag = false;

    for (int j = seq.size() - 1; j >= i + 1; j--) {
      if (seq[j].value < seq[j - 1].value) {
        std::swap(seq[j], seq[j - 1]);
        flag = true;
      }
    }

    i++;
  }
}

void selectionSort(std::vector<Card> &seq) {
  for (int i = 0; i < seq.size(); i++) {
    int minJ = i;

    for (int j = i; j < seq.size(); j++) {
      if (seq[j].value < seq[minJ].value) {
        minJ = j;
      }
    }

    if (i != minJ) {
      std::swap(seq[i], seq[minJ]);
    }
  }
}

int main() {
  int N;
  std::cin >> N;

  std::vector<Card> cards(N);

  for (int i = 0; i < N; i++) {
    std::string card;
    std::cin >> card;

    cards[i].suit = card[0];
    cards[i].value = std::stoi(std::string{card[1]});
  }

  std::vector<Card> cardsBubble = cards;
  bubbleSort(cardsBubble);

  for (int i = 0; i < N; i++) {
    std::cout << cardsBubble[i].toString();

    if (i < N - 1) {
      std::cout << ' ';
    }
  }

  std::cout << std::endl;
  std::cout << "Stable" << std::endl;

  std::vector<Card> cardsSelection = cards;
  selectionSort(cardsSelection);

  for (int i = 0; i < N; i++) {
    std::cout << cardsSelection[i].toString();

    if (i < N - 1) {
      std::cout << ' ';
    }
  }

  std::cout << std::endl;

  if (cardsSelection == cardsBubble) {
    std::cout << "Stable" << std::endl;
  } else {
    std::cout << "Not stable" << std::endl;
  }

  return 0;
}