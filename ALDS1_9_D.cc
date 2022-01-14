#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int parent(int i) { return i / 2; }

void reverseHeapify(std::vector<int> &A, int i) {
  int p = parent(i);

  if (p >= 1) {
    std::swap(A[i - 1], A[p - 1]);
    reverseHeapify(A, p);
  }
}

int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(N);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  std::sort(A.begin(), A.end());

  for (int i = 1; i < N; i++) {
    reverseHeapify(A, i);
    std::swap(A[0], A[i]);
  }

  for (int i = 0; i < N; i++) {
    std::cout << A[i];

    if (i < N - 1) {
      std::cout << ' ';
    }
  }

  std::cout << std::endl;
  return 0;
}