#include <iostream>
#include <utility>
#include <vector>

struct Card {
  char suit;
  int value;
  int k;
};

int partition(std::vector<Card> &A, int p, int r) {
  int x = A[r].value;
  int i = p;

  for (int j = p; j < r; j++) {
    if (A[j].value <= x) {
      std::swap(A[i], A[j]);
      i++;
    }
  }

  std::swap(A[i], A[r]);
  return i;
}

void quickSort(std::vector<Card> &A, int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<Card> A(n);

  for (int i = 0; i < n; i++) {
    std::cin >> A[i].suit >> A[i].value;
    A[i].k = i;
  }

  quickSort(A, 0, A.size() - 1);
  bool stable = true;

  for (int i = 0; i < n - 1; i++) {
    if (A[i].value == A[i + 1].value && A[i].k > A[i + 1].k) {
      stable = false;
      break;
    }
  }

  if (stable) {
    std::cout << "Stable" << std::endl;
  } else {
    std::cout << "Not stable" << std::endl;
  }

  for (int i = 0; i < n; i++) {
    std::cout << A[i].suit << ' ' << A[i].value << std::endl;
  }

  return 0;
}