#include <iostream>
#include <utility>
#include <vector>

int partition(std::vector<int> &A, int p, int r) {
  int x = A[r];
  int i = p;

  for (int j = p; j < r; j++) {
    if (A[j] <= x) {
      std::swap(A[i], A[j]);
      i++;
    }
  }

  std::swap(A[i], A[r]);
  return i;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> A(n);

  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  int pivot = partition(A, 0, A.size() - 1);

  for (int i = 0; i < n; i++) {
    if (i == pivot) {
      std::cout << '[' << A[i] << ']';
    } else {
      std::cout << A[i];
    }

    if (i < n - 1) {
      std::cout << ' ';
    }
  }

  std::cout << std::endl;
  return 0;
}