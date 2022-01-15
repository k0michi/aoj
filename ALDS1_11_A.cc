#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<bool>> matrix(n, std::vector<bool>(n));

  for (int i = 0; i < n; i++) {
    int u, k;
    std::cin >> u >> k;

    for (int j = 0; j < k; j++) {
      int v;
      std::cin >> v;

      matrix[i][v - 1] = true;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << std::noboolalpha << matrix[i][j];

      if (j < n - 1) {
        std::cout << ' ';
      }
    }

    std::cout << std::endl;
  }

  return 0;
}