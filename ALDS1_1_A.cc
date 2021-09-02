#include <iostream>
#include <vector>

void printSequence(const std::vector<int> &A) {
  for (int j = 0; j < A.size(); j++) {
    std::cout << A[j];

    if (j < A.size() - 1) {
      std::cout << ' ';
    }
  }

  std::cout << std::endl;
}

void insertionSort(std::vector<int> &A) {
  int N = A.size();

  for (int i = 1; i < N; i++) {
    printSequence(A);

    int v = A[i];
    int j = i - 1;

    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }

    A[j + 1] = v;
  }

  printSequence(A);
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> A(n);

  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  insertionSort(A);

  return 0;
}