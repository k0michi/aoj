#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

std::vector<double> p;
std::vector<double> q;
std::vector<std::vector<double>> memo;

double minCost(int i, int j) {
  if (j == i - 1) {
    return q[i - 1];
  }

  if (memo[i - 1][j - 1] != 0) {
    return memo[i - 1][j - 1];
  }

  double cost = std::numeric_limits<double>::max();

  for (int k = i; k <= j; k++) {
    cost = std::min(minCost(i, k - 1) + minCost(k + 1, j), cost);
  }

  for (int k = i; k <= j; k++) {
    cost += p[k - 1];
  }

  for (int k = i - 1; k <= j; k++) {
    cost += q[k];
  }

  memo[i - 1][j - 1] = cost;
  return cost;
}

int main() {
  int n;
  std::cin >> n;
  p.resize(n);
  q.resize(n + 1);
  memo.resize(n, std::vector<double>(n));

  for (int i = 0; i < n; i++) {
    double pi;
    std::cin >> pi;
    p[i] = pi;
  }

  for (int i = 0; i < n + 1; i++) {
    double qi;
    std::cin >> qi;
    q[i] = qi;
  }

  std::cout << std::fixed << std::setprecision(4);
  std::cout << minCost(1, n) << std::endl;
  return 0;
}