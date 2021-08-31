#include <iostream>

int main() {
  int H, W;

  while (std::cin >> H >> W, H != 0 || W != 0) {
    for (int y = 0; y < H; y++) {
      for (int x = 0; x < W; x++) {
        if ((x + y) % 2 == 0) {
          std::cout << '#';
        } else {
          std::cout << '.';
        }
      }

      std::cout << std::endl;
    }

    std::cout << std::endl;
  }

  return 0;
}