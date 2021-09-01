#include <iostream>
#include <string>

int main() {
  int n;
  std::cin >> n;

  int scoreTaro = 0, scoreHanako = 0;

  for (int i = 0; i < n; i++) {
    std::string cardTaro, cardHanako;
    std::cin >> cardTaro >> cardHanako;

    if (cardTaro == cardHanako) {
      scoreTaro++;
      scoreHanako++;
    } else if (cardTaro > cardHanako) {
      scoreTaro += 3;
    } else {
      scoreHanako += 3;
    }
  }

  std::cout << scoreTaro << ' ' << scoreHanako << std::endl;
  return 0;
}