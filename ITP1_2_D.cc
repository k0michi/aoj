#include <iostream>

int main() {
  int W, H, x, y, r;
  std::cin >> W >> H >> x >> y >> r;
  bool inside = false;

  if (x >= r && x <= W - r && y >= r && y <= H - r) {
    inside = true;
  }

  if (inside) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}