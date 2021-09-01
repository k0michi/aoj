#include <iostream>
#include <vector>

int main() {
  int r, c;
  std::cin >> r >> c;

  std::vector<std::vector<int>> table(r + 1, std::vector<int>(c + 1));

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int elem;
      std::cin >> elem;

      table[i][j] = elem;
      table[i][c] += elem;
      table[r][j] += elem;
      table[r][c] += elem;
    }
  }

  for (int i = 0; i < r + 1; i++) {
    for (int j = 0; j < c + 1; j++) {
      std::cout << table[i][j];

      if (j < c) {
        std::cout << ' ';
      }
    }

    std::cout << std::endl;
  }

  return 0;
}