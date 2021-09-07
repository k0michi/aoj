#include <iostream>
#include <utility>
#include <vector>

int selectionSort(std::vector<int> &seq) {
  int opCount = 0;

  for (int i = 0; i < seq.size(); i++) {
    int minJ = i;

    for (int j = i; j < seq.size(); j++) {
      if (seq[j] < seq[minJ]) {
        minJ = j;
      }
    }

    if (i != minJ) {
      std::swap(seq[i], seq[minJ]);
      opCount++;
    }
  }

  return opCount;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> A(n);

  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  int opCount = selectionSort(A);

  for (int i = 0; i < n; i++) {
    std::cout << A[i];

    if (i < n - 1) {
      std::cout << ' ';
    }
  }

  std::cout << std::endl;
  std::cout << opCount << std::endl;
  return 0;
}