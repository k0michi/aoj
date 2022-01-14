#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

struct Matrix {
  int rows;
  int columns;
};

std::vector<std::vector<int>> costTable;

void putCost(int first, int last, int cost) { costTable[first][last] = cost; }

int getCost(int first, int last) { return costTable[first][last]; }

int main() {
  int n;
  std::cin >> n;
  std::vector<Matrix> matrices(n);

  for (int i = 0; i < n; i++) {
    int r, c;
    std::cin >> r >> c;
    matrices[i].rows = r;
    matrices[i].columns = c;
  }

  costTable.resize(n, std::vector<int>(n));

  for (int i = 0; i < n; i++) {
    putCost(i, i, 0);
  }

  for (int num = 2; num <= n; num++) {
    for (int first = 0; first <= n - num; first++) {
      int last = first + num - 1;
      int costMin = std::numeric_limits<int>::max();

      for (int mid = first; mid < last; mid++) {
        int cost = getCost(first, mid) + getCost(mid + 1, last);
        cost += matrices[first].rows * matrices[mid].columns *
                matrices[last].columns;
        costMin = std::min(cost, costMin);
      }

      putCost(first, last, costMin);
    }
  }

  std::cout << getCost(0, n - 1) << std::endl;
  return 0;
}