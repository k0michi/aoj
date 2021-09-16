#include <iostream>
#include <vector>

std::vector<int> A;
int n;

bool solve(int i, int m) {
  if (m == 0) {
    return true;
  }

  if (i >= n) {
    return false;
  }

  return solve(i + 1, m) || solve(i + 1, m - A[i]);
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