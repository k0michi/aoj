#include <cmath>
#include <iostream>
#include <vector>

int count = 0;

void insertionSort(std::vector<int> &A, int g) {
  int n = A.size();

  for (int i = g; i < n; i++) {
    int v = A[i];
    int j = i - g;

    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j = j - g;
      count++;
    }

    A[j + g] = v;
  }
}

void shellSort(std::vector<int> &A) {
  int n = A.size();
  count = 0;
  int h = 1;

  while (h < std::ceil(n / 3.)) {
    h = h * 3 + 1;
  }

  std::vector<int> G;

  while (h > 0) {
    G.push_back(h);
    h /= 3;
  }

  int m = G.size();
  std::cout << m << std::endl;

  for (int i = 0; i < m; i++) {
    insertionSort(A, G[i]);
    std::cout << G[i];

    if (i < m - 1) {
      std::cout << ' ';
    }
  }

  std::cout << std::endl;
  std::cout << count << std::endl;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> A(n);

  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  shellSort(A);

  for (int i = 0; i < n; i++) {
    std::cout << A[i] << std::endl;
  }

  return 0;
}