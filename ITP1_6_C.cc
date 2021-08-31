#include <array>
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  std::array<std::array<std::array<int, 10>, 3>, 4> tenants = {};

  for (int i = 0; i < n; i++) {
    int b, f, r, v;
    std::cin >> b >> f >> r >> v;

    tenants[b - 1][f - 1][r - 1] += v;
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 10; k++) {
        std::cout << ' ' << tenants[i][j][k];
      }

      std::cout << std::endl;
    }

    if (i < 3) {
      std::cout << "####################" << std::endl;
    }
  }

  return 0;
}