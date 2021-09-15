#include <iostream>
#include <numeric>
#include <vector>

bool canLoadPackages(int k, int P, const std::vector<int> &w) {
  int truckCount = 1;
  int weightTotal = 0;

  for (int i = 0; i < w.size(); i++) {
    if (weightTotal + w[i] <= P) {
      weightTotal += w[i];
    } else if (w[i] <= P) {
      weightTotal = w[i];
      truckCount++;
    } else {
      return false;
    }
  }

  return truckCount <= k;
}

int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> w(n);

  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }

  int left = 0;
  int right = std::accumulate(w.begin(), w.end(), 0);

  while (left < right) {
    int mid = (left + right) / 2;

    if (canLoadPackages(k, mid, w)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  std::cout << right << std::endl;
  return 0;
}