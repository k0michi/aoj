#include <iostream>
#include <vector>

std::vector<int> A;
int n;

bool solve(int i, int m) {
  std::vector<std::vector<bool>> memo(n, std::vector<bool>(m + 1));
  memo[0][0] = true;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      memo[i][j] = false;
    }

    for (int j = 0; j <= m; j++) {
      if (i == 0) {
        if (j == A[i]) {
          memo[i][j] = true;
        }
      } else {
        if (memo[i - 1][j]) {
          memo[i][j] = true;
        }

        if (j >= A[i]) {
          if (memo[i - 1][j - A[i]]) {
            memo[i][j] = true;
          }
        }
      }
    }
  }

  return memo[n - 1][m];
}

int main() {
  std::cin >> n;
  A.resize(n);

  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  int q;
  std::cin >> q;

  for (int i = 0; i < q; i++) {
    int m;
    std::cin >> m;

    std::cout << (solve(0, m) ? "yes" : "no") << std::endl;
  }

  return 0;
}