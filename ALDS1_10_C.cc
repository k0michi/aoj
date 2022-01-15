#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int lcs(const std::string &X, const std::string &Y) {
  int m = X.length();
  int n = Y.length();
  std::vector<std::vector<int>> lengthTable(m + 1, std::vector<int>(n + 1));

  for (int x = 0; x <= m; x++) {
    lengthTable[x][0] = 0;
  }

  for (int y = 1; y <= n; y++) {
    lengthTable[0][y] = 0;
  }

  for (int x = 1; x <= m; x++) {
    for (int y = 1; y <= n; y++) {
      if (Y[y - 1] == X[x - 1]) {
        lengthTable[x][y] = lengthTable[x - 1][y - 1] + 1;
      } else {
        lengthTable[x][y] =
            std::max(lengthTable[x - 1][y], lengthTable[x][y - 1]);
      }
    }
  }

  return lengthTable[m][n];
}

int main() {
  int q;
  std::cin >> q;

  for (int i = 0; i < q; i++) {
    std::string X, Y;
    std::cin >> X >> Y;
    std::cout << lcs(X, Y) << std::endl;
  }

  return 0;
}