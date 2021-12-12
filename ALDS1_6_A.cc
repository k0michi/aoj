#include <algorithm>
#include <iostream>
#include <vector>

void countingSort(const std::vector<int> &A, std::vector<int> &B) {
  int n = A.size();
  int k = *std::max_element(A.begin(), A.end());
  std::vector<int> C(k + 1);

  for (int i = 0; i < n; i++) {
    C[A[i]]++;
  }

  for (int i = 1; i <= k; i++) {
    C[i] += C[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    B[C[A[i]] - 1] = A[i];
    C[A[i]]--;
  }
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> A(n), B(n);

  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  countingSort(A, B);

  for (int i = 0; i < n; i++) {
    std::cout << B[i];

    if (i < n - 1) {
      std::cout << ' ';
    }
  }

  std::cout << std::endl;
  return 0;
}