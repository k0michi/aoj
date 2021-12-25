#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> w(n);
  int minW = std::numeric_limits<int>::max();

  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
    minW = std::min(w[i], minW);
  }

  std::vector<int> wSorted(w.begin(), w.end());
  std::sort(wSorted.begin(), wSorted.end());
  std::map<int, int> dest;

  for (int i = 0; i < n; i++) {
    dest[wSorted[i]] = i;
  }

  std::vector<bool> done(n);
  int totalCost = 0;

  for (int i = 0; i < n; i++) {
    if (done[i]) {
      continue;
    }

    if (w[i] != wSorted[i]) {
      int nSub = 0;
      int totalWSub = 0;
      int minWSub = std::numeric_limits<int>::max();
      int j = i;

      do {
        totalWSub += w[j];
        minWSub = std::min(w[j], minWSub);
        done[j] = true;
        nSub++;
        j = dest[w[j]];
      } while (j != i);

      totalCost += std::min(totalWSub + (nSub - 2) * minWSub,
                            totalWSub + minWSub + (nSub + 1) * minW);
    }
  }

  std::cout << totalCost << std::endl;
  return 0;
}